#ifndef SIGN_IN_WINDOW_H
#define SIGN_IN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class sign_in_window;
}

class sign_in_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_in_window(QWidget *parent = nullptr);
    ~sign_in_window();

private slots:
    void on_forgetusername_pushbutton_clicked();

    void on_forgetpassword_pushbutton_clicked();

    void on_login_pushbutton_clicked();

    void on_rememberme_pushButton_clicked();

private:
    Ui::sign_in_window *ui;
};

#endif // SIGN_IN_WINDOW_H
