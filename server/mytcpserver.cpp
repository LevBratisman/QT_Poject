#include "mytcpserver.h"
#include "function.h"

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    qDeleteAll(mTcpSockets.begin(), mTcpSockets.end());
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    QTcpSocket *curr_mTcpSocket = mTcpServer->nextPendingConnection();
    connect(curr_mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(curr_mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    mTcpSockets.append(curr_mTcpSocket);
    qDebug() << qobject_cast<QTcpSocket *>(sender());
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *curr_mTcpSocket = qobject_cast<QTcpSocket *>(sender());
    QString res = "";
    while (curr_mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = curr_mTcpSocket->readAll();
        qDebug() << array;
        res.append(array);
    }

    curr_mTcpSocket->write(parsing(res));
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    mTcpSockets.removeOne(socket);
    socket->deleteLater();
}
