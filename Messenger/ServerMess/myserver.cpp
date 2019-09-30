#include "myserver.h"

myserver::myserver(){}

myserver::~myserver(){}

static int j=0;

void myserver::startServer()
{
    server = new QTcpServer (this);
    server->setMaxPendingConnections(12);

    for(int i=0;i<server->maxPendingConnections();i++)
    {
        socket[i] = new QTcpSocket(this);
    }

        if(server->listen(QHostAddress::Any,5555))
        {
            connect(server, SIGNAL(newConnection()), this, SLOT(NewConnect()));
            qDebug()<<"Waiting for connection...";
        }else
        {
            qDebug()<<"Error: server is not waiting for connection...";
        }
}


void myserver::NewConnect()
{

         qDebug()<<"Client " << j+1 << " connected...";
         socket[j] = server->nextPendingConnection();
         connect(socket[j],SIGNAL(readyRead()),this,SLOT(sockReady()));
         connect(socket[j],SIGNAL(disconnected()),this,SLOT(sockDisc()));
         j++;

}

void myserver::sockReady()
{

    for (int i=0;i<server->maxPendingConnections();i++)
    {
        if(socket[i]->waitForConnected(50))
           messagesFromAllClients[i] = socket[i]->readAll();
    }
    //messages are sent to everyone
    //
    for (int k=0;k<server->maxPendingConnections();k++)
         for (int i=0;i<server->maxPendingConnections();i++)
              if(socket[k]->waitForConnected(50))
                  socket[k]->write(messagesFromAllClients[i]);
}

void myserver::sockDisc()
{
    qDebug()<<"Client " << j << " disconnected...";
    j--;
}
