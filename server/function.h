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
/// \brief Функции валидации почты
/// \param email Электронная почта
bool isValidEmail(QString email);
/// \brief Вспомогательная функция для проверки дискриминанта
/// \param a Аргумент a
/// \param b Аргумент b
/// \param c Аргумент c
QString check_descr(float a, float b, float c);
/// \brief Алгоритм Дейкстры
/// \param graph Растояние между точками
/// \param size Количество точек
/// \param src Точка отсчета
QString dijkstra(QString graph, int size, int src);
/// \brief Алгоритм Бисекция
/// \param a Аргумент a
/// \param b Аргумент b
/// \param c Аргумент c
/// \param x_low Нижний предел
/// \param x_high Верхний предел
QString bisection_method(float a, float b, float c, float x_low, float x_high);
/// \brief Вспомогательная функция
float f(float x, float a, float b, float c);
#endif // FUNCTION_H
