#ifndef CIPCHANNELDISPLAY_H
#define CIPCHANNELDISPLAY_H

#include "cipchannel.h"
#include "cip_protocol.h"

class CipChannelDisplay : public CipChannel
{
    Q_OBJECT


public slots:
    void onData();

public:
    CipChannelDisplay(QString ip, quint16 port);
    void run();

};

#endif // CIPCHANNELDISPLAY_H
