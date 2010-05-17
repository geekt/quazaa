#include "g2packet.h"

G2PacketPool G2Packets;

G2Packet::G2Packet()
{
	m_pNext			= 0;
	m_nReference	= 0;

	m_nPosition		= 0;

	memset(&m_sType[0], 0, sizeof(m_sType));
	m_bCompound = false;
}

G2Packet::~G2Packet()
{
	Q_ASSERT( m_nReference == 0 );
}

void G2Packet::Reset()
{
	Q_ASSERT( m_nReference == 0 );

	m_pNext			= 0;
	m_oBuffer.clear();
	m_nPosition		= 0;

	memset(&m_sType[0], 0, sizeof(m_sType));
	m_bCompound = false;
}

void G2Packet::Seek(quint32 nPosition, int nRelative)
{
	if ( nRelative == seekStart )
	{
		m_nPosition = qMax( 0u, qMin<quint32>( m_oBuffer.size(), nPosition ) );
	}
	else
	{
		m_nPosition = qMax( 0u, qMin<quint32>( m_oBuffer.size(), m_oBuffer.size() - nPosition ) );
	}
}


char* G2Packet::WriteGetPointer(quint32 nLength, quint32 nOffset)
{
	if ( nOffset == 0xFFFFFFFF ) nOffset = m_oBuffer.size();

	if ( m_oBuffer.size() + nLength > m_oBuffer.capacity() )
	{
		m_oBuffer.reserve(qMax(m_oBuffer.capacity() + nLength, m_oBuffer.capacity() + 128u));
	}

	int nOldSize = m_oBuffer.size();
	m_oBuffer.resize(m_oBuffer.size() + nLength);

	if ( nOffset != nOldSize )
	{
		memmove(m_oBuffer.data() + nOffset + nLength, m_oBuffer.data() + nOffset, nOldSize - nOffset);
	}

	return m_oBuffer.data() + nOffset;
}

char* G2Packet::GetType() const
{
	return (char*)&m_sType;
}
void G2Packet::Delete()
{
	G2Packets.Delete(this);
}
G2Packet* G2Packet::New(const char* pszType, bool bCompound)
{
	G2Packet* pPacket = G2Packets.New();

	if ( pszType != 0 )
	{
		size_t nLength = strlen(pszType);
		strncpy( pPacket->m_sType, pszType, nLength );
		pPacket->m_sType[nLength] = 0;
	}

	pPacket->m_bCompound = bCompound;

	return pPacket;
}
G2Packet* G2Packet::New(char* pSource)
{
	G2Packet* pPacket = New();

	char nInput		= *pSource++;

	char nLenLen	= ( nInput & 0xC0 ) >> 6;
	char nTypeLen	= ( nInput & 0x38 ) >> 3;
	char nFlags	= ( nInput & 0x07 );

	pPacket->m_bCompound	= ( nFlags & G2_FLAG_COMPOUND ) ? true : false;
	bool	bBigEndian	= ( nFlags & G2_FLAG_BIG_ENDIAN ) ? true : false;

	quint32 nLength = 0;

	if ( bBigEndian )
	{
		throw packet_error();
	}
	else
	{
		char* pLenOut = (char*)&nLength;
		while ( nLenLen-- ) *pLenOut++ = *pSource++;
	}

	nTypeLen++;
	char* pszType = pPacket->m_sType;
	for ( ; nTypeLen-- ;  )
	{
		*pszType++ = *pSource++;
	}
	*pszType++ = 0;

	pPacket->Write( pSource, nLength );

	return pPacket;
}


G2PacketPool::G2PacketPool()
{
	m_pFree = 0;
	m_nFree = 0;
}

G2PacketPool::~G2PacketPool()
{
	Clear();
}

G2Packet* G2Packet::WritePacket(G2Packet* pPacket)
{
	if ( pPacket == 0 ) return 0;
	WritePacket( pPacket->m_sType, pPacket->m_oBuffer.size(), pPacket->m_bCompound );
	Write( pPacket->m_oBuffer.data(), pPacket->m_oBuffer.size() );
	return this;
}

G2Packet* G2Packet::WritePacket(const char* pszType, quint32 nLength, bool bCompound)
{
	Q_ASSERT( strlen( pszType ) > 0 );
	Q_ASSERT( nLength <= 0xFFFFFF );

	char nTypeLen	= (char)( strlen( pszType ) - 1 ) & 0x07;
	char nLenLen	= ((nLength & 0x000000ff)>0) + ((nLength & 0x0000ff00)>0) + ((nLength & 0x00ff0000)>0);

	char nFlags = ( nLenLen << 6 ) + ( nTypeLen << 3 );

	if ( bCompound ) nFlags |= G2_FLAG_COMPOUND;

	Write( &nFlags, 1 );

	Write( &nLength, nLenLen );

	Write( const_cast<char*>(pszType), nTypeLen + 1 );

	m_bCompound = true;

	return this;
}

bool G2Packet::ReadPacket(char* pszType, quint32& nLength, bool* pbCompound)
{
	if ( GetRemaining() == 0 ) return false;

	char nInput = ReadByte();
	if ( nInput == 0 ) return false;

	char nLenLen	= ( nInput & 0xC0 ) >> 6;
	char nTypeLen	= ( nInput & 0x38 ) >> 3;
	char nFlags		= ( nInput & 0x07 );

	if ( GetRemaining() < nTypeLen + nLenLen + 1 ) throw packet_error();

	nLength = 0;
	Read( &nLength, nLenLen );

	if ( GetRemaining() < (int)nLength + nTypeLen + 1 ) throw packet_error();

	Read( pszType, nTypeLen + 1 );
	pszType[ nTypeLen + 1 ] = 0;

	if ( pbCompound )
	{
		*pbCompound = ( nFlags & G2_FLAG_COMPOUND ) == G2_FLAG_COMPOUND;
	}
	else
	{
		if ( nFlags & G2_FLAG_COMPOUND ) SkipCompound( nLength );
	}

	return true;
}

bool G2Packet::SkipCompound()
{
	if ( m_bCompound )
	{
		quint32 nLength = m_oBuffer.size();
		if ( ! SkipCompound( nLength ) ) return false;
	}

	return true;
}

bool G2Packet::SkipCompound(quint32& nLength, quint32 nRemaining)
{
	quint32 nStart	= m_nPosition;
	quint32 nEnd	= m_nPosition + nLength;

	while ( m_nPosition < nEnd )
	{
		char nInput = ReadByte();
		if ( nInput == 0 ) break;

		char nLenLen	= ( nInput & 0xC0 ) >> 6;
		char nTypeLen	= ( nInput & 0x38 ) >> 3;
		char nFlags	= ( nInput & 0x07 );
		Q_UNUSED(nFlags);

		if ( m_nPosition + nTypeLen + nLenLen + 1 > nEnd ) throw packet_error();

		quint32 nPacket = 0;

		Read( &nPacket, nLenLen );

		if ( m_nPosition + nTypeLen + 1 + nPacket > nEnd ) throw packet_error();

		m_nPosition += nPacket + nTypeLen + 1;
	}

	nEnd = m_nPosition - nStart;
	if ( nEnd > nLength ) throw packet_error();
	nLength -= nEnd;

	return nRemaining ? nLength >= nRemaining : true;
}

void G2Packet::ToBuffer(QByteArray* pBuffer) const
{
	Q_ASSERT( strlen( m_sType ) > 0 );

	char nLenLen	= ((m_oBuffer.size() & 0x000000ff)>0) + ((m_oBuffer.size() & 0x0000ff00)>0) + ((m_oBuffer.size() & 0x00ff0000)>0);
	char nTypeLen	= (char)( strlen( m_sType ) - 1 ) & 0x07;

	char nFlags = ( nLenLen << 6 ) + ( nTypeLen << 3 );

	if ( m_bCompound ) nFlags |= G2_FLAG_COMPOUND;

	pBuffer->append( (char*)&nFlags, 1 );

	quint32 nLength = m_oBuffer.size();
	pBuffer->append( (char*)&nLength, nLenLen );

	pBuffer->append( (char*)&m_sType[0], nTypeLen + 1 );

	pBuffer->append( m_oBuffer );
}

//////////////////////////////////////////////////////////////////////
// G2Packet buffer stream read

G2Packet* G2Packet::ReadBuffer(QByteArray* pBuffer)
{
	if ( pBuffer == 0 )
		return 0;

	if ( pBuffer->size() < 2 )
		return 0;

	char nInput = *pBuffer[0];

	if ( nInput == 0 )
	{
		pBuffer->remove(0, 1);
		return 0;
	}

	char nLenLen	= ( nInput & 0xC0 ) >> 6;
	char nTypeLen	= ( nInput & 0x38 ) >> 3;
	char nFlags		= ( nInput & 0x07 );

	if ( (quint32)pBuffer->size() < (quint32)nLenLen + nTypeLen + 2u )
		return 0;

	quint32 nLength = 0;

	if ( nFlags & G2_FLAG_BIG_ENDIAN )
	{
		throw packet_error();
	}
	else
	{
		char* pLenIn	= pBuffer->data() + 1;
		char* pLenOut	= (char*)&nLength;
		for ( char nLenCnt = nLenLen ; nLenCnt-- ; ) *pLenOut++ = *pLenIn++;
	}

	if ( (quint32)pBuffer->size() < (quint32)nLength + nLenLen + nTypeLen + 2 )
		return 0;

	G2Packet* pPacket = G2Packet::New( pBuffer->data() );
	pBuffer->remove(0, nLength + nLenLen + nTypeLen + 2 );

	return pPacket;
}

QString G2Packet::ReadString()
{
	qint32 nNullIndex = 0;

	char chZero = 0;

	nNullIndex = m_oBuffer.indexOf(chZero, m_nPosition);
	if( nNullIndex == -1 )
		nNullIndex = m_oBuffer.size();
	nNullIndex -= m_nPosition;

	char* pStart = m_oBuffer.data() + m_nPosition;
	m_nPosition += nNullIndex + 1;
	m_nPosition = qMin<int>(m_nPosition, m_oBuffer.size());

	return QString::fromUtf8(pStart, nNullIndex);
}
void G2Packet::WriteString(QString sToWrite, bool bTerminate)
{
	m_oBuffer += sToWrite.toUtf8();
	if( bTerminate )
		m_oBuffer += "\x00";
}

QString G2Packet::ToHex() const
{
	const char* pszHex = "0123456789ABCDEF";
	QByteArray strDump;

	strDump.resize(m_oBuffer.size() * 3);
	char* pszDump = strDump.data();

	for ( qint32 i = 0 ; i < m_oBuffer.size() ; i++ )
	{
		int nChar = m_oBuffer[i];
		if ( i ) *pszDump++ = ' ';
		*pszDump++ = pszHex[ nChar >> 4 ];
		*pszDump++ = pszHex[ nChar & 0x0F ];
	}

	*pszDump = 0;

	return strDump;
}

QString G2Packet::ToASCII() const
{
	QByteArray strDump;

	strDump.resize(m_oBuffer.size() + 1);
	char* pszDump = strDump.data();

	for ( int i = 0 ; i < m_oBuffer.size() ; i++ )
	{
		int nChar = m_oBuffer[i];
		*pszDump++ = ( nChar >= 32 ? nChar : '.' );
	}

	*pszDump = 0;

	return strDump;
}


void G2PacketPool::Clear()
{
	for ( int nIndex = m_pPools.size() - 1 ; nIndex >= 0 ; nIndex-- )
	{
		G2Packet* pPool = (G2Packet*)m_pPools[ nIndex ];
		delete [] pPool;
	}

	m_pPools.clear();;
	m_pFree = 0;
	m_nFree = 0;
}

//////////////////////////////////////////////////////////////////////
// G2PacketPool new pool setup

void G2PacketPool::NewPool()
{
	G2Packet* pPool = 0;
	int nPitch = 0, nSize = 256;

	nPitch	= sizeof(G2Packet);
	pPool	= new G2Packet[ nSize ];

	m_pPools.append( pPool );

	char* pchars = (char*)pPool;

	while ( nSize-- > 0 )
	{
		pPool = (G2Packet*)pchars;
		pchars += nPitch;

		pPool->m_pNext = m_pFree;
		m_pFree = pPool;
		m_nFree++;
	}
}
