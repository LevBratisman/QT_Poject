#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    emit auth_klick();
}


void MainWindow::on_regButton_clicked()
{
    emit reg_klick();
}


void MainWindow::on_changeFormButton_clicked()
{
    emit change_klick();
}

