#ifndef SELECTYEARMONTH_TOSHOWCALENDER_WINDOW_H
#define SELECTYEARMONTH_TOSHOWCALENDER_WINDOW_H

#include <QWidget>
#include "QString"
#include "cstring"
namespace Ui {
class SelectYearMonth_toshowcalender_window;
}

class SelectYearMonth_toshowcalender_window : public QWidget
{
    Q_OBJECT

public:
    explicit SelectYearMonth_toshowcalender_window(QWidget *parent = nullptr);
    ~SelectYearMonth_toshowcalender_window();

private slots:
    void on_showcalender_pushbutton_clicked();

    void on_ok_pushButton_clicked();

private:
    Ui::SelectYearMonth_toshowcalender_window *ui;
    bool is_leap_year_miladi(int year);
    QString zellersAlgorithm(int day, int month, int year);
    int which_col_weekday(QString r);
    QString which_weekday_col(int c);
    void set_items_of_the_table_widget(bool x, int col, QString maheentekhabi);
};

#endif // SELECTYEARMONTH_TOSHOWCALENDER_WINDOW_H
