#ifndef FUNCTION_H
#define FUNCTION_H

#include "Database.h"

#include <QByteArray>
#include <QString>
#include <QStringList>
#include <regex>
#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include <QVector>
#include <QVariant>
#include <cmath>

/// \brief Функция обрабатывания запросов от клиента
/// \param client_data Данные от клиента
QByteArray parsing(QString client_data);
/// \brief Функция авторизации
/// \param log Логин
/// \param pass Пароль
QByteArray auth(QString log, QString pass);
/// \brief Функция регистрации
/// \param log Логин
/// \param pass Пароль
/// \param mail Электронная почта
QByteArray reg(QString log, QString pass, QString mail);
/// \brief Функция выводящая статистику
QByteArray viewStat();
/// \brief Функции валидации почты
/// \param email Электронная почта
bool isValidEmail(QString email);
/// \brief Функция шифрования
/// \param src Информация о статистике пользователя
QByteArray encript(QByteArray src);
QString dijkstra(QString graph, int size, int src);
QString bisection_method(float a, float b, float c, float x_low, float x_high);
float f(float x, float a, float b, float c);
#endif // FUNCTION_H
