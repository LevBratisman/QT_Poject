#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QWidget>

namespace Ui
{
    class Dijkstra;
}

class Dijkstra : public QWidget
{
    Q_OBJECT

public:
    explicit Dijkstra(QWidget *parent = nullptr);
    ~Dijkstra();
    /// \brief Получение результата от сервера
    /// \param ans
    void getDataBackFromHandler(QString ans);
private slots:
    void on_backButton_clicked();

    void on_OkButton_clicked();

signals:
    /// \brief Отправка данных на сервер
    /// \param cur_p Текущая позиция
    /// \param start_p Начальная позиция
    /// \param data_str Данные
    void SendDijkstraData(QString cur_p, QString start_p, QString data_str);
    /// \brief Вернуться в главное меню
    void backButtonClikedFromDijkstra();

private:
    Ui::Dijkstra *ui;
};

#endif // DIJKSTRA_H
