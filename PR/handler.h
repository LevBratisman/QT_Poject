#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "mainwindow.h"
#include "authorization.h"
#include "net.h"
#include "registration.h"
#include "changeform.h"
#include "tasks.h"
#include "dijkstra.h"
#include "bi.h"
#include <QMessageBox>

class Handler : public QObject
{
    Q_OBJECT
public:
    Handler();

public slots:
    /// \brief Слот создания меню авторизации
    void openAuthorization();
    /// \brief Слот создания меню регистрации
    void openRegistration();
    /// \brief Слот создания меню изменения пароля
    void openChangeForm();
    /// \brief Слот создания меню с задачами
    void openTasksForm();
    /// \brief Слот создания меню с Бисекцией
    void openBiForm();
    /// \brief Слот создания меню с алгоритмом Дейкстры
    void openDijkstraForm();
    /// \brief Слот, открывающий меню авторизации из главного меню
    void openAuthorizationFromFirstWindow();
    /// \brief Слот обрабатывающий нажатие кнопки регистрации
    void handle_backButtonClikedFromReg();
    /// \brief Слот обрабатывающий нажатие кнопки авторизации
    void handle_backButtonClikedFromAuth();
    /// \brief Слот обрабатывающий нажатие кнопки меню смены пароля
    void handle_backButtonClikedFromChange();
    /// \brief Слот обрабатывающий нажатие кнопки меню задач
    void handle_backButtonClikedFromTasks();
    /// \brief Слот обрабатывающий нажатие кнопки меню с алгоритмом Дейкстры
    void handle_backButtonClikedFromDijkstra();
    /// \brief Слот обрабатывающий нажатие кнопки меню с Бисекцией
    void handle_backButtonClikedFromBi();
    /// \brief Слот обрабатывающий нажатие кнопки меню с алгоритмом Дейкстры
    void handle_dijkstraButtonClickedFromTasks();
    /// \brief Получение данных от сервера для алгоритма Дейкстры
    void getDataFromDijkstra(QString cur_p, QString start_p, QString data_str);
    /// \brief Получение данных от сервера для Бисекции
    /// \param a Аргумент a
    /// \param b Аргумент b
    /// \param c Аргумент c
    void handle_DataFromBi(QString a, QString b, QString c);

    /// \brief Верификация данных пользователя
    /// \param name Логин пользователя
    /// \param pass Пароль пользователя
    void handle_verify(QString name, QString pass);

private:
    /// \brief Функция, которая создает главное окно
    void CreateMainWindow();

    MainWindow *first_wind;
    Authorization *authorization;
    Registration *registration;
    ChangeForm *change_form;
    Dijkstra *dijkstra;
    Tasks *tasts;
    Bi *bi;

    QString user_name;
    QString password;

    Net *net;
};

#endif // HANDLER_H
