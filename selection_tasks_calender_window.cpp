#include "selection_tasks_calender_window.h"
#include "ui_selection_tasks_calender_window.h"
#include "QLabel"
#include "QPushButton"
#include "tasks_window.h"
#include "calender_window.h"
selection_tasks_calender_window::selection_tasks_calender_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selection_tasks_calender_window)
{
    ui->setupUi(this);
    ui->tasks_pushbutton->setText("Tasks");
    ui->tasks_pushbutton->setGeometry(310,250,161,51);
    ui->tasks_pushbutton->setToolTip("if you click here, you'll see your tasks information list!");
    ui->tasks_pushbutton->setCursor(Qt::PointingHandCursor);
    ui->tasks_pushbutton->setStyleSheet("color:black;background-color:blue");

    ui->calender_pushbutton->setText("Calender");
    ui->calender_pushbutton->setGeometry(540,250,161,51);
    ui->calender_pushbutton->setToolTip("if you click here, you'll see your works calender!");
    ui->calender_pushbutton->setCursor(Qt::PointingHandCursor);
    ui->calender_pushbutton->setStyleSheet("color:black;background-color:blue");


    ui->choosing_label->setText("choose one :");
    ui->choosing_label->setGeometry(400,170,221,20);
    ui->choosing_label->setFrameStyle(QFrame::Panel|QFrame::Raised);
    ui->choosing_label->setStyleSheet("color:white;background-color:black");
    ui->choosing_label->setIndent(60);
}

selection_tasks_calender_window::~selection_tasks_calender_window()
{
    delete ui;
}

void selection_tasks_calender_window::on_tasks_pushbutton_clicked()
{
    tasks_window *taskwindow = new tasks_window;
    taskwindow->resize(1500,700);
    taskwindow->setWindowTitle("Tasks");
    //?
    taskwindow->show();
}

void selection_tasks_calender_window::on_calender_pushbutton_clicked()
{
    calender_window *calenderwindow = new calender_window;
    calenderwindow->resize(1500,700);
    calenderwindow->setWindowTitle("Calender");
    //safhe selection baste she
    calenderwindow->show();
}
