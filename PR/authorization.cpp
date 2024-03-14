#include "authorization.h"
#include "ui_authorization.h"
#include <QMessageBox>

Authorization::Authorization(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Authorization)
{
    ui->setupUi(this);

    user_name = "name";
    password = "123";
}

Authorization::~Authorization()
{
    delete ui;
}


void Authorization::on_nextWindowButton_clicked()
{
    if ((ui->user_name->text() == this->user_name) && (ui->password->text() == this->password)) {
        emit newxButtonClikedFromAuth();
    } else {
        QMessageBox::warning(this, "вход", "введен не правильный логин или пароль");
    }
}


void Authorization::on_backButton_clicked()
{
    emit backButtonClikedFromAuth();
}

