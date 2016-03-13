#include "cipchannel.h"
#include <QHostAddress>
#include "cip_protocol.h"

CipChannel::CipChannel(QString ip, quint16 port) : QObject()
{
    this->ip = ip;
    this->port = port;
    this->socket = new QTcpSocket();
}

int CipChannel::connectServer()
{
    QHostAddress addr;
    addr.setAddress(this->ip);

    this->socket->connectToHost(addr, this->port);
    if(!this->socket->waitForConnected()){
        qDebug("cannot establish channel on port: %d\n", this->port);
        return -1;
    }

    return 0;
}

qint64 CipChannel::write(const char *data, qint64 len)
{
    qint64 res = this->socket->write(data, len);
    //this->socket->waitForBytesWritten(-1);
    return res;
}

qint64 CipChannel::read(char *data, qint64 maxlen)
{
    int completed = 0;
    int res;
    while (completed < maxlen) {
        //res = this->socket->waitForReadyRead();
        if (res < 0)
            continue;
        res = this->socket->read(&data[completed], maxlen - completed);
        if (res <= 0) {
            return -1;
        }
        completed += res;
    }
    return completed;
}

int CipChannel::init(const char *session, int length)
{
    cip_message_connect_t conn;
    conn.version = 0;
    conn.channel_type = this->type;
    conn.session_length = length;
    this->write((char*)&conn, sizeof(conn));
    this->write(session, length);

    cip_message_connect_reply_t reply;
    this->read((char*)&reply, sizeof(reply));
    if (!reply.success) { /* success */
        return 0;
    } else {
        return -1;
    }

}
