#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

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
    /// \brief Слот обработки нажатия кнопки авторизации
    void on_pushButton_clicked();
    /// \brief Слот обработки нажатия кнопки регистрации
    void on_regButton_clicked();
    /// \brief Слот обработки нажатия кнопки изменения пароля
    void on_changeFormButton_clicked();

signals:
    /// \brief сигнал, вызывающийся при нажатии кнопки авторизации
    void auth_klick();
    /// \brief сигнал, вызывающийся при нажатии кнопки регистрации
    void reg_klick();
    /// \brief сигнал, вызывающийся при нажатии кнопки изменения пароля
    void change_klick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
