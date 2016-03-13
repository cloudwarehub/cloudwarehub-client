#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork>
#include <QHostAddress>
#include "cipclient.h"
#include "cloudwaredialog.h"

MainWindow *mainwindow;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    mainwindow = new MainWindow();
    mainwindow->show();
//    /* connect to nat server */
//    QString server_ip = "180.150.186.157";
//    QHostAddress addr;
//    addr.setAddress(server_ip);

//    QTcpSocket *socket = new QTcpSocket();
//    socket->connectToHost(addr, 999);
//    if(!socket->waitForConnected()){
//        qDebug("cannot connect to 999\n");
//        return 0;
//    }

//    /* write cloudware instance id to nat server */
//    socket->write("hello", 6);

//    /* read nat port */
//    quint16 port;
//    if(!socket->waitForReadyRead()){
//        qErrnoWarning("cannot get proxy port!");
//        return 0;
//    }
//    socket->read((char*)&port, 2);
//    qDebug("nat port: %d\n", port);

    QString server_ip = "180.150.186.157";
    quint16 port = 5999;
    /* run cip client */
    CipClient *cipclient = new CipClient(server_ip, port);
    cipclient->mainwindow = mainwindow;
    cipclient->run();




    return a.exec();
}
