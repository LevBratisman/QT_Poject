#ifndef NET_H
#define NET_H
#include <QTcpSocket>
#include <QObject>

class Net : public QObject
{
    Q_OBJECT
public:
    Net();
    void send_to_server(QString str);
    QString getData();
private slots:
    void slotReadyReed();
private:

    void connect_socket();
    static Net *p_net;
    QTcpSocket *socket;
    QString data_str;
};

#endif // NET_H
