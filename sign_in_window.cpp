#include "sign_in_window.h"
#include "ui_sign_in_window.h"
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QMessageBox"
#include "QDateEdit"
#include "selection_tasks_calender_window.h"

sign_in_window::sign_in_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_in_window)
{
    setWindowTitle("Sign In");
    setMinimumSize(900,900);
    setMaximumSize(900,900);
    ui->setupUi(this);
    ui->wlc_label->setText("Welcome to <b>ToDo</b> Application!");
    ui->wlc_label->setGeometry(395,100,200,16);
    ui->wlc_label->setFrameStyle(QFrame::Panel);
    ui->wlc_label->setIndent(7);

    ui->username_label->setText("<b>Username:</b>");
    ui->username_label->setGeometry(60,80,80,16);

    ui->password_label->setText("<b>Password:</b>");
    ui->password_label->setGeometry(60,130,80,16);

    ui->username_lineedit->setGeometry(130,80,221,22);
    ui->username_lineedit->setPlaceholderText("Enter your username...");
    ui->username_lineedit->setStyleSheet("color:purple;background-color:white;selection-background-color:black");

    ui->password_lineedit->setGeometry(130,120,221,22);
    ui->password_lineedit->setPlaceholderText("Enter your password...");
    ui->password_lineedit->setStyleSheet("color:purple;background-color:white;selection-background-color:black");
    ui->password_lineedit->setEchoMode(QLineEdit::Password);//ke baqal dastim passwordi k mixanam nabine

    ui->login_pushbutton->setText("Log In");
    ui->login_pushbutton->setGeometry(180,190,93,28);
    ui->login_pushbutton->setToolTip("click here to enter the Application!");
    ui->login_pushbutton->setCursor(Qt::PointingHandCursor);
    ui->login_pushbutton->setStyleSheet("color:black;background-color:yellow");


    ui->forgetusername_pushbutton->setText("Forget your username?");
    ui->forgetusername_pushbutton->setGeometry(70,260,150,28);
    ui->forgetusername_pushbutton->setCursor(Qt::PointingHandCursor);
    ui->forgetusername_pushbutton->setStyleSheet("color:yellow;background-color:gray");

    ui->forgetpassword_pushbutton->setText("Forget your password?");
    ui->forgetpassword_pushbutton->setGeometry(260,260,150,28);
    ui->forgetpassword_pushbutton->setCursor(Qt::PointingHandCursor);
    ui->forgetpassword_pushbutton->setStyleSheet("color:yellow;background-color:gray");

    QString currentdate = QDate::currentDate().toString();
    QLabel *currentdate_on_statusbar_label = new QLabel(currentdate,this);
    ui->statusBar->addWidget(currentdate_on_statusbar_label);

}

sign_in_window::~sign_in_window()
{
    delete ui;
}

void sign_in_window::on_forgetusername_pushbutton_clicked()
{
    QMessageBox::information(this,"Forget username","your username is your fullname without space and all with small letters!");
}

void sign_in_window::on_forgetpassword_pushbutton_clicked()
{
    QMessageBox::information(this,"Forget password","your password is your student number!");
}

void sign_in_window::on_login_pushbutton_clicked()
{
    QString u,p;
    u=ui->username_lineedit->text();
    p=ui->password_lineedit->text();
    if(u=="elahehmolaei" && p=="4001262728")
    {
        selection_tasks_calender_window *selection_tc_window = new selection_tasks_calender_window;
        selection_tc_window->resize(1000,900);
        selection_tc_window->setWindowTitle("Selection between Tasks and Calender!");
        //safhe sign in baste she ->toye form in karo kardam ba icone edit signals and slots o click(signal) o close(slot)
        selection_tc_window->show();
        //bad ke safe selection baz shod safe sign in baste mishe k in karo toye form be komake siganl slot kardam
    }
    else
    {
        QMessageBox::information(this,"incorrect information",
                                 "The information you've entered is wrong! "
                                 "if you've forgotten your username/password , please click on:"
                                 "<ul>"
                                 "<li>Forget your username?</li>"
                                 "<li>Forget your password?</li>"
                                 "</ul>");
    }
}

void sign_in_window::on_rememberme_pushButton_clicked()
{
    selection_tasks_calender_window *selection_tc_window = new selection_tasks_calender_window;
    selection_tc_window->resize(1000,900);
    selection_tc_window->setWindowTitle("Selection between Tasks and Calender!");
    selection_tc_window->show();
}
