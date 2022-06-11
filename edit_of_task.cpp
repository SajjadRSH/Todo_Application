#include "edit_of_task.h"
#include "ui_edit_of_task.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QComboBox"
#include "QWidget"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QHeaderView"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QGridLayout"
#include "selectyearmonth_toshowcalender_window.h"
edit_of_task::edit_of_task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_of_task)
{
    ui->setupUi(this);
    ui->edittopic_lineedit->setPlaceholderText("type the topic to edit the topic of this task ...");
    ui->editdescription_textedit->setPlaceholderText("type the Description to edit the Description of this task ...");
    ui->edittime_lineedit->setInputMask("00:00:00");

    QStringList prioritylist = (QStringList() <<""<<"Top priority"<<"Medium priority"<<"Low priority");
    ui->editpriority_combobox->addItems(prioritylist);

    QSqlDatabase database ;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\informations_of_tasks.db");
    database.open();

}

edit_of_task::~edit_of_task()
{
    delete ui;
}

void edit_of_task::on_allowedit_pushbutton_clicked()
{

    QString topic;
    topic = ui->whichtopic_lineEdit->text();
    QString s1,s2,s3,s4,s5;
    QSqlQuery q;//,w,e,r,t;

    if(ui->edittopic_lineedit->text()=="")
    {
        q.exec("SELECT Topic FROM tasks_list WHERE Topic= '"+topic+"'");
        if(q.first())
        {
            s1=(q.value(0).toString());
        }
    }
    else
    {
        s1=ui->edittopic_lineedit->text();
    }

    /////////////////////////////////////////////////////////

    if(ui->editdescription_textedit->toPlainText()=="")
    {
        q.exec("SELECT Description FROM tasks_list WHERE Topic= '"+topic+"'");
        if(q.first())
        {
            s2=(q.value(0).toString());
        }
    }
    else
    {
        s2=ui->editdescription_textedit->toPlainText();
    }

    /////////////////////////////////////////////////////////

    /*if(ui->edittaskdate_calendarwidget->selectedDate().toString()=="") //***************after creating calender come here and ..(:
    {
        q.exec("SELECT Date FROM tasks_list WHERE Topic= '"+topic+"'");
        if(q.first())
        {
            s3=(q.value(0).toString());
        }
    }
    else
    {
        s3=ui->edittaskdate_calendarwidget->selectedDate().toString();
    }*/

    /////////////////////////////////////////////////////////


    if(ui->editpriority_combobox->currentText()=="")
    {
        q.exec("SELECT Priority FROM tasks_list WHERE Topic= '"+topic+"'");
        if(q.first())
        {
            s4=(q.value(0).toString());
        }
    }
    else
    {
        s4=ui->editpriority_combobox->currentText();
    }

    /////////////////////////////////////////////////////////

    if(ui->edittime_lineedit->text()=="::")
    {
        q.exec("SELECT Time FROM tasks_list WHERE Topic= '"+topic+"'");
        if(q.first())
        {
            s5=(q.value(0).toString());
        }
    }
    else
    {
        s5=ui->edittime_lineedit->text();
    }


    /////////////////////////////////////////////////////////

    /*s2=ui->editdescription_textedit->toPlainText();//chetori be matnesh dasresi dshte bshm?
    s3=ui->edittaskdate_calendarwidget->selectedDate().toString();   //bayad yejori byam oon date k az taghvim entekhab shde connect knm
    s4=ui->editpriority_combobox->currentText();
    s5=ui->edittime_lineedit->text();*/


    q.exec("UPDATE tasks_list SET Topic= '"+s1+"', Description= '"+s2+"', Date= '"+s3+"', Priority= '"+s4+"', Time= '"+s5+"' WHERE Topic='"+topic+"'");


}

/*void edit_of_task::on_show_calender_pushButton_clicked()
{
    QWidget *calenderr = new QWidget;
    calenderr->setWindowTitle("Calender!");
    calenderr->resize(1500,1000);
    QGridLayout *gl = new QGridLayout;
    QTableWidget *tableWidget = new QTableWidget(6, 7, this);
    tableWidget->resize(950,300);
    tableWidget->setGeometry(300,300,950,300);
    //tableWidget->setItem(0,0,new QTableWidgetItem("Saturday"));
    tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Saturday"));
    tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Sunday"));
    tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Monday"));
    tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Tuesday"));
    tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Wednesday"));
    tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem("Thursday"));
    tableWidget->setHorizontalHeaderItem(6,new QTableWidgetItem("Friday"));

    tableWidget->setColumnWidth(0,130);
    tableWidget->setColumnWidth(1,130);
    tableWidget->setColumnWidth(2,130);
    tableWidget->setColumnWidth(3,130);
    tableWidget->setColumnWidth(4,130);
    tableWidget->setColumnWidth(5,130);
    tableWidget->setColumnWidth(6,130);
    tableWidget->verticalHeader()->setVisible(false);
    gl->addWidget(tableWidget);
    calenderr->setLayout(gl);
    calenderr->show();

    //tableWidget->setItem(0,1,new QTableWidgetItem("  "));
}*/

void edit_of_task::on_show_calender_pushButton_clicked()
{

    SelectYearMonth_toshowcalender_window *symw = new SelectYearMonth_toshowcalender_window;
    symw->setWindowTitle("Select year and month to show the calender !");
    symw->show();
}
