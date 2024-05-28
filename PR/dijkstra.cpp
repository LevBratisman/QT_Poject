#include "dijkstra.h"
#include "ui_dijkstra.h"

Dijkstra::Dijkstra(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dijkstra)
{
    ui->setupUi(this);
}

Dijkstra::~Dijkstra()
{
    delete ui;
}

void Dijkstra::on_backButton_clicked()
{
    emit backButtonClikedFromDijkstra();
}


void Dijkstra::on_OkButton_clicked()
{
    emit SendDijkstraData(ui->count_of_point->text(), ui->start_point->text(), ui->input->toPlainText());
}

void Dijkstra::getDataBackFromHandler(QString ans) {
    qDebug() << "ans is = " <<ans;
    ui->output->setText(ans);
}
