#include "handler.h"

void Handler::CreateMainWindow() {
    first_wind = new MainWindow;
    first_wind->show();
    connect(first_wind, SIGNAL(auth_klick()), this, SLOT(openAuthorization()));
    connect(first_wind, SIGNAL(reg_klick()), this, SLOT(openRegistration()));
    connect(first_wind, SIGNAL(change_klick()), this, SLOT(openChangeForm()));
}


Handler::Handler() {
    CreateMainWindow();
}

void Handler::openAuthorization() {
    delete first_wind;
    authorization = new Authorization;
    authorization->show();
    connect(authorization, SIGNAL(backButtonClikedFromAuth()), this, SLOT(handle_backButtonClikedFromAuth()));
    connect(authorization, SIGNAL(newxButtonClikedFromAuth()), this, SLOT(openTasksForm()));
}

void Handler::openTasksForm() {
    delete authorization;
    tasts = new Tasks;
    tasts->show();
}

void Handler::openRegistration(){
    delete first_wind;
    registration = new Registration;
    registration->show();
    connect(registration, SIGNAL(backButtonClikedFromReg()), this, SLOT(handle_backButtonClikedFromReg()));
}

void Handler::openChangeForm() {
    delete first_wind;
    change_form = new ChangeForm;
    change_form->show();
    connect(change_form, SIGNAL(backButtonClikedFromChange()), this, SLOT(handle_backButtonClikedFromChange()));
}

void Handler::handle_backButtonClikedFromReg() {
    delete registration;
    CreateMainWindow();
}

void Handler::handle_backButtonClikedFromAuth() {
    delete authorization;
    CreateMainWindow();
}

void Handler::handle_backButtonClikedFromChange(){
    delete change_form;
    CreateMainWindow();
}
