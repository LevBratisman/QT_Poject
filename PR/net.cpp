#include "net.h"

Net::Net() {
    socket = new QTcpSocket();
    connect_socket();
}






Net* Net::getInstance() {
    if(!p_net) {
        p_net = new Net();
    }
    return p_net;
}
