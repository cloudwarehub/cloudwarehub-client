#include <x265.h>
#include "cipchanneldisplay.h"
#include "cip_protocol.h"

CipChannelDisplay::CipChannelDisplay(QString ip, quint16 port) : CipChannel(ip, port)
{
    this->type = CIP_CHANNEL_DISPLAY;

    connect(this->socket, SIGNAL(readyRead()), this, SLOT(onData()));
}



void CipChannelDisplay::onData()
{
    qDebug("ondata display");

    return;
    while(this->socket->bytesAvailable() >= 8) {
        char buf[sizeof(cip_event_window_create_t)];
        int res;
        res = this->read(buf, sizeof(cip_event_window_create_t));
        if (res <= 0) {
            return;
        }

    }
}

void CipChannelDisplay::run()
{
    this->connectServer();
    cip_message_connect_t conn;
    conn.version = 0;
    conn.channel_type = this->type;
    conn.session_length = 6;
    this->write((char*)&conn, sizeof(conn));
    this->write("hello", 6);
}
