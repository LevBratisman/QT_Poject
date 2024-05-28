#ifndef BI_H
#define BI_H

#include <QWidget>

namespace Ui
{
    class Bi;
}

class Bi : public QWidget
{
    Q_OBJECT

public:
    explicit Bi(QWidget *parent = nullptr);
    ~Bi();
    /// \brief Получение результата от сервера
    /// \param data
    void getDataBackFromHandler(QString data);

private slots:
    void on_OkButton_clicked();

    void on_BackButtonFromBi_clicked();

signals:
    /// \brief Отправка данных(аргументов функции) на сервер
    void SendDataFromBi(QString a, QString b, QString c);
    /// \brief Вернуться в главное меню
    void backButtonClikedFromBi();

private:
    Ui::Bi *ui;
};

#endif // BI_H
