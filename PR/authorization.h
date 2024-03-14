#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:
    void on_nextWindowButton_clicked();
    void on_backButton_clicked();

signals:
    void backButtonClikedFromAuth();
    void newxButtonClikedFromAuth();
private:
    Ui::Authorization *ui;

    QString user_name;
    QString password;
};

#endif // AUTHORIZATION_H
