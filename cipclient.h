#ifndef CIPCLIENT_H
#define CIPCLIENT_H

#include "mainwindow.h"
#include "cipchannel.h"
#include "cipchannelmaster.h"
#include "cipchannelevent.h"
#include "cipchanneldisplay.h"

class CipClient
{
private:
    QString ip;
    quint16 port;
    QString session;
    CipChannelMaster *channel_master;
    CipChannelEvent *channel_event;
    CipChannelDisplay *channel_display;

public:
    MainWindow *mainwindow;
    CipClient(QString ip, quint16 port);
    int run();

};

#endif // CIPCLIENT_H
