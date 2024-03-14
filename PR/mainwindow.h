#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_regButton_clicked();

    void on_changeFormButton_clicked();

signals:
    void auth_klick();
    void reg_klick();
    void change_klick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
