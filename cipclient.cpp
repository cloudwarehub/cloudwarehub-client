#include "cipclient.h"
#include "cipchannelmaster.h"
#include "cipchannelevent.h"
#include "cloudwaredialog.h"
#include "cip_protocol.h"
#include "cipchannelevent.h"

CipClient::CipClient(QString ip, quint16 port)
{
    this->ip = ip;
    this->port = port;
    this->channel_master = new CipChannelMaster(this->ip, this->port);
    this->channel_event = new CipChannelEvent(this->ip, this->port);
    this->channel_display = new CipChannelDisplay(this->ip, this->port);
    this->session = "hello";
}

int CipClient::run()
{

    this->channel_master->run();
    sleep(1);
    QObject::connect(this->channel_event, SIGNAL(windowCreate(cip_event_window_create_t*)),
                     this->mainwindow, SLOT(windowCreate(cip_event_window_create_t*)));
    QObject::connect(this->channel_event, SIGNAL(windowDestroy(cip_event_window_destroy_t*)),
                     this->mainwindow, SLOT(windowDestroy(cip_event_window_destroy_t*)));
    QObject::connect(this->channel_event, SIGNAL(windowShow(cip_event_window_show_t*)),
                     this->mainwindow, SLOT(windowShow(cip_event_window_show_t*)));
    QObject::connect(this->channel_event, SIGNAL(windowHide(cip_event_window_hide_t*)),
                     this->mainwindow, SLOT(windowHide(cip_event_window_hide_t*)));
    this->channel_event->run();
    this->channel_display->run();

    return 0;
}
