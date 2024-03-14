#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>
#include <QCoreApplication>
#include <QString>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    /// \brief Слот, обрабатывающий новоеподключение к серверу
    void slotNewConnection();
    /// \brief Слот отключения клиента от сервера
    void slotClientDisconnected();
    /// \brief Слот прослушивающий сервер
    void slotServerRead();
private:
    /// \brief Указатель на объект класса
    QTcpServer * mTcpServer;
    /// \brief Контейнер подключений
    QMap<int, QTcpSocket*> mTcpSocket;
};
#endif // MYTCPSERVER_H







