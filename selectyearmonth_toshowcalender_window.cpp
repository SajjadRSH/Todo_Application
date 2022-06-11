#include "selectyearmonth_toshowcalender_window.h"
#include "ui_selectyearmonth_toshowcalender_window.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QSpinBox"
#include "QPushButton"
#include "QLabel"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QHeaderView"
#include "cmath"
#include "QTableWidgetItem"
#include "QDate"
#include "QMessageBox"
#include <QSqlRecord>
#include "QDate"
#include "QDateEdit"
SelectYearMonth_toshowcalender_window::SelectYearMonth_toshowcalender_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectYearMonth_toshowcalender_window)
{
    ui->setupUi(this);
    ui->year_number_spinBox->setMaximum(3000);
    ui->year_number_spinBox->setMinimum(2000);
    QStringList monthslist = (QStringList()
                              <<""
                              <<"January"
                              << "February"
                              << "March"
                              << "April"
                              << "May"
                              << "June"
                              << "July"
                              << "August"
                              << "September"
                              << "October"
                              << "November"
                              << "December");

    ui->months_comboBox->addItems(monthslist);

    ui->calendertable->setColumnCount(7);
    ui->calendertable->setRowCount(7);


    ui->calendertable->setHorizontalHeaderItem(0,new QTableWidgetItem("Monday"));
    ui->calendertable->setHorizontalHeaderItem(1,new QTableWidgetItem("Tuesday"));
    ui->calendertable->setHorizontalHeaderItem(2,new QTableWidgetItem("Wednesday"));
    ui->calendertable->setHorizontalHeaderItem(3,new QTableWidgetItem("Thursday"));
    ui->calendertable->setHorizontalHeaderItem(4,new QTableWidgetItem("Friday"));
    ui->calendertable->setHorizontalHeaderItem(5,new QTableWidgetItem("Saturday"));
    ui->calendertable->setHorizontalHeaderItem(6,new QTableWidgetItem("Sunday"));

    ui->calendertable->setColumnWidth(0,130);
    ui->calendertable->setColumnWidth(1,130);
    ui->calendertable->setColumnWidth(2,130);
    ui->calendertable->setColumnWidth(3,130);
    ui->calendertable->setColumnWidth(4,130);
    ui->calendertable->setColumnWidth(5,130);
    ui->calendertable->setColumnWidth(6,130);

    ui->calendertable->verticalHeader()->setVisible(false);// dar on_showcalender_pushbutton_clicked() hamchenan false mimone
    ui->calendertable->horizontalHeader()->setVisible(false);//dar on_showcalender_pushbutton_clicked() true kon

    //==============neveshtane tabei baraye tashkhise avalin ruzee sal




    //hala set kardan adad 1 ta 30 dar item haye jadval



    for(int i=0; i<7; i++) //i shomarande radif
        ui->calendertable->hideRow(i);
    for(int j=0; j<7; j++)
        ui->calendertable->hideColumn(j);


    QSqlDatabase database ;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\informations_of_tasks.db");
    database.open();
}

SelectYearMonth_toshowcalender_window::~SelectYearMonth_toshowcalender_window()
{
    delete ui;
}




void SelectYearMonth_toshowcalender_window::on_showcalender_pushbutton_clicked()
{


   //////////////////////////////////////////////////////////////kod gozari mah ha baraye estefade dar zellersAlgorithm
    int month;
    month=0;
    if(ui->months_comboBox->currentText()=="January")
        month=1;
    else if(ui->months_comboBox->currentText()=="February")
        month=2;
    else if(ui->months_comboBox->currentText()=="March")
        month=3;
    else if(ui->months_comboBox->currentText()=="April")
        month=4;
    else if(ui->months_comboBox->currentText()=="May")
        month=5;
    else if(ui->months_comboBox->currentText()=="June")
        month=6;
    else if(ui->months_comboBox->currentText()=="July")
        month=7;
    else if(ui->months_comboBox->currentText()=="August")
        month=8;
    else if(ui->months_comboBox->currentText()=="September")
        month=9;
    else if(ui->months_comboBox->currentText()=="October")
        month=10;
    else if(ui->months_comboBox->currentText()=="November")
        month=11;
    else if(ui->months_comboBox->currentText()=="December")
        month=12;
    /////////////////////////////////////////////////////////////////////////////////
     bool x = is_leap_year_miladi(ui->year_number_spinBox->value());
       int day = 1;
       QString r = zellersAlgorithm(day, month, ui->year_number_spinBox->value());
       int col = which_col_weekday(r);

       QString maheentekhabi = ui->months_comboBox->currentText();
       set_items_of_the_table_widget(x,col,maheentekhabi);

    ui->calendertable->horizontalHeader()->setVisible(true);
    for(int i=0; i<7; i++) //i shomarande radif
        ui->calendertable->showRow(i);
    for(int j=0; j<7; j++)
        ui->calendertable->showColumn(j);
}

void SelectYearMonth_toshowcalender_window::on_ok_pushButton_clicked()
{

    if(ui->topic_lineEdit->text()=="")
    {
        QMessageBox ::warning(this,"WARNING", "pleas enter the topic!");
    }
    /*else if(ui->calendertable->isItemSelected()==false)
    {
        QMessageBox::warning(this,"WARNING","pleas select the day in the calender !");
    }*/
    else {
        //Thu Jun 9 2022 = s5 = s1 + s2 + s3 + s4
        //farakhani tabei k tashkhis bede oon item entekhab shde male che roozie
        int c = ui->calendertable->currentColumn();
        QString s1 = which_weekday_col(c); //weekday text
        QString s2 = ui->months_comboBox->currentText(); //month text
        QString s3 = ui->calendertable->currentItem()->text();//day : integer
        //int d =  ui->calendertable->currentItem()->text().toInt();
        QString s4 = QString::number(ui->year_number_spinBox->value()); //year integer
        //int y = ui->year_number_spinBox->value();
        QString space = " ";
        QString s5 = s1+space+s2+space+s3+space+s4;
        //update database filde Date
        QString topic = ui->topic_lineEdit->text();
        QSqlQuery q;
        q.exec("UPDATE tasks_list SET  Date= '"+s5+"' , Weekday = '"+s1+"', Month='"+s2+"', Day='"+s3+"' , Year='"+s4+"'  WHERE Topic='"+topic+"'");


    }

}


bool SelectYearMonth_toshowcalender_window::is_leap_year_miladi(int year) //tabei k mige sal kabisas ya na
{
    if((year-2000)%4==0)
        return true;

    else
        return false;
}

QString SelectYearMonth_toshowcalender_window::zellersAlgorithm(int day, int month, int year)
{
    QString weekday[7] = {"Saturday","Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday"};
    int mon;
    if(month > 2)
        mon = month; //for march to december month code is same as month
    else{
            mon = (12+month); //for Jan and Feb, month code will be 13 and 14
            year--; //decrease year for month Jan and Feb
       }
    int y = year % 100; //last two digit
    int c = year / 100; //first two digit
    int w = (day + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
    w = w % 7;
    return weekday[w];
}

int SelectYearMonth_toshowcalender_window::which_col_weekday(QString r) //tabei k bege r yani sotone chand az oon table widget
{
    if(r=="Monday")
        return 0;
    else if(r=="Tuesday")
        return 1;
    else if(r=="Wednesday")
        return 2;
    else if(r=="Thursday")
        return 3;
    else if(r=="Friday")
        return 4;
    else if(r=="Saturday")
        return 5;
    else if(r=="Sunday")
        return 6;
}

QString SelectYearMonth_toshowcalender_window::which_weekday_col(int c)
{
    if(c==0)      return "Monday";
    else if(c==1) return "Tuesday";
    else if(c==2) return "Wednesday";
    else if(c==3) return "Thursday";
    else if(c==4) return "Friday";
    else if(c==5) return "Saturday";
    else if(c==6) return "Sunday";

}

void SelectYearMonth_toshowcalender_window::set_items_of_the_table_widget(bool x, int col, QString maheentekhabi)
{
    int chandrooze ;
    if(x==true)//sal kabise ast
    {
        if(maheentekhabi=="January")
            chandrooze=31;
        else if(maheentekhabi=="February")
            chandrooze=29; //chon sale kabisas
        else if(maheentekhabi=="March")
            chandrooze=31;
        else if(maheentekhabi=="April")
            chandrooze=30;
        else if(maheentekhabi=="May")
            chandrooze=31;
        else if(maheentekhabi=="June")
            chandrooze=30;
        else if(maheentekhabi=="July")
            chandrooze=31;
        else if(maheentekhabi=="August")
            chandrooze=31;
        else if(maheentekhabi=="September")
            chandrooze=30;
        else if(maheentekhabi=="October")
            chandrooze=31;
        else if(maheentekhabi=="November")
            chandrooze=30;
        else if(maheentekhabi=="December")
            chandrooze=31;
    }
    else if(x==false)//sal kabise nist
    {
        if(maheentekhabi=="January")
            chandrooze=31;
        else if(maheentekhabi=="February")
            chandrooze=28; //chon sale kabise nis
        else if(maheentekhabi=="March")
            chandrooze=31;
        else if(maheentekhabi=="April")
            chandrooze=30;
        else if(maheentekhabi=="May")
            chandrooze=31;
        else if(maheentekhabi=="June")
            chandrooze=30;
        else if(maheentekhabi=="July")
            chandrooze=31;
        else if(maheentekhabi=="August")
            chandrooze=31;
        else if(maheentekhabi=="September")
            chandrooze=30;
        else if(maheentekhabi=="October")
            chandrooze=31;
        else if(maheentekhabi=="November")
            chandrooze=30;
        else if(maheentekhabi=="December")
            chandrooze=31;
    }
    int k=1;
    QString ks;
    QString resetspace =" ";
    int j;
    //aval item haye jadval delete badan  ijad

    for(int i=0; i<7; i++)
    {
         for(int j=0; j<7; j++)
         {
             QTableWidgetItem *item = ui->calendertable->item(i, j);

             item = new QTableWidgetItem();
             ui->calendertable->setItem(i, j, item);

            item->setText(resetspace);
         }
    }



    for (int i=0, p=0; i<7 && p<chandrooze; i++) //i shomarande satr .... p shomarande tedad rooza k age mah 30 roozas nayad 31 ta tanzim kne
    {
        for(j=col; j<7&&p<chandrooze; j++,p++)
        {
           ks=QString::number(k);
            QTableWidgetItem *item = ui->calendertable->item(i, j);

           item = new QTableWidgetItem();
           ui->calendertable->setItem(i, j, item);

           item->setText(ks);
            k++;
        }
        col=0;
    }

}







