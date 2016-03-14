#include "cipchanneldisplay.h"
#include "cip_protocol.h"
#include "mainwindow.h"

extern MainWindow *mainwindow;

CipChannelDisplay::CipChannelDisplay(QString ip, quint16 port) : CipChannel(ip, port)
{
    this->type = CIP_CHANNEL_DISPLAY;
    this->ev = NULL;
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(onData()));
}

void CipChannelDisplay::onData()
{
    qDebug("ondata display:%d",this->socket->bytesAvailable());

    if (this->ev == NULL) { /* read head first, then frame data */

        if (this->socket->bytesAvailable() >= sizeof(cip_event_window_frame_t)) {
            this->ev = (cip_event_window_frame_t*)malloc(sizeof(cip_event_window_frame_t));
            this->read((char*)this->ev, sizeof(cip_event_window_frame_t));
            qDebug("%d", this->ev->length);

            if (this->socket->bytesAvailable() >= this->ev->length) { /* if frame data is ready to read */
                qDebug("still");
                char buf[this->ev->length];
                this->read(buf, this->ev->length);
                if(mainwindow->windows.contains(this->ev->wid))
                    mainwindow->windows[this->ev->wid]->decode((const unsigned char*)buf, this->ev->length);
                if(this->ev) {
                    free(this->ev);
                    this->ev = NULL;
                }
                this->onData();
            }
        }
    } else { /* header already read */
        if (this->socket->bytesAvailable() >= this->ev->length) { /* if frame data is ready to read */
            char buf[this->ev->length];
            this->read(buf, this->ev->length);
            if(mainwindow->windows.contains(this->ev->wid))
                mainwindow->windows[this->ev->wid]->decode((const unsigned char*)buf, this->ev->length);
            if(this->ev) {
                free(this->ev);
                this->ev = NULL;
            }
            this->onData();
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
