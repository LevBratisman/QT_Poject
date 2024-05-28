#ifndef CHANGEFORM_H
#define CHANGEFORM_H

#include <QWidget>

namespace Ui
{
    class ChangeForm;
}

class ChangeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeForm(QWidget *parent = nullptr);
    ~ChangeForm();

private slots:
    /// \brief Вызов при нажатии backButton
    void on_backButton_clicked();

signals:
    /// \brief Вызов сигнала при нажатии на backButton
    void backButtonClikedFromChange();

private:
    Ui::ChangeForm *ui;
};

#endif // CHANGEFORM_H
