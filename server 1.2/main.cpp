#include <QCoreApplication>
#include "mytcpserver.h"
#include "Database.h"
#include <iostream>
#include "function.h"

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // QSqlDatabase& db = Database::getInstance().getDatabase();
    MyTcpServer myserv;
    return a.exec();
}
