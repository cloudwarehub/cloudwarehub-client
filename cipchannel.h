#ifndef CIPCHANNEL_H
#define CIPCHANNEL_H

#include <QString>
#include <QTcpSocket>



class CipChannel : public QObject
{


protected:
    QString ip;
    quint16 port;
    QTcpSocket *socket;
    quint8 type; /* channel type */

public:
    explicit CipChannel(QString ip, quint16 port);
    int connectServer();
    qint64 write(const char *data, qint64 len);
    qint64 read(char *data, qint64 maxlen);
    int init(const char *session, int length);


};



#endif // CIPCHANNEL_H
