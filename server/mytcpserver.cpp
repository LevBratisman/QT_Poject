#include "mytcpserver.h"
#include "function.h"

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    QTcpSocket *curr_mTcpSocket;
    curr_mTcpSocket = mTcpServer->nextPendingConnection();
    //curr_mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
    connect(curr_mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(curr_mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
    mTcpSocket.insert(curr_mTcpSocket->socketDescriptor(), curr_mTcpSocket);
}

void MyTcpServer::slotServerRead(){
    QString res = "";
    qDebug()<<((QTcpSocket*)sender())->socketDescriptor();
    QTcpSocket *curr_mTcpSocket = mTcpSocket[((QTcpSocket*)sender())->socketDescriptor()];

    while(curr_mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = curr_mTcpSocket->readAll();
        res.append(array);
        qDebug() << res;
        //count_of_call++;
    }

    curr_mTcpSocket->write(parsing(res));
}

void MyTcpServer::slotClientDisconnected(){
    int key = QTcpSocket(sender()).socketDescriptor();
    mTcpSocket[key]->close();
    mTcpSocket.remove(key);
}
