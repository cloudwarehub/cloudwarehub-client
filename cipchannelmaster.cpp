#include <QObject>
#include <QObject>
#include "cipchannelmaster.h"
#include "cip_protocol.h"
#include "cipclient.h"

CipChannelMaster::CipChannelMaster(QString ip, quint16 port) : CipChannel(ip, port)
{
    this->type = CIP_CHANNEL_MASTER;
    this->connected = false;
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(onData()));
}

int CipChannelMaster::auth(QString token)
{
    this->write(token.toStdString().c_str(), token.size()+1);
    return 0;
}

void CipChannelMaster::onData()
{
    qDebug("master ondata");
    if(!this->connected){
        CipClient *c = (CipClient*)this->cipclient;
        c->initOtherChannels();
    }
    this->connected = true;
}

void CipChannelMaster::run()
{

    this->connectServer();
    cip_message_connect_t conn;
    conn.version = 0;
    conn.channel_type = this->type;
    conn.session_length = 6;
    this->write((char*)&conn, sizeof(conn));
    this->write("hello", 6);
    //this->init("hello", 6);
}
