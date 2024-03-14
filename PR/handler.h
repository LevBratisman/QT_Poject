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
    void openAuthorization();
    void openRegistration();
    void openChangeForm();
    void openTasksForm();

    void handle_backButtonClikedFromReg();
    void handle_backButtonClikedFromAuth();
    void handle_backButtonClikedFromChange();

private:
    void CreateMainWindow();

    MainWindow *first_wind;
    Authorization *authorization;
    Registration *registration;
    ChangeForm *change_form;
    Tasks *tasts;
};

#endif // HANDLER_H
