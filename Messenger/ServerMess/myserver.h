#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class myserver: public QTcpServer
{
    Q_OBJECT
private:
    QByteArray messagesFromAllClients[12];
public:
    myserver();
    ~myserver();

    QTcpServer* server;
    QTcpSocket* socket[12];

public slots:
    void startServer();
    void NewConnect();
    void sockReady();
    void sockDisc();
};

#endif // MYSERVER_H
