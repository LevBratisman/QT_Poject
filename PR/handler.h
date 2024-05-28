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

    void openBiForm();

    void openDijkstraForm();

    void openAuthorizationFromFirstWindow();

    /// \brief Слот обрабатывающий нажатие кнопки регистрации
    void handle_backButtonClikedFromReg();
    /// \brief Слот обрабатывающий нажатие кнопки авторизации
    void handle_backButtonClikedFromAuth();
    /// \brief Слот обрабатывающий нажатие кнопки меню смены пароля
    void handle_backButtonClikedFromChange();

    void handle_backButtonClikedFromTasks();

    void handle_backButtonClikedFromDijkstra();

    void handle_backButtonClikedFromBi();

    void handle_dijkstraButtonClickedFromTasks();

    void getDataFromDijkstra(QString cur_p, QString start_p, QString data_str);

    void handle_DataFromBi(QString a, QString b, QString c);




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

    Net * net;
};

#endif // HANDLER_H
