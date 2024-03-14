#include <QApplication>
#include "mainwindow.h"
#include "handler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Handler hnd;
    return a.exec();
}
