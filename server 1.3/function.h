#ifndef FUNCTION_H
#define FUNCTION_H

#include <QByteArray>
#include <QString>
#include <QStringList>
#include "Database.h"
#include <regex>
#include <string>
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
QByteArray searchShortestDistance(QStringList args);
QByteArray halvingMethod(QStringList args);

//void caching();
/// \brief Функция шифрования
/// \param src Информация о статистике пользователя
QByteArray encript(QByteArray src);

#endif // FUNCTION_H
