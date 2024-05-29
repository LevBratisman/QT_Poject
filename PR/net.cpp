#include "net.h"

Net::Net() {
    socket = new QTcpSocket();
    connect(socket, &QTcpSocket::readyRead, this, &Net::slotReadyReed);
    connect_socket();
}

void Net::connect_socket() {

    qDebug() << "connect_socket";
    socket->connectToHost("192.168.238.136", 33333);
    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

    }
    else
    {
        qDebug() << "Not connected!";
    }
}

void Net::slotReadyReed() {
    this->data_str.clear();
    while (socket->bytesAvailable() > 0)
    {
        QByteArray array = socket->readAll();
        this->data_str += QString(array);
        qDebug() << "get" << array;
    }
    qDebug() << data_str;
}

void Net::send_to_server(QString str) {
    qDebug() << "send_to_server";
    socket->write(str.toUtf8());
}

QString Net::getData() {
    return data_str;
}


