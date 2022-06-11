#ifndef SELECTION_TASKS_CALENDER_WINDOW_H
#define SELECTION_TASKS_CALENDER_WINDOW_H

#include <QWidget>

namespace Ui {
class selection_tasks_calender_window;
}

class selection_tasks_calender_window : public QWidget
{
    Q_OBJECT

public:
    explicit selection_tasks_calender_window(QWidget *parent = nullptr);
    ~selection_tasks_calender_window();

private slots:
    void on_tasks_pushbutton_clicked();

    void on_calender_pushbutton_clicked();

private:
    Ui::selection_tasks_calender_window *ui;
};

#endif // SELECTION_TASKS_CALENDER_WINDOW_H
