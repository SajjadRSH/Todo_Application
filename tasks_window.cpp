#include "tasks_window.h"
#include "ui_tasks_window.h"
#include "inputs_of_task.h"
#include "edit_of_task.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

#include "QtWidgets"
#include "QLabel"
#include "QVBoxLayout"

#include "QLineEdit"
#include "QTextEdit"
#include "QTimeEdit"
#include "QCalendarWidget"
#include "QComboBox"
#include "QPushButton"

#include "cstring"
#include "QStyledItemDelegate"
#include <QSqlRecord>
#include "QDate"
#include "QDateEdit"

#include "calender_window.h"
tasks_window::tasks_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tasks_window)
{
    ui->setupUi(this);

    QSqlDatabase database ;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\informations_of_tasks.db");
    database.open();

    ui->topicsearch_lineedit->setPlaceholderText("type here ...");
    ui->topicdelete_lineedit->setPlaceholderText("type here ...");
    ui->destextEditenabledfalse->setReadOnly(true);//bara inke vaqte search taqiiresh ndm

}

tasks_window::~tasks_window()
{
    delete ui;
}

void tasks_window::on_show_taskslist_pushbutton_clicked()
{

    QSqlQuery q;//baraye ertebat ba data basi k bala moarrefi krdm
    q.exec("SELECT * FROM tasks_list");//ghablan goftam kodom file hala migam hamechi az kodom tabele in file (*) :yani hamechi
    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(q);

    ui->taskslist_tableview->setModel(m);


}

void tasks_window::on_add_task_pushbutton_clicked()
{
   inputs_of_task *inputtaskwindow = new inputs_of_task;
   inputtaskwindow->setWindowTitle("Add a new task !");
   inputtaskwindow->resize(1000,800);
   inputtaskwindow->show();
}

void tasks_window::on_search_pushButton_clicked()
{
    QSqlQuery q;//baraye ertebat ba data basi k bala moarrefi krdm
    QString topic;
    topic=ui->topicsearch_lineedit->text();
    q.exec("SELECT Description,Date,Priority,Time FROM tasks_list WHERE Topic= '"+topic+"'");
    if(q.first())
    {
        ui->destextEditenabledfalse->setText(q.value(0).toString());
        ui->label_4->setText(q.value(1).toString());
        ui->label_5->setText(q.value(2).toString());
        ui->label_9->setText(q.value(3).toString());
    }
    else
    {
        ui->destextEditenabledfalse->setText("Note Found!");
        ui->label_4->setText("Not Found!");
        ui->label_5->setText("Not Found!");
    }
}

void tasks_window::on_delete_pushButton_clicked()
{
    QSqlQuery q;//baraye ertebat ba data basi k bala moarrefi krdm
    QString topic;
    topic = ui->topicdelete_lineedit->text();
    q.exec("DELETE FROM tasks_list WHERE Topic= '"+topic+"' ");
}

void tasks_window::on_Edit_pushButton_clicked()
{
    edit_of_task *edittaskwindow = new edit_of_task;
    edittaskwindow->setWindowTitle("Edit a task !");
    edittaskwindow->resize(1000,800);
    edittaskwindow->show();
}

void tasks_window::on_done_pushButton_clicked()
{
    QString topic, done;
    done = "X";
    topic = ui->whichtask_done_topic_lineedit->text();

    QSqlQuery q;//baraye ertebat ba data basi k bala moarrefi krdm
    q.exec("UPDATE tasks_list SET Done='"+done+"'  WHERE Topic='"+topic+"' ");
}

void tasks_window::on_undone_pushButton_clicked()
{
    QString topic, done;
    done = " ";
    topic = ui->whichtask_undone_topic_lineedit->text();

    QSqlQuery q;//baraye ertebat ba data basi k bala moarrefi krdm
    q.exec("UPDATE tasks_list SET Done='"+done+"'  WHERE Topic='"+topic+"' ");

}

void tasks_window::on_gotocalenderwindow_pushButton_clicked()
{
    calender_window *w= new calender_window;
    w->show();
}
