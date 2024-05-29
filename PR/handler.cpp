#include "handler.h"
#include<thread>

void Handler::CreateMainWindow() {
    first_wind = new MainWindow;
    first_wind->show();
    connect(first_wind, SIGNAL(auth_klick()), this, SLOT(openAuthorizationFromFirstWindow()));
    connect(first_wind, SIGNAL(reg_klick()), this, SLOT(openRegistration()));
    connect(first_wind, SIGNAL(change_klick()), this, SLOT(openChangeForm()));
}


Handler::Handler() {
    CreateMainWindow();
    net = new Net();
    this->password = "1234";
    this->user_name = "name";
}

void Handler::openAuthorization() {
    authorization = new Authorization;
    authorization->show();
    connect(authorization, SIGNAL(backButtonClikedFromAuth()), this, SLOT(handle_backButtonClikedFromAuth()));
    connect(authorization, SIGNAL(newxButtonClikedFromAuth()), this, SLOT(openTasksForm()));
    connect(authorization, SIGNAL(newAuth(QString, QString)), this, SLOT(handle_verify(QString, QString)));
}

void Handler::openTasksForm() {
    tasts = new Tasks;
    tasts->show();
    connect(tasts, SIGNAL(OpenDijkstraButtonClickedFromTasks()), this, SLOT(handle_dijkstraButtonClickedFromTasks()));
    connect(tasts, SIGNAL(OpenBiButtonClickedFromTasks()), this, SLOT(handle_OpenBiButtonClickedFromTasks()));
    connect(tasts, SIGNAL(backButtonClikedFromTasks()), this, SLOT(handle_backButtonClikedFromTasks()));
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

void Handler::openDijkstraForm(){
    dijkstra = new Dijkstra;
    dijkstra->show();
    connect(dijkstra, SIGNAL(SendDijkstraData(QString, QString, QString)), this, SLOT(getDataFromDijkstra(QString, QString, QString)));
    connect(dijkstra, SIGNAL(backButtonClikedFromDijkstra()), this, SLOT(handle_backButtonClikedFromDijkstra()));
}

void Handler::openBiForm() {
    bi = new Bi;
    bi->show();
    connect(bi, SIGNAL(SendDataFromBi(QString,QString,QString)), this, SLOT(handle_DataFromBi(QString,QString,QString)));
    connect(bi, SIGNAL(backButtonClikedFromBi()), this, SLOT(handle_backButtonClikedFromBi()));
}


void Handler::openAuthorizationFromFirstWindow() {
    delete first_wind;
    openAuthorization();
}

void Handler::handle_OpenBiButtonClickedFromTasks() {
    delete tasts;
    openBiForm();
}

void Handler::handle_backButtonClikedFromReg() {
    delete registration;
    CreateMainWindow();
}

void Handler::handle_backButtonClikedFromBi() {
    delete bi;
    openTasksForm();
}

void Handler::handle_backButtonClikedFromDijkstra() {
    delete dijkstra;
    openTasksForm();
}

void Handler::handle_backButtonClikedFromAuth() {
    delete authorization;
    openTasksForm();
}

void Handler::handle_backButtonClikedFromChange(){
    delete change_form;
    CreateMainWindow();
}

void Handler::handle_backButtonClikedFromTasks() {
    delete tasts;
    openAuthorization();
}

void Handler::handle_dijkstraButtonClickedFromTasks() {
    delete tasts;
    openDijkstraForm();
}

void Handler::handle_DataFromBi(QString a, QString b, QString c) {
    QString str_to_send = "bisection_method";
    str_to_send.append("&");
    str_to_send.append(a);
    str_to_send.append("&");
    str_to_send.append(b);
    str_to_send.append("&");
    str_to_send.append(c);
    str_to_send.append("&");
    net->send_to_server(str_to_send);
    qDebug() << "data is = " <<net->getData();
    bi->getDataBackFromHandler(net->getData());
}

void Handler::getDataFromDijkstra(QString cur_p, QString start_p, QString data_str) {
    QString str_to_send = "dijkstra";
    str_to_send.append("&");
    str_to_send.append(data_str);
    str_to_send.append(" ");
    str_to_send.append("&");
    str_to_send.append(cur_p);
    str_to_send.append("&");
    str_to_send.append(start_p);
    str_to_send.append("&");
    qDebug() << str_to_send;
    net->send_to_server(str_to_send);
    qDebug() << "data is = " <<net->getData();
    dijkstra->getDataBackFromHandler(net->getData());
}


void Handler::handle_verify(QString name, QString pass) {
    QString str_to_send = "auth";
    str_to_send.append("&");
    str_to_send.append(name);
    str_to_send.append("&");
    str_to_send.append(pass);
    str_to_send.append("&");
    qDebug() << str_to_send;
    net->send_to_server(str_to_send);
    //this_thread::sleep_for(chrono::milliseconds(1000));
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    qDebug() << "data is = " <<net->getData();
    if (net->getData() == "1") {
        delete authorization;
        openTasksForm();
    } else {
        qDebug() << "введен не правильный логин или пароль";
    }
}


