#ifndef NET_H
#define NET_H
#include <QTcpSocket>

class Net
{
public:
    Net();
    static Net* getInstance();
    void send_to_server(QString str);
private:

    void connect_socket();
    static Net *p_net;
    QTcpSocket *socket;
};

#endif // NET_H
