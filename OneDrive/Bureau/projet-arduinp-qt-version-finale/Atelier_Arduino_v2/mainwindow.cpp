#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <chrono>
#include <ctime>

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{
    delete ui;
}





QSqlQueryModel* MainWindow::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM POINTAGE");


    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
     model ->setHeaderData(1, Qt::Horizontal ,QObject::tr("id_p"));
      model ->setHeaderData(2, Qt::Horizontal ,QObject::tr("date_time_p"));




    return model;
}









void MainWindow::ajouter(QString nom, QString id_p, QString date  )
{
    QSqlQuery query;
   // QString id_string=QString::number(id);

         query.prepare("INSERT INTO POINTAGE (NOM, ID_P,DATE_TIME_P ) "
                       "VALUES (:nom, :id_p, :date)");

         query.bindValue(":nom", nom);
         query.bindValue(":id_p", id_p);
         query.bindValue(":date", date);





          query.exec();
}

void MainWindow::update_label()
{
    char       d1[80];
    //lire a partir arduino
    data=A.read_from_arduino();
     qDebug() << data;

     time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
        // for more information about date/time format
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);


    if(data=="1")
    {
A.write_to_arduino("1");
        ui->label_3->setText("Welcome Ali"); // si les données reçues de arduino via la liaison série sont égales à 1
    ajouter("ali", "1", buf);

    }
    // alors afficher ON
   else  if(data=="2")
{
        A.write_to_arduino("2");

        ui->label_3->setText("Welcome Fatma"); // si les données reçues de arduino via la liaison série sont égales à 2
    ajouter("FATMA", "2", buf);
}
    else  if(data=="3")
{
        A.write_to_arduino("3");

         ui->label_3->setText("Welcome nour");//si les données reçues de arduino via la liaison série sont égales à 3
    ajouter("nour", "3", buf);
    }
    else  if(data=="4")
{
        A.write_to_arduino("4");

         ui->label_3->setText("Welcome haithem");//si les données reçues de arduino via la liaison série sont égales à 4
ajouter("haithem", "4", buf);
    }
    else  if(data=="5")
{
        A.write_to_arduino("5");

         ui->label_3->setText("Welcome rahma");//si les données reçues de arduino via la liaison série sont égales à 5
ajouter("rahma", "5", buf);
    }

    else 

        ui->label_3->setText("wrong password");   // si les données reçues de arduino via la liaison série sont égales à 0

    ui->tableView->setModel(afficher());
}




void MainWindow::on_pushButton_clicked()
{
     ui->tableView->setModel(afficher());
}
