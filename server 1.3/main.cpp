#include <QCoreApplication>
#include "mytcpserver.h"
#include "Database.h"
#include <iostream>
#include "function.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
<<<<<<< HEAD:server 1.3/main.cpp
=======
    // QSqlDatabase& db = Database::getInstance().getDatabase();
>>>>>>> 64042d481ddef9a7818534e372ce9bb4afae214f:server 1.2/main.cpp
    MyTcpServer myserv;
    return a.exec();
}
