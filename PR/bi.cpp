#include "bi.h"
#include "ui_bi.h"

Bi::Bi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Bi)
{
    ui->setupUi(this);
}

Bi::~Bi()
{
    delete ui;
}

void Bi::on_OkButton_clicked()
{
    emit SendDataFromBi(ui->input_a->text(), ui->input_b->text(), ui->input_c->text());
}

void Bi::getDataBackFromHandler(QString data) {
    qDebug() << "ans is = " << data;
    if(data == "0") {
        ui->output->setText("Нет вещественных корней или метод бисекции не может быть применен");
    } else {
        ui->output->setText(data);
    }
}

void Bi::on_BackButtonFromBi_clicked()
{
    emit backButtonClikedFromBi();
}

