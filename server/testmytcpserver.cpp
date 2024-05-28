#include "mytcpserver.h"

class TestMyTcpServer : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testConnection();

private:
    MyTcpServer *server;
};

void TestMyTcpServer::initTestCase()
{
    server = new MyTcpServer();
}

void TestMyTcpServer::cleanupTestCase()
{
    server->deleteLater();
}

void TestMyTcpServer::testConnection()
{
    QTcpSocket socket;
    socket.connectToHost(QHostAddress::Any, 33333);
    QVERIFY(socket.waitForConnected());
}
