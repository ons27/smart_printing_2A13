#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "smtp.h"
#include "employee.h"
#include"conge.h"
#include "equipements.h"
#include "interventions.h"
#include "fournisseurs.h"
#include <QMessageBox>
#include<QSystemTrayIcon>
#include <QRegExp>
#include <QSqlQueryModel>
#include "connection.h"
#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include "qrcode.h"
#include <QChartView>
#include <QPieSlice>
#include <QPieSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>
#include "commandes.h"
using namespace QtCharts;
using namespace qrcodegen;
using namespace std;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(5);
    this->ui->stackedWidget_7->setCurrentIndex(0);


    ui->table->setModel(e.afficher());
    ui->table_3->setModel(cc.afficher());
    ui->table_6->setModel(cs.afficher());
     //ui->table->setModel(f.afficher());

    QRegExp rx("[a-zA-Z,@,.]+");
    QValidator *validatior = new
            QRegExpValidator (rx ,this) ;
    this->ui->stackedWidget_5->setCurrentIndex(0);
    ui->table_14->setModel(i.afficher());
    ui->table_13->setModel(ee.afficher());
    ui->lineEdit->setValidator(validatior);
    ui->lineEdit_5->setValidator(validatior);
    ui->lineEdit_8->setValidator(validatior);
    ui->lineEdit_9->setValidator(validatior);
    ui->lineEdit_3->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_4->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_11->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_12->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_7->setValidator(new QIntValidator(0, 999999,this));

    ui->lineEdit_73->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_79->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_68->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_69->setValidator(new QIntValidator(0, 999999,this));
    // ui->lineEdit_1->setValidator( new QIntValidator(0, 999999, this));
//    ui->lineEdit->setValidator(validator);
//    ui->lineEdit_11->setValidator(validator);
//    ui->lineEdit_2->setValidator(validator);
//    ui->lineEdit_11->setValidator(validator);

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


     int retv=S.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< S.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<S.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(S.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).




    QSqlQuery query;
    QSqlQueryModel *load=new QSqlQueryModel();
    query.prepare("SELECT ID_EQ FROM EQUIPEMENT");
    query.exec();
    load->setQuery(query);
    ui->comboBox_28->setModel(load);
    QSqlQuery qry;
    QSqlQueryModel *looad=new QSqlQueryModel();
    qry.prepare("SELECT ID_EMP FROM EMPLOYES");
    qry.exec();
    looad->setQuery(qry);
    ui->comboBox_29->setModel(looad);
    //input__control
        ui->upd_pri_eq->setValidator(new QIntValidator(0,999999,this));
        ui->lineEdit_114->setValidator(new QIntValidator(0,999999,this));
        QValidator *validator = new
                QRegExpValidator (rx,this);
        ui->lineEdit_12->setValidator(validator);
        ui->lineEdit_13->setValidator(validator);
        ui->upd_nom_eq->setValidator(validator);
        ui->upd_mar_eq->setValidator(validator);
        ee.Signal();
}


MainWindow::~MainWindow()
{
    QSqlQuery query;
    //QString id_string=QString::number(id);
    QString nbr=QString::number(it);

         query.prepare("INSERT INTO arduino (NB_CLIENTS) "
                       "VALUES (:nombre)");
         query.bindValue(":nombre", nbr);

         query.exec();
    delete ui;
}


//**************************CLIENT**********************//////////////////










void MainWindow::update_label()
{
    set=A.read_from_arduino();
    ui->label_129->setNum(it);

    if(set=="1"){
        //wait=1;
        inc=1;
        ui->label_130->setText("Un client est à la porte"); // si les données reçues de arduino via la liaison série sont égales à 1
        // alors afficher UN CLLIENT
        //ui->label_3->setNum(i);
        ui->pushButton_50->setEnabled(true);

     }
    else
    {
     ui->label_130->setText("Pas de client");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher PAS DE CLIENT
     ui->pushButton_50->setEnabled(false);
    }
//    while(inc ){
//        i++;
//        //inc=0;
//    }


}


void MainWindow::on_pushButton_50_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
    it++;
}

void MainWindow::on_HomeBtn_10_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_21_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(1);
}
void MainWindow::on_PdfBtn_26_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(9);
}
void MainWindow::on_PdfBtn_29_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(9);
}
void MainWindow::on_PdfBtn_31_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(9);
}


void MainWindow::on_addeq_21_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_11_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_22_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(1);
}

void MainWindow::on_addeq_22_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_12_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_23_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(1);
}

void MainWindow::on_addeq_23_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_21_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_24_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(1);
}

void MainWindow::on_addeq_24_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(2);
}

//void MainWindow::on_pushButton_2_clicked()
//{
//    ui->stackedWidget_7->setCurrentIndex(0);
//}

void MainWindow::on_LogoutBtn_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_LogoutBtn_25_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(4);
}
void MainWindow::on_buttonBox_7_accepted()
{
    QString nom =ui->lineEdit_75->text();
    QString prenom =ui->lineEdit_76->text();
    QString email =ui->lineEdit_77->text();
    QString street =ui->lineEdit_78->text();
    QString genre =ui->comboBox->currentText();

    int age =ui->lineEdit_79->text().toInt();

    Client c(nom,prenom,email,street,genre,age);

    bool test=c.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_75->clear();
        ui->lineEdit_76->clear();
        ui->lineEdit_77->clear();
        ui->lineEdit_78->clear();
        ui->lineEdit_79->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}


void MainWindow::on_PdfBtn_14_clicked()
{
    ui->table_6->setModel(cs.afficher());
}




void MainWindow::on_pushButton_46_clicked()
{
    int id =ui->lineEdit_68->text().toUInt();
    bool test=c.supprimer(id);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimé \n" "click to cancel"),QMessageBox::Cancel);

    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_47_clicked()
{
    {
        int id=ui->lineEdit_69->text().toUInt();
        QString nom=ui->lineEdit_70->text();
        QString prenom=ui->lineEdit_71->text();
        QString email=ui->lineEdit_72->text();
        QString street=ui->lineEdit_74->text();
        QString genre=ui->comboBox_2->currentText();

        int age=ui->lineEdit_73->text().toUInt();


        bool test=cs.modifier(id,nom,prenom,email,street,genre,age);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("modifier \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

    }
}


void MainWindow::on_table_activated(const QModelIndex &index)
{
    QString val=ui->table_6->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from CLIENT1  where ID='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or EMAIL='"+val+"' or STREET='"+val+"' or GENRE='"+val+"' or AGE='"+val+"'");

        if (qry.exec())
        { while (qry.next())
            {
                ui->lineEdit_69->setText(qry.value(0).toString());
                ui->lineEdit_70->setText(qry.value(1).toString());
                ui->lineEdit_71->setText(qry.value(2).toString());
                ui->lineEdit_72->setText(qry.value(3).toString());
                ui->lineEdit_74->setText(qry.value(4).toString());
                ui->comboBox_2->setCurrentText(qry.value(5).toString());
                ui->lineEdit_73->setText(qry.value(6).toString());


                ui->lineEdit_68->setText(qry.value(0).toString()); //pour supprimer


            }
        }
}

void MainWindow::on_Psearch_4_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM CLIENT1 WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or PRENOM  LIKE'"+arg1+"%' or EMAIL LIKE'"+arg1+"%' or STREET  LIKE'"+arg1+"%' or GENRE  LIKE'"+arg1+"%' or AGE  LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->table_6->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !!\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->Psearch_4->clear();}
}

void MainWindow::on_Tri_IdE_2_clicked()
{
    ui->table_6->setModel(cs.tri());
}

void MainWindow::on_Tri_Taille_2_clicked()
{
    ui->table_6->setModel(cs.tri_age());

}

void MainWindow::on_Tri_Taille_3_clicked()
{
    ui->table_6->setModel(cs.tri_nom());

}

void MainWindow::on_Tri_Taille_4_clicked()
{
    ui->table_6->setModel(cs.tri_prenom());
}


void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("ibrahim.khedhiri@esprit.tn", "zpeejnaakttbrhfr","smtp.gmail.com",465,30000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("Client", ui->lineEdit_81->text() , ui->lineEdit_80->text(),ui->textEdit_8->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void MainWindow::on_sendBtn_6_clicked()
{
    connect(ui->sendBtn_6, SIGNAL(clicked()),this, SLOT(sendMail()));
}


void MainWindow::on_Mailing_2_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(3);
}
void MainWindow::on_PdfBtn_13_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(3);
}
void MainWindow::on_mailing_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(3);
}

void MainWindow::on_PdfBtn_15_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




                                            i = i +500;
                                         }
                                         int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                             QMessageBox::Yes |  QMessageBox::No);
                                             if (reponse == QMessageBox::Yes)
                                             {
                                                 QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                 painter.end();
                                             }
                                             else
                                             {
                                                  painter.end();
    }

}







void MainWindow::on_PdfBtn_12_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




                                            i = i +500;
                                         }
                                         int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                             QMessageBox::Yes |  QMessageBox::No);
                                             if (reponse == QMessageBox::Yes)
                                             {
                                                 QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                 painter.end();
                                             }
                                             else
                                             {
                                                  painter.end();
    }
}

void MainWindow::on_PdfBtn_28_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




                                            i = i +500;
                                         }
                                         int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                             QMessageBox::Yes |  QMessageBox::No);
                                             if (reponse == QMessageBox::Yes)
                                             {
                                                 QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                 painter.end();
                                             }
                                             else
                                             {
                                                  painter.end();
    }
}

void MainWindow::on_PdfBtn_30_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




                                            i = i +500;
                                         }
                                         int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                             QMessageBox::Yes |  QMessageBox::No);
                                             if (reponse == QMessageBox::Yes)
                                             {
                                                 QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                 painter.end();
                                             }
                                             else
                                             {
                                                  painter.end();
    }
}

void MainWindow::on_HomeBtn_22_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(0);
}

//**************************CLIENT**********************//////////////////

//**************************FOURNISSEURS**********************/////////////
void MainWindow::on_HomeBtn_28_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);
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
void MainWindow::updateR_label()
{
    char       d1[80];
    //lire a partir arduino
    data=S.read_from_arduino();
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
        ui->label_147->setText("Welcome Ali"); // si les données reçues de arduino via la liaison série sont égales à 1
    ajouter("ali", "1", buf);

    }
    // alors afficher ON
   else  if(data=="2")
{
        S.write_to_arduino("2");

        ui->label_147->setText("Welcome Fatma"); // si les données reçues de arduino via la liaison série sont égales à 2
    ajouter("FATMA", "2", buf);
}
    else  if(data=="3")
{
        S.write_to_arduino("3");

         ui->label_147->setText("Welcome nour");//si les données reçues de arduino via la liaison série sont égales à 3
    ajouter("nour", "3", buf);
    }
    else  if(data=="4")
{
        S.write_to_arduino("4");

         ui->label_147->setText("Welcome haithem");//si les données reçues de arduino via la liaison série sont égales à 4
ajouter("haithem", "4", buf);
    }
    else  if(data=="5")
{
        S.write_to_arduino("5");

         ui->label_147->setText("Welcome rahma");//si les données reçues de arduino via la liaison série sont égales à 5
ajouter("rahma", "5", buf);
    }

    else

        ui->label_147->setText("wrong password");   // si les données reçues de arduino via la liaison série sont égales à 0

    ui->tableViewR->setModel(afficher());
}

void MainWindow::on_pushButton_53_clicked()
{
     ui->tableViewR->setModel(afficher());
}
void MainWindow::on_PdfBtn_32_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(11);
}

void MainWindow::on_PdfBtn_33_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(11);
}

void MainWindow::on_PdfBtn_35_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(11);
}

void MainWindow::on_PdfBtn_36_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(11);
}

void MainWindow::on_PdfBtn_37_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(11);
}

void MainWindow::on_HomeBtn_23_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_25_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::on_addeq_25_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_24_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_26_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::on_addeq_26_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_25_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_27_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::on_addeq_27_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_26_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_28_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::on_addeq_28_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(2);
}

//void MainWindow::on_pushButton_51_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

void MainWindow::on_LogoutBtn_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_txtBtn_18_clicked()
{
     ui->stackedWidget_8->setCurrentIndex(3);
}

void MainWindow::on_txtBtn_6_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(3);
}
void MainWindow::on_txtBtn_7_clicked()
{
     ui->stackedWidget_8->setCurrentIndex(3);
}

void MainWindow::on_txtBtn_8_clicked()
{
     ui->stackedWidget_8->setCurrentIndex(3);
}
void MainWindow::on_HomeBtn_27_clicked()
{
     ui->stackedWidget_8->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_29_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::on_addeq_29_clicked()
{
     ui->stackedWidget_8->setCurrentIndex(2);
}

void MainWindow::on_LogoutBtn_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_buttonBox_10_accepted()
{
    QString nom =ui->lineEdit_90->text();
    QString prenom =ui->lineEdit_91->text();
    QString email =ui->lineEdit_92->text();
    QString adresse =ui->lineEdit_93->text();
    int num_tel =ui->lineEdit_1->text().toUInt();

    fournisseurs f(nom,prenom,email,adresse,num_tel);

    bool test=f.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}


void MainWindow::on_PdfBtn_34_clicked()
{
    ui->table_7->setModel(f.afficher());
}

void MainWindow::on_pushButton_51_clicked()
{
    {
        int id =ui->lineEdit_82->text().toUInt();
        bool test=f.supprimer(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Supprimé \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_52_clicked()
{
      int id =ui->lineEdit_83->text().toUInt();
      QString nom =ui->lineEdit_84->text();
      QString prenom =ui->lineEdit_85->text();
      QString email =ui->lineEdit_86->text();
      QString adresse =ui->lineEdit_87->text();
      int num_tel =ui->lineEdit_88->text().toInt();
      bool test=f.modifier_fournisseurs(id,nom,prenom,email,adresse,num_tel);
      if(test)
      {
          QMessageBox::information(nullptr, QObject::tr("ok"),
                                   QObject::tr("modifié \n"
                                               "click to cancel"), QMessageBox::Cancel);
      }
  else
      QMessageBox::critical(nullptr,QObject::tr("not ok"),
                            QObject::tr("modification non effectué"),QMessageBox::Cancel);

}

void MainWindow::on_table_7_activated(const QModelIndex &index)
{
    QString val=ui->table->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from FOURNISSEURS  where ID_FOURNISEUR='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or EMAIL='"+val+"' or NUM_TEL='"+val+"' or ADRESSE='"+val+"' ");

            if (qry.exec())
            { while (qry.next())
                {
                    ui->lineEdit_83->setText(qry.value(0).toString());
                    ui->lineEdit_84->setText(qry.value(1).toString());
                    ui->lineEdit_85->setText(qry.value(2).toString());
                    ui->lineEdit_86->setText(qry.value(3).toString());
                    ui->lineEdit_87->setText(qry.value(5).toString());
                    ui->lineEdit_88->setText(qry.value(4).toString());
                    ui->lineEdit_82->setText(qry.value(0).toString());


                }
            }

}

void MainWindow::on_lineEdit_89_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM FOURNISSEURS WHERE ID_FOURNISEUR  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or PRENOM  LIKE'"+arg1+"%' or EMAIL LIKE'"+arg1+"%' or NUM_TEL LIKE'"+arg1+"%' or ADRESSE LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) {
         model->setQuery(*query);
         ui->table->setModel(model);
         }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->lineEdit_89->clear();}

}
void MainWindow::on_Export_button_clicked()
    {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home",

          QFileDialog::ShowDirsOnly  | QFileDialog::DontResolveSymlinks);

            qDebug()<<dir;
             QPdfWriter pdf(dir+"/PdfList.pdf");
              QPainter painter(&pdf);
              int i = 4000;



              painter.setPen(Qt::red);
              painter.setFont(QFont("Arial", 30));
              QPixmap pxpic;
              pxpic.load("C:/Users/MSI/Desktop/Téléchargements/IPrintz.png");
              painter.drawPixmap(100,100,780,780,pxpic);
              painter.drawText(900,650,"IPrintz");
              painter.drawText(3000,1400,"Liste Des Fournisseur");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 9));
              painter.drawText(300,3300,"ID");
              painter.drawText(1900,3300,"NOM");
              painter.drawText(2900,3300,"PRENOM");
              painter.drawText(4000,3300,"EMAIL");
              painter.drawText(5900,3300,"ADRESSE");
              painter.drawText(7000,3300,"NUM_TEL");
              painter.drawRect(100,3000,9400,10700);

              QTextDocument previewDoc;
              QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");
              QTextCursor cursor(&previewDoc);



              QSqlQuery query;
              query.prepare("select * from FOURNISSEURS");
              query.exec();
              while (query.next())
              {
                  painter.drawText(300,i,query.value(0).toString());
                  painter.drawText(1900,i,query.value(1).toString());
                  painter.drawText(2900,i,query.value(2).toString());
                  painter.drawText(4000,i,query.value(3).toString());
                  painter.drawText(5900,i,query.value(4).toString());
                  painter.drawText(7000,i,query.value(5).toString());

                  i = i +500;
               }
               int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                   QMessageBox::Yes |  QMessageBox::No);
                   if (reponse == QMessageBox::Yes)
                   {
                       QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                       painter.end();
                   }
                   else
                   {
                        painter.end();
                       }

    }




void MainWindow::on_trierbutton_clicked()
{
    ui->table_7->setModel(f.afficher_fournisseurs_trierf());
}

void MainWindow::on_trierNbutton_clicked()
{
     ui->table_7->setModel(f.afficher_fournisseurs_trierfn());
}

void MainWindow::on_trierAbutton_clicked()
{
    ui->table_7->setModel(f.afficher_fournisseurs_trierfa());
}
































//**************************FOURNISSEURS**********************/////////////
void MainWindow::on_HomeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_HomeBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_HomeBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_HomeBtn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString username=ui->lineEdit_29->text();
        QString password=ui->lineEdit_30->text();
        if((username=="admin")&&(password=="admin"))
        {
          ui->stackedWidget->setCurrentIndex(0);
        }
        else if((username=="abdou")&&(password=="admin"))
        {
          ui->stackedWidget->setCurrentIndex(7);
        }
        else if((username=="ons")&&(password=="admin"))
        {
          ui->stackedWidget->setCurrentIndex(8);
        }else if((username=="ibrahim")&&(password=="admin"))
        {
          ui->stackedWidget->setCurrentIndex(9);
        }else if((username=="haithem")&&(password=="admin"))
        {
          ui->stackedWidget->setCurrentIndex(10);
        }
        else QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                    QObject::tr("Vérifiez vos coordonnées."), QMessageBox::Cancel);


}

void MainWindow::on_LogoutBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_buttonBox_2_accepted()
{
    QString nom =ui->lineEdit->text();
    QString prenom =ui->lineEdit_5->text();
    QString email =ui->lineEdit_2->text();
    int salaire =ui->lineEdit_4->text().toInt();
    int age =ui->lineEdit_3->text().toInt();

    Employee e(nom,prenom,email,age,salaire);

    bool test=e.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}


void MainWindow::on_PdfBtn_3_clicked()
{
    ui->table->setModel(e.afficher());
}




void MainWindow::on_pushButton_3_clicked()
{
    int id =ui->lineEdit_6->text().toUInt();
    bool test=e.supprimer(id);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimé \n" "click to cancel"),QMessageBox::Cancel);

    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

/*void MainWindow::on_pushButton_4_clicked()
{
    {
        int id=ui->lineEdit_7->text().toUInt();
        QString nom=ui->lineEdit_8->text();
        QString prenom=ui->lineEdit_9->text();
        QString email=ui->lineEdit_10->text();
        int age=ui->lineEdit_12->text().toUInt();
        int salaire=ui->lineEdit_11->text().toUInt();


        bool test=e.modifier(id,nom,prenom,email,age,salaire);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("modifier \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

    }
}*/




void MainWindow::on_pushButton_17_clicked()
{
    {
        int id=ui->lineEdit_7->text().toUInt();
        QString nom=ui->lineEdit_8->text();
        QString prenom=ui->lineEdit_9->text();
        QString email=ui->lineEdit_10->text();
        int age=ui->lineEdit_12->text().toUInt();
        int salaire=ui->lineEdit_11->text().toUInt();


        bool test=e.modifier(id,nom,prenom,email,age,salaire);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("modifier \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

    }
}







void MainWindow::on_pushButton_5_clicked()
{
    ui->table->setModel(e.tri2());
}
void MainWindow::on_pushButton_6_clicked()
{
    ui->table->setModel(e.tri());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->table->setModel(e.tri1());
}




/*void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString ch = arg1;

                        if (ch=="")
                        {
                            ui->table->setModel(e.afficher());
                        }
                        else {
                          ui->table->setModel(e.rechercherid(ch)) ;
       }
}*/

void MainWindow::on_HomeBtn_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_PdfBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PdfBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PdfBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_DataBtn_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_15_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;

            QSqlQuery query;
            QString nom="",prenom="",email="";
            QString critere=ui->comboBox->currentText();
            if(critere=="mail")
            {
                 email=ui->lineEdit_49->text();
                 ui->table->setModel(e.RechercheByemail(email));
            }
               else if(critere=="nom")
               {
                   nom=ui->lineEdit_49->text();
                   ui->table->setModel(e.RechercheByNom(nom));
               }
               else if(critere=="prenom")
               {
                   prenom=ui->lineEdit_49->text();
                   ui->table->setModel(e.RechercheByPrenom(prenom));
               }
    }









void MainWindow::on_pushButton_9_clicked()
{
    QString nom =ui->lineEdit_44->text();
    QString prenom =ui->lineEdit_45->text();
    QString email =ui->lineEdit_46->text();
          int id=ui->lineEdit_50->text().toInt();
       QString date_debut =ui->lineEdit_13->text();
        QString date_fin =ui->lineEdit_14->text();


    Conge c(  id,nom, prenom, email, date_debut, date_fin);

    bool test=c.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_10_clicked()
{





    QPdfWriter pdf("C:/Users/Rahma/OneDrive/Bureau/test_pdf/liste.pdf");

        QPainter painter(&pdf);

        int i = 4000;
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(3000,1500,"LISTE employee");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(2700,200,7300,2600);
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"Identifiant");
        painter.drawText(2300,3300,"NOM");
        painter.drawText(4300,3300,"prenom");
        painter.drawText(6300,3300,"email");
        painter.drawText(8000,3300,"age");
        QSqlQuery query;
        query.prepare("select * from Employee");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(2300,i,query.value(1).toString());
            painter.drawText(4300,i,query.value(2).toString());
            painter.drawText(6300,i,query.value(3).toString());
            painter.drawText(8000,i,query.value(4).toString());
            i = i +500;
        }

        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Rahma/OneDrive/Bureau/test_pdf/liste.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }





}





void MainWindow::on_pushButton_14_clicked()
{
   ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_36_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_HomeBtn_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PdfBtn_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_PdfBtn_8_clicked()
{
    ui->table_2->setModel(c.afficher());
}

void MainWindow::on_pushButton_12_clicked()
{
    int id =ui->lineEdit_15->text().toInt();
    bool test=c.supprimer(id);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimé \n" "click to cancel"),QMessageBox::Cancel);

    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_13_clicked()
{
    {
        int id=ui->lineEdit_16->text().toInt();
        QString nom=ui->lineEdit_17->text();
        QString prenom=ui->lineEdit_18->text();
        QString email=ui->lineEdit_19->text();
        QString date_debut=ui->lineEdit_20->text();
       QString date_fin=ui->lineEdit_21->text();



        bool test=c.modifier(id,nom,prenom,email,date_debut,date_fin);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("modifier \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

    }
}

void MainWindow::on_LogoutBtn_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_SettingsBtn_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_4_clicked()
{
    {
        int id=ui->lineEdit_7->text().toUInt();
        QString nom=ui->lineEdit_8->text();
        QString prenom=ui->lineEdit_9->text();
        QString email=ui->lineEdit_10->text();
        int age=ui->lineEdit_12->text().toUInt();
        int salaire=ui->lineEdit_11->text().toUInt();


        bool test=e.modifier(id,nom,prenom,email,age,salaire);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("modifier \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

    }
}

void MainWindow::on_DataBtn_33_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::on_addeq_33_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(2);
}

void MainWindow::on_PdfBtn_57_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(3);
}

void MainWindow::on_HomeBtn_34_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_34_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::on_addeq_34_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(2);
}

void MainWindow::on_PdfBtn_58_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(3);
}

void MainWindow::on_HomeBtn_35_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_35_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::on_addeq_35_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(2);
}

void MainWindow::on_PdfBtn_63_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(3);
}

void MainWindow::on_HomeBtn_36_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_36_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::on_addeq_36_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(2);
}

void MainWindow::on_PdfBtn_64_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(3);
}

void MainWindow::on_PdfBtn_59_clicked()
{
    ui->table_13->setModel(ee.afficher());
}

void MainWindow::on_pushButton_77_clicked()
{
        int id =ui->sup_eq->text().toUInt();
        bool test=ee.supprimer(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Supprimé \n"
                                                 "click to cancel"), QMessageBox::Cancel);
            ui->sup_eq->clear();
            ui->upd_id_eq->clear();
            ui->upd_nom_eq->clear();
            ui->upd_mar_eq->clear();
            ui->upd_pri_eq->clear();
            ui->table_13->setModel(ee.afficher());
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_table_13_activated(const QModelIndex &index)
{
            QString val=ui->table_13->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from equipement  where ID_EQ='"+val+"' or NOM='"+val+"' or MARQUE='"+val+"' or ETAT='"+val+"' or PRIX='"+val+"'");

            if (qry.exec())
            { while (qry.next())
                {
                    //update
                    //id
                    ui->upd_id_eq->setText(qry.value(0).toString());
                    ui->upd_nom_eq->setText(qry.value(1).toString());
                    ui->upd_mar_eq->setText(qry.value(2).toString());
                    ui->upd_pri_eq->setText(qry.value(4).toString());
                    //
                    ui->combo_statut_eq->setCurrentText(qry.value(1).toString());
                    //delete
                    //id
                    ui->sup_eq->setText(qry.value(0).toString()); //pour supprimer
                }
            }
}

void MainWindow::on_PdfBtn_60_clicked()
{
    ui->table_13->setModel(ee.trie_id());
}

void MainWindow::on_PdfBtn_61_clicked()
{
    ui->table_13->setModel(ee.trie_nom());

}

void MainWindow::on_PdfBtn_62_clicked()
{
    ui->table_13->setModel(ee.trie_prix());

}

void MainWindow::on_pushButton_79_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
        qDebug()<<dir;
        QPdfWriter pdf(dir+"/PdfList.pdf");
                               QPainter painter(&pdf);
                              int i = 4000;

                                    painter.drawPixmap(QRect(100,100,2500,2500),QPixmap("C:/Users/ABDOU/Desktop/project/1.png"));
                                    painter.drawText(900,650,"IPrintz");
                                   painter.setPen(Qt::red);
                                   painter.setFont(QFont("Time New Roman", 25));
                                   painter.drawText(3000,1400,"Equipements list");
                                   painter.setPen(Qt::black);
                                   painter.setFont(QFont("Time New Roman", 15));
                                   painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                   painter.drawRect(100,3000,9400,500);
                                   painter.setFont(QFont("Time New Roman", 9));
                                   painter.drawText(300,3300,"ID");
                                   painter.drawText(2000,3300,"Nom");
                                   painter.drawText(4000,3300,"Marque");
                                   painter.drawText(5600,3300,"Etat");
                                   painter.drawText(7000,3300,"Prix");
                                   painter.drawText(8000,3300,"Date ajout");
                                   painter.drawRect(100,3000,9400,10700);
                                   QTextDocument previewDoc;
                                   QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");
                                   QTextCursor cursor(&previewDoc);
                                   QSqlQuery query;
                                   query.prepare("select * from equipement");
                                   query.exec();
                                   while (query.next())
                                   {
                                       painter.drawText(300,i,query.value(0).toString());
                                       painter.drawText(2000,i,query.value(1).toString());
                                       painter.drawText(4000,i,query.value(2).toString());
                                       painter.drawText(5600,i,query.value(3).toString());
                                       painter.drawText(7000,i,query.value(4).toString());
                                       painter.drawText(8000,i,query.value(5).toString());
                                      i = i +500;
                                   }
                                   int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                       QMessageBox::Yes|QMessageBox::No);
                                       if (reponse == QMessageBox::Yes)
                                       {
                                           QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                           painter.end();
                                       }
                                       else
                                       {
                                            painter.end();
    }

}

void MainWindow::on_lineEdit_111_textChanged(const QString &arg1)
{
            QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM equipement WHERE ID_EQ  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or PRIX  LIKE'"+arg1+"%' or MARQUE LIKE'"+arg1+"%'");
             query->exec();
             if (query->next()) {
             model->setQuery(*query);
             ui->table_13->setModel(model);
             }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !!\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
              ui->lineEdit_111->clear();}
}



void MainWindow::on_pushButton_78_clicked()
{
    int id =ui->upd_id_eq->text().toUInt();
        QString nom =ui->upd_nom_eq->text();
        QString marque =ui->upd_mar_eq->text();
        QString etat =ui->combo_statut_eq->currentText();
        float prix =ui->upd_pri_eq->text().toFloat();
        bool test=ee.modifier_equipement(id ,nom,marque,prix,etat);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("modifié \n"
                                                 "click to cancel"), QMessageBox::Cancel);
            ui->upd_id_eq->clear();
            ui->upd_nom_eq->clear();
            ui->upd_mar_eq->clear();
            ui->upd_pri_eq->clear();
            ui->table_13->setModel(ee.afficher());
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("modification non effectué"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_80_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                        model->setQuery("select * from EQUIPEMENT where etat = 'WORKING' ");
                                        float e=model->rowCount();
                                        model->setQuery("select * from EQUIPEMENT where etat = 'NOT WORKING' ");
                                        float ee=model->rowCount();
                                        float total=e+ee;
                                        QString a=QString("working"+QString::number((e*100)/total,'f',2)+"%" );
                                        QString b=QString("not working"+QString::number((ee*100)/total,'f',2)+"%" );
                                        QPieSeries *series = new QPieSeries();
                                        series->append(a,e);
                                        series->append(b,ee);
                                if (e!=0)
                                {QPieSlice *slice = series->slices().at(0);
                                 slice->setLabelVisible();
                                 slice->setPen(QPen());}
                                if ( ee!=0)
                                {
                                         // Add label, explode and define brush for 2nd slice
                                         QPieSlice *slice1 = series->slices().at(1);
                                         //slice1->setExploded();
                                         slice1->setLabelVisible();
                                }
                                        // Create the chart widget
                                        QChart *chart = new QChart();
                                        // Add data to chart with title and hide legend
                                        chart->addSeries(series);
                                        chart->setTitle("Pourcentage suivant etat machine : nombre totale machine: "+ QString::number(total));
                                        chart->legend()->hide();
                                        // Used to display the chart
                                        QChartView *chartView = new QChartView(chart);
                                        chartView->setRenderHint(QPainter::Antialiasing);
                                        chartView->resize(1000,500);
                                        chartView->show();
    }
void MainWindow::on_buttonBox_11_accepted()
{
        QString nom =ui->lineEdit_112->text();
        QString marque =ui->lineEdit_113->text();
        QString etat =ui->comboBox_27->currentText();
        float prix =ui->lineEdit_114->text().toFloat();
        equipement ee(nom,marque,prix,etat);
        bool test=ee.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
            ui->lineEdit_112->clear();
            ui->lineEdit_113->clear();
            ui->lineEdit_114->clear();
            ui->table_13->setModel(ee.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}

void MainWindow::on_PdfBtn_65_clicked()
{
    ui->table_14->setModel(i.afficher());
}

void MainWindow::on_table_14_activated(const QModelIndex &index)
{
        QString val=ui->table_14->model()->data(index).toString();
        QSqlQuery qry;
        //
        qry.prepare("select * from INTERVENTIONS  where ID_INT='"+val+"' or TYPE_INT='"+val+"' ");
        if (qry.exec())
        { while (qry.next())
            {
                //update
                //id
                ui->lineEdit_117->setText(qry.value(0).toString());
                ui->lineEdit_118->setText(qry.value(1).toString());
                //
                //delete
                //id
                ui->lineEdit_116->setText(qry.value(0).toString()); //pour supprimer

            }
        }
}

void MainWindow::on_pushButton_83_clicked()
{
    int id =ui->lineEdit_116->text().toUInt();
        bool test=i.supprimer(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Supprimé \n"
                                                 "click to cancel"), QMessageBox::Cancel);
            ui->lineEdit_117->clear();
            ui->lineEdit_118->clear();
            ui->lineEdit_116->clear();
            ui->table_14->setModel(i.afficher());
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_84_clicked()
{
       int id =ui->lineEdit_117->text().toUInt();
       QString type =ui->lineEdit_118->text();
       QString etat = ui->comboBox_31->currentText();
       bool test=i.modifier_interventions(id,type,etat);
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("modifié \n"
                                                "click to cancel"), QMessageBox::Cancel);
           ui->lineEdit_117->clear();
           ui->lineEdit_118->clear();
           ui->table_14->setModel(i.afficher());
       }
   else
       QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("modification non effectué"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_85_clicked()
{
    int tabeq=ui->table_14->currentIndex().row();
                   QVariant idd=ui->table_14->model()->data(ui->table_14->model()->index(tabeq,0));
                   QString id=idd.toString();
                  // QString code=idd.toSTring();
                   QSqlQuery qry;
                   qry.prepare("select * from equipement where ID_EQ=:code");
                   qry.bindValue(":code",id);
                   qry.exec();

                    QString nom,marque,etat;//attributs
                    int prix;

                  while(qry.next()){

                      id=qry.value(0).toString();
                       nom=qry.value(1).toString();
                        marque=qry.value(2).toInt();
                       etat=qry.value(3).toInt();
                       prix=qry.value(4).toInt();
                   }
                   id=QString(id);
                          id="CODE:\t" +id+ "NOM\t:" +nom+ "marque:\t" +marque+ "etat:\t" +etat+ "prix:\t" +prix+ "prix:\t" +prix ;
                   QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

                   // Read the black & white pixels
                   QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                   for (int y = 0; y < qr.getSize(); y++) {
                       for (int x = 0; x < qr.getSize(); x++) {
                           int color = qr.getModule(x, y);  // 0 for white, 1 for black

                           // You need to modify this part
                           if(color==0)
                               im.setPixel(x, y,qRgb(254, 254, 254));
                           else
                               im.setPixel(x, y,qRgb(0, 0, 0));
                       }
                   }
                   im=im.scaled(200,200);
                   ui->label_199->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::on_pushButton_82_clicked()
{
        QString type =ui->lineEdit_115->text();
        int eq =ui->comboBox_28->currentText().toInt();
        int emp =ui->comboBox_29->currentText().toInt();
        QString etat =ui->comboBox_30->currentText();

        interventions i(type,etat,eq,emp);
        bool test=i.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
            ui->lineEdit_115->clear();
            ui->table_14->setModel(i.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}

void MainWindow::on_HomeBtn_9_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_11_clicked()
{
   ui->stackedWidget_6->setCurrentIndex(1);
}

void MainWindow::on_addeq_11_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(3);
}

void MainWindow::on_DataBtn_9_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(1);
}

void MainWindow::on_addeq_9_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_DataBtn_10_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(1);
}

void MainWindow::on_addeq_10_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_pushButton_37_clicked()
{
            int id =ui->lineEdit_31->text().toUInt();
            bool test=cc.supprimer(id);
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                                         QObject::tr("Supprimé \n"
                                                     "click to cancel"), QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("suppression non effectué"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_38_clicked()
{
          int id =ui->lineEdit_32->text().toUInt();
          int quantite =ui->lineEdit_33->text().toInt();
          QString adresse =ui->lineEdit_34->text();
          float prix_unitaire =ui->lineEdit_35->text().toFloat();
          float prix_total =ui->lineEdit_36->text().toFloat();
          int id_clients =ui->lineEdit_65->text().toFloat();
          int id_empl =ui->lineEdit_66->text().toFloat();
          int id_produits =ui->lineEdit_67->text().toFloat();

           bool test=cc.modifier_commandes(id, adresse,quantite,prix_unitaire, prix_total,id_clients,id_empl,id_produits);
           if(test)
           {
               QMessageBox::information(nullptr, QObject::tr("ok"),
                                        QObject::tr("modifié \n"
                                                    "click to cancel"), QMessageBox::Cancel);
           }
       else
           QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("modification non effectué"),QMessageBox::Cancel);
    }

void MainWindow::on_PdfBtn_11_clicked()
{
    ui->table_3->setModel(cc.afficher());
}

void MainWindow::on_qr_clicked()
{
    int tabeq=ui->table_3->currentIndex().row();
                       QVariant idd=ui->table_3->model()->data(ui->table_3->model()->index(tabeq,0));
                       QString id=idd.toString();
                      // QString code=idd.toSTring();
                       QSqlQuery qry;
                       qry.prepare("select * from COMMANDES where ID_COMMANDES=:code");
                       qry.bindValue(":code",id);
                       qry.exec();

                        QString adresse;//attributs
                        int quantite,prix_unitaire,prix_total;
                        QDate date;

                      while(qry.next()){

                          id=qry.value(1).toString();
                           //=qry.value(2).toString();
                            quantite=qry.value(3).toInt();
                           adresse=qry.value(4).toString();
                           prix_unitaire=qry.value(5).toInt();
                           prix_total=qry.value(6).toInt();
                           date=qry.value(7).toDate();
                       }
                       id=QString(id);

                       id="CODE:\t" +id+ "quantite\t:" +quantite+ "adresse:\t" +adresse+ "prix_unitaire:\t" +prix_unitaire  ;
                       QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);
                       // Read the black & white pixels
                       QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                       for (int y = 0; y < qr.getSize(); y++) {
                           for (int x = 0; x < qr.getSize(); x++) {
                               int color = qr.getModule(x, y);  // 0 for white, 1 for black

                               // You need to modify this part
                               if(color==0)
                                   im.setPixel(x, y,qRgb(254, 254, 254));
                               else
                                   im.setPixel(x, y,qRgb(0, 0, 0));
                           }
                       }
                       im=im.scaled(200,200);
                       ui->label_42->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::on_pushButton_42_clicked()
{
    QTableView *table;
                               table = ui->table_3;

                               QString filters("CSV files (.xlsx);;All files (.*)");
                               QString defaultFilter("CSV files (*.xlsx)");
                               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                  filters, &defaultFilter);
                               QFile file(fileName);

                               QAbstractItemModel *model =  table->model();
                               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                                   QTextStream data(&file);
                                   QStringList strList;
                                   for (int i = 0; i < model->columnCount(); i++) {
                                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") << "\n";
                                   for (int i = 0; i < model->rowCount(); i++) {
                                       strList.clear();
                                       for (int j = 0; j < model->columnCount(); j++) {

                                           if (model->data(model->index(i, j)).toString().length() > 0)
                                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                           else
                                               strList.append("");
                                       }
                                       data << strList.join(";") + "\n";
                                   }
                                   file.close();
                                   QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                             QObject::tr("Export avec succes .\n"
                                                                         "Click OK to exit."), QMessageBox::Ok);
                               }
}

void MainWindow::on_pushButton_40_clicked()
{
    cc.exporterpdf(ui->textBrowser);
}

void MainWindow::on_pushButton_44_clicked()
{
    ui->table_3->setModel(cc.trier_par_prix());
}

void MainWindow::on_pushButton_43_clicked()
{
    ui->table_3->setModel(cc.trier_par_identifiant());
}

void MainWindow::on_pushButton_41_clicked()
{
    ui->table_3->setModel(cc.trier_par_quantite());
}

void MainWindow::on_pushButton_39_clicked()
{
    ui->table_3->setModel(cc.recherche(ui->lineEdit_51->text()));
}

void MainWindow::on_buttonBox_5_accepted()
{
        QString adresse =ui->lineEdit_62->text();
        int quantite =ui->lineEdit_61->text().toInt();
        int prix_total =ui->lineEdit_64->text().toFloat();
        int prix_unitaire =ui->lineEdit_63->text().toFloat();
        int id_clients =ui->lineEdit_65->text().toFloat();
               int id_empl =ui->lineEdit_66->text().toFloat();
               int id_produits =ui->lineEdit_67->text().toFloat();
        commandes cc(adresse,quantite,prix_unitaire, prix_total,id_clients,id_empl,id_produits);

        bool test=cc.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effectue"),QMessageBox::Cancel);

}

void MainWindow::on_LogoutBtn_11_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_10_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_9_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_33_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_34_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_35_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_LogoutBtn_36_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_table_3_activated(const QModelIndex &index)
{
                QString val=ui->table_3->model()->data(index).toString();
                QSqlQuery query;
                query.prepare("select * from commandes  where ID_COMMANDES='"+val+"' or ADRESSE='"+val+"' or QUANTITE='"+val+"' or PRIX_UNITAIRE='"+val+"' or PRIX_TOTAL='"+val+"'");
                if (query.exec())
                { while (query.next())
                    {
                        ui->lineEdit_32->setText(query.value(0).toString());
                        ui->lineEdit_33->setText(query.value(1).toString());
                        ui->lineEdit_34->setText(query.value(2).toString());
                        ui->lineEdit_35->setText(query.value(3).toString());
                        ui->lineEdit_36->setText(query.value(4).toString());
                        ui->lineEdit_65->setText(query.value(5).toString());
                        ui->lineEdit_66->setText(query.value(6).toString());
                        ui->lineEdit_67->setText(query.value(7).toString());
                        ui->lineEdit_31->setText(query.value(0).toString()); //pour supprimer


                    }
                }
}









