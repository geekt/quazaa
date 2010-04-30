#include "network.h"

#include "Thread.h"
#include "webcache.h"
#include "hostcache.h"
#include "g2packet.h"
#include "datagrams.h"
#include <QTimer>
#include <QList>
#include "g2node.h"
#include "NetworkConnection.h"
#include "Handshakes.h"

#include "queryhashtable.h"
#include "SearchManager.h"
#include "ManagedSearch.h"
#include "Query.h"

CNetwork Network;
CThread NetworkThread;

CNetwork::CNetwork(QObject *parent)
    :QObject(parent)
{
    m_pSecondTimer = 0;
    //m_oAddress.port = 6346;
    m_oAddress.port = 1095;

    m_nHubsConnected = 0;
    m_nLeavesConnected = 0;
    m_bNeedUpdateLNI = true;
    m_nLNIWait = 60;
    m_nKHLWait = 60;
    m_tCleanRoutesNext = 60;

    m_pHashTable = new QueryHashTable();

    // dla testu
    m_pHashTable->AddWord("urn:guid:xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    m_pHashTable->AddWord("guid:xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
}
CNetwork::~CNetwork()
{
    if( m_bActive )
    {
        Disconnect();
    }

    if( m_pHashTable )
    {
        delete m_pHashTable;
        m_pHashTable = 0;
    }
}

void CNetwork::Connect()
{
    QMutexLocker l(&m_pSection);

    qDebug() << "connect " << QThread::currentThreadId();

    if( m_bActive )
    {
        qDebug() << "Network already started";
        return;
    }

    m_nNodeState = G2_LEAF;
    //m_nNodeState = G2_HUB;
    m_bActive = true;

    Datagrams.moveToThread(&NetworkThread);
    Handshakes.moveToThread(&NetworkThread);
    SearchManager.moveToThread(&NetworkThread);
    m_oRoutingTable.Clear();
    NetworkThread.start(&m_pSection, this);

    /*if( !isRunning() )
    {
        //m_nNodeState = G2_LEAF;
        m_nNodeState = G2_HUB;
        m_bActive = true;

        //Handshakes.Listen();
        Datagrams.Listen();
        start();
    }*/

}
void CNetwork::Disconnect()
{
    QMutexLocker l(&m_pSection);

    qDebug() << "CNetwork::Disconnect() ThreadID:" << QThread::currentThreadId();

    if( m_bActive )
    {
        m_bActive = false;
        NetworkThread.exit(0);
    }

    /*if( isRunning() )
    {
        m_bActive = false;
        Handshakes.Disconnect();
        emit changeThreadSignal(qApp->thread());
        quit();
        l.unlock();
    }

    wait();*/
}
void CNetwork::SetupThread()
{
    qWarning("In Network Thread");
    qDebug() << QThread::currentThreadId();

    Q_ASSERT(m_pSecondTimer == 0 && m_pRateController == 0);

    m_pSecondTimer = new QTimer();
    connect(m_pSecondTimer, SIGNAL(timeout()), this, SLOT(OnSecondTimer()));
    m_pSecondTimer->start(1000);

    // Powiedzmy ze mamy lacze 2Mbit/s / 128kbit/s
    quint32 nUploadCapacity = 1024 * 1024 * 8;
    quint32 nDownloadCapacity = 16384 * 1024 * 8;

    // Dla polaczen TCP w sieci 1/4 dostepnego pasma
    m_pRateController = new CRateController();
    m_pRateController->setObjectName("CNetwork rate controller");
    m_pRateController->SetDownloadLimit(nDownloadCapacity / 4);
    //m_pRateController->setDownloadLimit(2048);
    m_pRateController->SetUploadLimit(nUploadCapacity / 4);

    Datagrams.Listen();
    Handshakes.Listen();
}
void CNetwork::CleanupThread()
{
    qWarning("Stopping Network Thread");
    qDebug() << "Network ThreadID: " << QThread::currentThreadId();

    m_pSecondTimer->stop();
    delete m_pSecondTimer;
    m_pSecondTimer = 0;
    WebCache.CancelRequests();

    //Datagrams.Disconnect();

    delete m_pRateController;
    m_pRateController = 0;

    Datagrams.Disconnect();
    Handshakes.Disconnect();

    moveToThread(qApp->thread());
    DisconnectAllNodes();
}

void CNetwork::RemoveNode(CG2Node* pNode)
{
    //qDebug() << "Remove node" << pNode;

    //QMutexLocker l(&m_pSection);

    if( pNode->m_nType == G2_HUB )
        m_nHubsConnected--;
    else if( pNode->m_nType == G2_LEAF )
        m_nLeavesConnected--;

    m_pRateController->RemoveSocket(pNode);

    emit NodeRemoved(pNode);
    m_lNodes.removeOne(pNode);
    m_oRoutingTable.Remove(pNode);

    //qDebug() << "List size: " << m_lNodes.size();

}

void CNetwork::OnSecondTimer()
{

    if( !m_pSection.tryLock(250) )
    {
        qWarning() << "WARNING: Network core overloaded!";
        return;
    }
    //m_pSection.lock();

    if( !m_bActive )
    {
        /*if( m_lNodes.isEmpty() )
        {
            //quit();
        }
        else
        {
            DisconnectAllNodes();
        }*/
        m_pSection.unlock();
        return;
    }

    if( HostCache.isEmpty() && !WebCache.isRequesting() )
    {
        WebCache.RequestRandom();
    }

    if( m_tCleanRoutesNext > 0 )
        m_tCleanRoutesNext--;
    else
    {
        m_oRoutingTable.Dump();
        m_oRoutingTable.ExpireOldRoutes();
        m_tCleanRoutesNext = 60;
    }

    Datagrams.FlushSendCache();
    Handshakes.OnTimer();

    Maintain();

    SearchManager.OnTimer();

    if( m_nLNIWait == 0 )
    {
        if( m_bNeedUpdateLNI )
        {
            m_nLNIWait = 60;
            m_bNeedUpdateLNI = false;

            foreach( CG2Node* pNode, m_lNodes )
            {
                if( pNode->m_nState == nsConnected )
                    pNode->SendLNI();
            }
        }
    }
    else
        m_nLNIWait--;

    if( m_nKHLWait == 0 )
    {
        HostCache.Save();
        DispatchKHL();
        m_nKHLWait = 60;
    }
    else
        m_nKHLWait--;


    m_pSection.unlock();
}

void CNetwork::DisconnectAllNodes()
{
    QListIterator<CG2Node*> it(m_lNodes);
    CG2Node* pNode = 0;
    while( it.hasNext() )
    {
        pNode = it.next();
        pNode->abort();
        pNode->deleteLater();
    }
}
bool CNetwork::NeedMore(G2NodeType nType)
{
    if( nType == G2_HUB ) // potrzeba hubow?
    {
        if( m_nNodeState == G2_HUB ) // jesli hub
            return ( m_nHubsConnected < HubToHub );
        else    // jesli leaf
            return ( m_nLeavesConnected < LeafToHub );
    }
    else // potrzeba leaf?
    {
        if( m_nNodeState == G2_HUB )    // jesli hub
            return ( m_nLeavesConnected < HubToLeaf );
    }

    return false;
}

void CNetwork::Maintain()
{

    //qDebug() << "CNetwork::Maintain";
    CG2Node* pNode = 0;

    quint32 tNow = time(0);

    QListIterator<CG2Node*> it(m_lNodes);
    while(it.hasNext())
    {
        pNode = it.next();
        pNode->OnTimer(tNow);
    }

    quint32 nHubs = 0, nLeaves = 0, nUnknown = 0;
    quint32 nCoreHubs = 0, nCoreLeaves = 0;

    it.toFront();
    while(it.hasNext())
    {
        pNode = it.next();

        if( pNode->m_nState == nsConnected )
        {
            switch( pNode->m_nType )
            {
            case G2_UNKNOWN:
                nUnknown++;
                break;
            case G2_HUB:
                nHubs++;
                if( pNode->m_bG2Core )
                    nCoreHubs++;
                break;
            case G2_LEAF:
                nLeaves++;
                if( pNode->m_bG2Core )
                    nCoreLeaves++;
            }
        }
        else
        {
            nUnknown++;
        }


    }

    //qDebug("Hubs: %u, Leaves: %u, unknown: %u", nHubs, nLeaves, nUnknown);



    if( m_nHubsConnected != nHubs || m_nLeavesConnected != nLeaves )
        m_bNeedUpdateLNI = true;

    m_nHubsConnected = nHubs;
    m_nLeavesConnected = nLeaves;

    //return;

    if( m_nNodeState == G2_LEAF )
    {
        if( nHubs > LeafToHub )
        {
            // rozlaczyc
            DropYoungest(G2_HUB, (nCoreHubs / nHubs) > 0.5);
        }
        else if( nHubs < LeafToHub )
        //else if( nHubs < 1)
        {
            qint32 nAttempt = qint32((LeafToHub - nHubs) * ConnectFactor);
            nAttempt = qMin(nAttempt, 8) - nUnknown;

            quint32 tNow = time(0);

            for( ; nAttempt > 0; nAttempt-- )
            {
                // nowe polaczenie
                CHostCacheHost* pHost = HostCache.GetConnectable(tNow);

                if( pHost )
                {
                    CG2Node* pNew = new CG2Node();
                    //connect(pNew, SIGNAL(NodeStateChanged()), this, SLOT(OnNodeStateChange()));
                    emit NodeAdded(pNew);
                    m_pRateController->AddSocket(pNew);
                    m_lNodes.append(pNew);
                    pNew->connectToHost(pHost->m_oAddress);
                    pHost->m_tLastConnect = tNow;
                }
                else
                    break;
            }

        }
    }
    else
    {
        if( nHubs > HubToHub )
        {
            // rozlaczyc hub
            DropYoungest(G2_HUB, (nCoreHubs / nHubs) > 0.5);
        }
        else if( nHubs < HubToHub )
        {
            qint32 nAttempt = qint32((HubToHub - nHubs) * ConnectFactor);
            nAttempt = qMin(nAttempt, 8) - nUnknown;

            quint32 tNow = time(0);

            for( ; nAttempt > 0; nAttempt-- )
            {
                // nowe polaczenie
                CHostCacheHost* pHost = HostCache.GetConnectable(tNow);

                if( pHost )
                {
                    CG2Node* pNew = new CG2Node();
                    //connect(pNew, SIGNAL(NodeStateChanged()), this, SLOT(OnNodeStateChange()));
                    emit NodeAdded(pNew);
                    m_pRateController->AddSocket(pNew);
                    m_lNodes.append(pNew);
                    pNew->connectToHost(pHost->m_oAddress);
                    pHost->m_tLastConnect = tNow;
                }
                else
                    break;
            }
        }

        if( nLeaves > HubToLeaf )
        {
            DropYoungest(G2_LEAF, (nCoreLeaves / nLeaves) > 0.5);
        }
    }
}

void CNetwork::DispatchKHL()
{
    if( m_lNodes.isEmpty() )
        return;

    G2Packet* pKHL = G2Packet::New("KHL");
    G2Packet* pTmp = pKHL->WriteChild("TS");
    quint32 ts = time(0);
    pTmp->WriteBytes((void*)&ts, sizeof(ts));

    foreach(CG2Node* pNode, m_lNodes)
    {
        if( pNode->m_nType == G2_HUB && pNode->m_nState == nsConnected )
        {
            pTmp = pKHL->WriteChild("NH");
            pTmp->WriteBytes(&pNode->m_oAddress, 6);
        }
    }

    foreach(CG2Node* pNode, m_lNodes)
    {
        if( pNode->m_nState == nsConnected )
        {
            pKHL->AddRef();
            pNode->SendPacket(pKHL, true);
        }
    }
    pKHL->Release();
}

void CNetwork::OnNodeStateChange()
{
    QObject* pSender = QObject::sender();
    if( pSender )
        emit NodeUpdated(qobject_cast<CG2Node*>(pSender));
}

void CNetwork::OnAccept(QTcpSocket* pConn)
{
    CG2Node* pNew = new CG2Node();
    pNew->moveToThread(&NetworkThread);
    pNew->AttachTo(pConn);
    //connect(pNew, SIGNAL(NodeStateChanged()), this, SLOT(OnNodeStateChange()));
    emit NodeAdded(pNew);
    m_pRateController->AddSocket(pNew);
    m_lNodes.append(pNew);
}

bool CNetwork::IsListening()
{
    return Handshakes.isListening() && Datagrams.isListening();
}

bool CNetwork::IsFirewalled()
{
    return Datagrams.IsFirewalled() || Handshakes.IsFirewalled();
}

void CNetwork::DropYoungest(G2NodeType nType, bool bCore)
{
    CG2Node* pNode = 0;

    for( QList<CG2Node*>::iterator i = m_lNodes.begin(); i != m_lNodes.end(); i++ )
    {
        if( (*i)->m_nState == nsConnected )
        {
            if( (*i)->m_nType == nType )
            {
                if( !bCore && (*i)->m_bG2Core )
                    continue;

                if( pNode == 0 )
                {
                    pNode = (*i);
                }
                else
                {
                    if( (*i)->m_tConnected > pNode->m_tConnected )
                        pNode = (*i);
                }
            }
        }
    }

    if( pNode )
        pNode->disconnectFromHost();
}

void CNetwork::AcquireLocalAddress(QString &sHeader)
{
    IPv4_ENDPOINT hostAddr(sHeader + ":0");

    qDebug() << "Got Local Address: " << sHeader << hostAddr.toString();

    if( hostAddr.ip != 0 )
    {
        m_oAddress.ip = hostAddr.ip;
    }
}
bool CNetwork::IsConnectedTo(IPv4_ENDPOINT addr)
{
    for( int i = 0; i < m_lNodes.size(); i++ )
    {
        if( m_lNodes.at(i)->m_oAddress == addr )
            return true;
    }

    return false;
}

bool CNetwork::RoutePacket(QUuid &pTargetGUID, G2Packet *pPacket)
{
    CG2Node* pNode = 0;
    IPv4_ENDPOINT pAddr;

    if( m_oRoutingTable.Find(pTargetGUID, &pNode, &pAddr) )
    {
        if( pNode )
        {
            pNode->SendPacket(pPacket, true);
            return true;
        }
        else if( pAddr.ip )
        {
            Datagrams.SendPacket(pAddr, pPacket, true);
            return true;
        }
    }

    return false;
}
bool CNetwork::RoutePacket(G2Packet *pPacket, CG2Node *pNbr)
{
    QUuid pGUID;

    if( pPacket->IsAddressed(pGUID) ) // no i adres != moj adres
    {
        CG2Node* pNode = 0;
        IPv4_ENDPOINT pAddr;

        if( m_oRoutingTable.Find(pGUID, &pNode, &pAddr) )
        {
            bool bForwardTCP = false;
            bool bForwardUDP = false;

            if( pNbr )
            {
                if( pNbr->m_nType == G2_LEAF )  // if received from leaf - can forward anywhere
                {
                    bForwardTCP = bForwardUDP = true;
                }
                else    // if received from a hub - can be forwarded to leaf
                {
                    if( pNode && pNode->m_nType == G2_LEAF )
                    {
                        bForwardTCP = true;
                    }
                }
            }
            else    // received from udp - do not forward via udp
            {
                bForwardTCP = true;
            }

            if( pNode && bForwardTCP )
            {
                pNode->SendPacket(pPacket, true);
                return true;
            }
            else if( pAddr.ip && bForwardUDP )
            {
                Datagrams.SendPacket(pAddr, pPacket, true);
                return true;
            }
            // drop
        }
        return true;
    }
    return false;
}