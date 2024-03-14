#include "changeform.h"
#include "ui_changeform.h"

ChangeForm::ChangeForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeForm)
{
    ui->setupUi(this);
}

ChangeForm::~ChangeForm()
{
    delete ui;
}


void ChangeForm::on_backButton_clicked()
{
    emit backButtonClikedFromChange();
}

