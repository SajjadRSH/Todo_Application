#include "inputs_of_task.h"
#include "ui_inputs_of_task.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QComboBox"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QWidget"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QHeaderView"
#include "QPushButton"
#include "selectyearmonth_toshowcalender_window.h"
inputs_of_task::inputs_of_task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputs_of_task)
{
    ui->setupUi(this);
    ui->topic_lineedit->setPlaceholderText("type the topic of this task ...");
    ui->description_textedit->setPlaceholderText("type the description of this task ...");
    ui->settime_lineedit->setInputMask("00:00:00");

    QStringList prioritylist = (QStringList() <<"Top priority"<<"Medium priority"<<"Low priority");
    ui->priority_combobox->addItems(prioritylist);
    ui->label->setStyleSheet("color:white;background-color:black");


    QSqlDatabase database ;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\informations_of_tasks.db");
    database.open();
}

inputs_of_task::~inputs_of_task()
{
    delete ui;
}

void inputs_of_task::on_save_pushbutton_clicked()
{
    QSqlQuery q;

    QString s1,s2,s3,s4,s5;
    s1=ui->topic_lineedit->text();
    s2=ui->description_textedit->toPlainText();//chetori be matnesh dasresi dshte bshm?
    //s3=ui->settaskdate_calendarwidget->selectedDate().toString();   //bayad yejori byam oon date k az taghvim entekhab shde connect knm
    //s3= //new calender i've made
    s4=ui->priority_combobox->currentText();    //chetori b entekhabam dastresi dashte bshm?
    s5=ui->settime_lineedit->text();

    q.exec("INSERT INTO tasks_list(Topic,Description,Date,Priority,Time)VALUES('"+s1+"', '"+s2+"', '"+s3+"', '"+s4+"', '"+s5+"')");

    //how to upsert? ostad goft ino ignore konid feln
    //q.exec("INSERT INTO tasks_list(Topic,Description,Date,Priority,Time)VALUES('"+s1+"', '"+s2+"', '"+s3+"', '"+s4+"', '"+s5+"')ON CONFLICT(Topic)DO NOTHING;");//UPDATE SET Description= '"+s2+"', Date= '"+s3+"', Priority= '"+s4+"', Time= '"+s5+"'

}



void inputs_of_task::on_show_calender_pushButton_clicked()
{
    SelectYearMonth_toshowcalender_window *symw = new SelectYearMonth_toshowcalender_window;
    symw->setWindowTitle("Select year and month to show the calender !");
    symw->show();
}
