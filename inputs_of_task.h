#ifndef INPUTS_OF_TASK_H
#define INPUTS_OF_TASK_H

#include <QWidget>

namespace Ui {
class inputs_of_task;
}

class inputs_of_task : public QWidget
{
    Q_OBJECT

public:
    explicit inputs_of_task(QWidget *parent = nullptr);
    ~inputs_of_task();

private slots:
    void on_save_pushbutton_clicked();

    //void on_show_calender_pushButton_clicked();

    void on_show_calender_pushButton_clicked();

private:
    Ui::inputs_of_task *ui;
};

#endif // INPUTS_OF_TASK_H
