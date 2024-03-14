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
    void on_backButton_clicked();
signals:
    void backButtonClikedFromReg();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
