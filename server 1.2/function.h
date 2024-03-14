#ifndef FUNCTION_H
#define FUNCTION_H

#include <QByteArray>
#include <QString>
#include <QStringList>
#include "Database.h"
#include <regex>
#include <string>

QByteArray parsing(QString client_data);

QByteArray auth(QString log, QString pass);

QByteArray reg(QString log, QString pass, QString mail);

QByteArray viewStat();

bool isValidEmail(QString email);
QByteArray task1(QStringList args);
QByteArray task2(QStringList args);

// void caching();

QByteArray encript(QByteArray);

#endif // FUNCTION_H
