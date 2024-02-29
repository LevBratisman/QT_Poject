#ifndef FUNCTION_H
#define FUNCTION_H

//#include <QCoreApplication>
#include <QByteArray>
#include <QString>
//#include <QObject>
#include <QStringList>
#include "Database.h"

QByteArray parsing(QString client_data);

QByteArray auth(QString log, QString pass);

QByteArray reg(QString log, QString pass, QString mail);

//void task();

//void caching();

#endif // FUNCTION_H
