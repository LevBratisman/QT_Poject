#include "mytcpserver.h"
#include "function.h"

/**
 * @brief Destroy the My Tcp Server:: My Tcp Server object
 *
 */
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

/**
 * @brief Construct a new My Tcp Server:: My Tcp Server object
 *
 * @param parent
 */
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

/**
 * @brief
 *
 */
void MyTcpServer::slotNewConnection()
{
    QTcpSocket *curr_mTcpSocket;
    curr_mTcpSocket = mTcpServer->nextPendingConnection();
    connect(curr_mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(curr_mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    mTcpSocket.insert(curr_mTcpSocket->socketDescriptor(), curr_mTcpSocket);
}

/**
 * @brief
 *
 */
void MyTcpServer::slotServerRead()
{
    QString res = "";
    // qDebug()<<((QTcpSocket*)sender())->socketDescriptor();
    QTcpSocket *curr_mTcpSocket = mTcpSocket[((QTcpSocket *)sender())->socketDescriptor()];

    while (curr_mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = curr_mTcpSocket->readAll();
        res.append(array);
    }

    curr_mTcpSocket->write(parsing(res));
}

/**
 * @brief
 *
 */
void MyTcpServer::slotClientDisconnected()
{
    int key = QTcpSocket(sender()).socketDescriptor();
    mTcpSocket[key]->close();
    mTcpSocket.remove(key);
}
