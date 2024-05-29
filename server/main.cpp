#include <QCoreApplication>
#include "mytcpserver.h"
#include "Database.h"
#include "function.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    if (!QTest::qExec(&myserv, argc, argv)) {
        qDebug() << "Test 1 successfully passed!";
    }
    else{
        qDebug() << "Test 1 passed with errors!";
    }
    return a.exec();
}
