#ifndef CIPCHANNELMASTER_H
#define CIPCHANNELMASTER_H

#include <QTcpSocket>
#include "cipchannel.h"

class CipChannelMaster : public CipChannel
{
    Q_OBJECT


public slots:
    void onData();
public:
    CipChannelMaster(QString ip, quint16 port);
    int auth(QString token);
    void run();
};

#endif // CIPCHANNELMASTER_H
