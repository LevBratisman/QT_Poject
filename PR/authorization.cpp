#include "authorization.h"
#include "ui_authorization.h"


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
    emit newAuth(ui->user_name->text(), ui->password->text());
}


void Authorization::on_backButton_clicked()
{
    emit backButtonClikedFromAuth();
}

