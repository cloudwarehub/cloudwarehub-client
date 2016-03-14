#ifndef CIPCHANNELMASTER_H
#define CIPCHANNELMASTER_H

#include <QTcpSocket>
#include "cipchannel.h"


class CipChannelMaster : public CipChannel
{
    Q_OBJECT

private:
    int connected;

public slots:
    void onData();

public:
    CipChannelMaster(QString ip, quint16 port);
    int auth(QString token);
    void run();
    void *cipclient;
};

#endif // CIPCHANNELMASTER_H
