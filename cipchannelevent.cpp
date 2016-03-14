#include "cipchannelevent.h"
#include "cip_protocol.h"
#include "cloudwaredialog.h"

CipChannelEvent::CipChannelEvent(QString ip, quint16 port) : CipChannel(ip, port)
{
    this->type = CIP_CHANNEL_EVENT;
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(onData()));
}

void CipChannelEvent::onData()
{
    qDebug("ondata");

    while(this->socket->bytesAvailable() >= 16) {
        char buf[sizeof(cip_event_window_create_t)];
        int res;
        res = this->read(buf, sizeof(cip_event_window_create_t));
        if (res <= 0) {
            return;
        }
        qDebug("event type: %d", buf[0]);
        switch (buf[0]) {
        case CIP_EVENT_WINDOW_CREATE:{
            cip_event_window_create_t *cewc = (cip_event_window_create_t*)buf;
            emit windowCreate(cewc);
            qDebug("%d,%d,%d,%d", cewc->x, cewc->y,cewc->width,cewc->height);
            break;}
        case CIP_EVENT_WINDOW_DESTROY:{
            cip_event_window_destroy_t *cewd = (cip_event_window_destroy_t*)buf;
            emit windowDestroy(cewd);
            break;}
        case CIP_EVENT_WINDOW_SHOW:{
            emit windowShow((cip_event_window_show_t*)buf);
            break;}
        case CIP_EVENT_WINDOW_HIDE:{
            emit windowHide((cip_event_window_hide_t*)buf);
            break;}
        default:
            break;
        }
    }
}

void CipChannelEvent::run()
{
    this->connectServer();
    cip_message_connect_t conn;
    conn.version = 0;
    conn.channel_type = this->type;
    conn.session_length = 6;
    this->write((char*)&conn, sizeof(conn));
    this->write("hello", 6);
}

