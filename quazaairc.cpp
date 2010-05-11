//
// quazaairc.cpp
//
// Copyright � Quazaa Development Team, 2009-2010.
// This file is part of QUAZAA (quazaa.sourceforge.net)
//
// Quazaa is free software; you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// Quazaa is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Quazaa; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "quazaairc.h"

QuazaaIRC::QuazaaIRC()
{
    QStringList channels;
    channels.append("#quazaa-dev");

    MyIrcSession session;
    session.setNick("quazaatestuser");
    session.setAutoJoinChannels(channels);
    session.connectToServer("irc.nixtrixirc.net", 6667);
}

MyIrcSession::MyIrcSession(QObject* parent) : Irc::Session(parent)
{
}

void MyIrcSession::on_connected()
{
    qDebug() << "connected:";
}

void MyIrcSession::on_disconnected()
{
    qDebug() << "disconnected:";
}

void MyIrcSession::on_bufferAdded(Irc::Buffer* buffer)
{
    qDebug() << "buffer added:" << buffer->receiver();
}

void MyIrcSession::on_bufferRemoved(Irc::Buffer* buffer)
{
    qDebug() << "buffer removed:" << buffer->receiver();
}

Irc::Buffer* MyIrcSession::createBuffer(const QString& receiver)
{
    return new MyIrcBuffer(receiver, this);
}

MyIrcBuffer::MyIrcBuffer(const QString& receiver, Irc::Session* parent)
    : Irc::Buffer(receiver, parent)
{
    connect(this, SIGNAL(receiverChanged(QString)), SLOT(on_receiverChanged(QString)));
    connect(this, SIGNAL(joined(QString)), SLOT(on_joined(QString)));
    connect(this, SIGNAL(parted(QString, QString)), SLOT(on_parted(QString, QString)));
    connect(this, SIGNAL(quit(QString, QString)), SLOT(on_quit(QString, QString)));
    connect(this, SIGNAL(nickChanged(QString, QString)), SLOT(on_nickChanged(QString, QString)));
    connect(this, SIGNAL(modeChanged(QString, QString, QString)), SLOT(on_modeChanged(QString, QString, QString)));
    connect(this, SIGNAL(topicChanged(QString, QString)), SLOT(on_topicChanged(QString, QString)));
    connect(this, SIGNAL(invited(QString, QString, QString)), SLOT(on_invited(QString, QString, QString)));
    connect(this, SIGNAL(kicked(QString, QString, QString)), SLOT(on_kicked(QString, QString, QString)));
    connect(this, SIGNAL(messageReceived(QString, QString)), SLOT(on_messageReceived(QString, QString)));
    connect(this, SIGNAL(noticeReceived(QString, QString)), SLOT(on_noticeReceived(QString, QString)));
    connect(this, SIGNAL(ctcpRequestReceived(QString, QString)), SLOT(on_ctcpRequestReceived(QString, QString)));
    connect(this, SIGNAL(ctcpReplyReceived(QString, QString)), SLOT(on_ctcpReplyReceived(QString, QString)));
    connect(this, SIGNAL(ctcpActionReceived(QString, QString)), SLOT(on_ctcpActionReceived(QString, QString)));
    connect(this, SIGNAL(numericMessageReceived(QString, uint, QStringList)), SLOT(on_numericMessageReceived(QString, uint, QStringList)));
    connect(this, SIGNAL(unknownMessageReceived(QString, QStringList)), SLOT(on_unknownMessageReceived(QString, QStringList)));
}

void MyIrcBuffer::on_receiverChanged(const QString& receiver)
{
    qDebug() << "receiver changed:" << receiver;
}

void MyIrcBuffer::on_joined(const QString& origin)
{
    qDebug() << "joined:" << receiver() << origin;
}

void MyIrcBuffer::on_parted(const QString& origin, const QString& message)
{
    qDebug() << "parted:" << receiver() << origin << message;
}

void MyIrcBuffer::on_quit(const QString& origin, const QString& message)
{
    qDebug() << "quit:" << receiver() << origin << message;
}

void MyIrcBuffer::on_nickChanged(const QString& origin, const QString& nick)
{
    qDebug() << "nick changed:" << receiver() << origin << nick;
}

void MyIrcBuffer::on_modeChanged(const QString& origin, const QString& mode, const QString& args)
{
    qDebug() << "mode changed:" << receiver() << origin << mode << args;
}

void MyIrcBuffer::on_topicChanged(const QString& origin, const QString& topic)
{
    qDebug() << "topic changed:" << receiver() << origin << topic;
}

void MyIrcBuffer::on_invited(const QString& origin, const QString& receiver, const QString& channel)
{
    qDebug() << "invited:" << Irc::Buffer::receiver() << origin << receiver << channel;
}

void MyIrcBuffer::on_kicked(const QString& origin, const QString& nick, const QString& message)
{
    qDebug() << "kicked:" << receiver() << origin << nick << message;
}

void MyIrcBuffer::on_messageReceived(const QString& origin, const QString& message)
{
    qDebug() << "message received:" << receiver() << origin << message;
}

void MyIrcBuffer::on_noticeReceived(const QString& origin, const QString& notice)
{
    qDebug() << "notice received:" << receiver() << origin << notice;
}

void MyIrcBuffer::on_ctcpRequestReceived(const QString& origin, const QString& request)
{
    qDebug() << "ctcp request received:" << receiver() << origin << request;
}

void MyIrcBuffer::on_ctcpReplyReceived(const QString& origin, const QString& reply)
{
    qDebug() << "ctcp reply received:" << receiver() << origin << reply;
}

void MyIrcBuffer::on_ctcpActionReceived(const QString& origin, const QString& action)
{
    qDebug() << "ctcp action received:" << receiver() << origin << action;
}

void MyIrcBuffer::on_numericMessageReceived(const QString& origin, uint code, const QStringList& params)
{
    qDebug() << "numeric message received:" << receiver() << origin << code << params;
}

void MyIrcBuffer::on_unknownMessageReceived(const QString& origin, const QStringList& params)
{
    qDebug() << "unknown message received:" << receiver() << origin << params;
}
