#ifndef TASKS_H
#define TASKS_H

#include <QWidget>

namespace Ui
{
    class Tasks;
}

class Tasks : public QWidget
{
    Q_OBJECT

public:
    explicit Tasks(QWidget *parent = nullptr);
    ~Tasks();

private slots:
    /// \brief Слот обработки нажатия кнопки для открытия задачи 'Алгоритм Дейкстры'
    void on_OpenDijkstraButton_clicked();
    /// \brief Вернуться в главное меню
    void on_pushBackButton_clicked();
    void on_BiButton_clicked();

signals:
    /// \brief Сигнал обработки нажатия кнопки для открытия задачи 'Алгоритм Дейкстры'
    void OpenDijkstraButtonClickedFromTasks();
    /// \brief Вернуться в главное меню из меню задач
    void backButtonClikedFromTasks();

    void OpenBiButtonClickedFromTasks();

private:
    Ui::Tasks *ui;
};

#endif // TASKS_H
