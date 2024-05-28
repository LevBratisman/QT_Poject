#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

namespace Ui
{
    class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:
    /// \brief Вызов слота при нажатии на nextWindowButton
    void on_nextWindowButton_clicked();
    /// \brief Вызов слота при нажатии на backButton
    void on_backButton_clicked();
signals:
    /// \brief Вызов сигнала при нажатии на nextWindowButton
    void backButtonClikedFromAuth();
    /// \brief Вызов сигнала при нажатии на nextWindowButton
    void newxButtonClikedFromAuth();
    /// \brief Вызов сигнала при добавлении нового пользователя
    /// \param name Логин пользователя
    /// \param pass Пароль пользователя
    void newAuth(QString name, QString pass);

private:
    Ui::Authorization *ui;

    QString user_name;
    QString password;
};

#endif // AUTHORIZATION_H
