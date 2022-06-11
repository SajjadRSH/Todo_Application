#ifndef CALENDER_WINDOW_H
#define CALENDER_WINDOW_H

#include <QWidget>

namespace Ui {
class calender_window;
}

class calender_window : public QWidget
{
    Q_OBJECT

public:
    explicit calender_window(QWidget *parent = nullptr);
    ~calender_window();

private slots:
    void on_showcalender_pushbutton_clicked();

    void on_show_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::calender_window *ui;
    bool is_leap_year_miladi(int year);
    QString zellersAlgorithm(int day, int month, int year);
    int which_col_weekday(QString r);
    QString which_weekday_col(int c);
    void set_items_of_the_table_widget(bool x, int col, QString maheentekhabi);
};

#endif // CALENDER_WINDOW_H
