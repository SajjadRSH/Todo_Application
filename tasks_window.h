#ifndef TASKS_WINDOW_H
#define TASKS_WINDOW_H

#include <QWidget>

namespace Ui {
class tasks_window;
}

class tasks_window : public QWidget
{
    Q_OBJECT

public:
    explicit tasks_window(QWidget *parent = nullptr);
    ~tasks_window();

private slots:
    void on_show_taskslist_pushbutton_clicked();

    void on_add_task_pushbutton_clicked();

    void on_search_pushButton_clicked();

    void on_delete_pushButton_clicked();

    void on_Edit_pushButton_clicked();

    void on_done_pushButton_clicked();



    void on_undone_pushButton_clicked();

    void on_gotocalenderwindow_pushButton_clicked();

private:
    Ui::tasks_window *ui;
};

#endif // TASKS_WINDOW_H
