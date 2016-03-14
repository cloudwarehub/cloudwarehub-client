#ifndef CIPCHANNELDISPLAY_H
#define CIPCHANNELDISPLAY_H

#include "cipchannel.h"
#include "cip_protocol.h"

class CipChannelDisplay : public CipChannel
{
    Q_OBJECT


public:
    CipChannelDisplay(QString ip, quint16 port);
    void run();

private:
    cip_event_window_frame_t *ev;

signals:
    void newFrame(cip_event_window_frame_t *ev, char *data);

public slots:
    void onData();

};

#endif // CIPCHANNELDISPLAY_H
