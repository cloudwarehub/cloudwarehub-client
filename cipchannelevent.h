#ifndef CIPCHANNELEVENT_H
#define CIPCHANNELEVENT_H

#include "cipchannel.h"
#include "cip_protocol.h"

class CipChannelEvent : public CipChannel
{
    Q_OBJECT

public:
    CipChannelEvent(QString ip, quint16 port);
    void run();

signals:
    void windowCreate(cip_event_window_create_t*);
    void windowDestroy(cip_event_window_destroy_t*);
    void windowShow(cip_event_window_show_t*);
    void windowHide(cip_event_window_hide_t*);


public slots:
    void onData();
};

#endif // CIPCHANNELEVENT_H
