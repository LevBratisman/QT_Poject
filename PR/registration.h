#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    /// \brief слот, который вызывается при нажатии кнопки назад
    void on_backButton_clicked();
signals:
    /// \brief слот, вызывающийся при нажатии кнопки назад
    void backButtonClikedFromReg();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
