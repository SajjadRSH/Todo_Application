#ifndef EDIT_OF_TASK_H
#define EDIT_OF_TASK_H

#include <QWidget>

namespace Ui {
class edit_of_task;
}

class edit_of_task : public QWidget
{
    Q_OBJECT

public:
    explicit edit_of_task(QWidget *parent = nullptr);
    ~edit_of_task();

private slots:
    void on_allowedit_pushbutton_clicked();

    //void on_show_calender_pushButton_clicked();

    void on_show_calender_pushButton_clicked();

private:
    Ui::edit_of_task *ui;
};

#endif // EDIT_OF_TASK_H
