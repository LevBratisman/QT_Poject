#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "mainwindow.h"
#include "authorization.h"
#include "registration.h"
#include "changeform.h"
#include "tasks.h"

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

    /// \brief Слот обрабатывающий нажатие кнопки регистрации
    void handle_backButtonClikedFromReg();
    /// \brief Слот обрабатывающий нажатие кнопки авторизации
    void handle_backButtonClikedFromAuth();
    /// \brief Слот обрабатывающий нажатие кнопки меню смены пароля
    void handle_backButtonClikedFromChange();

private:
    /// \brief Функция, которая создает главное окно
    void CreateMainWindow();

    MainWindow *first_wind;
    Authorization *authorization;
    Registration *registration;
    ChangeForm *change_form;
    Tasks *tasts;
};

#endif // HANDLER_H
