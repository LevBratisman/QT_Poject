#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QWidget>

namespace Ui {
class Dijkstra;
}

class Dijkstra : public QWidget
{
    Q_OBJECT

public:
    explicit Dijkstra(QWidget *parent = nullptr);
    ~Dijkstra();

    void getDataBackFromHandler(QString ans);
private slots:
    void on_backButton_clicked();

    void on_OkButton_clicked();

signals:
    void SendDijkstraData(QString cur_p, QString start_p, QString data_str);
    void backButtonClikedFromDijkstra();
private:
    Ui::Dijkstra *ui;
};

#endif // DIJKSTRA_H
