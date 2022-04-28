#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include "fournisseurs.h"

#include <QMessageBox>
#include <QPdfWriter>
#include <QDesktopServices>
=======
#include "client.h"
#include "smtp.h"
#include "employee.h"
#include"conge.h"
#include "equipements.h"
#include "interventions.h"
>>>>>>> 9cdc5de51a5e4b9e00fe648bc684815af01e3d83
#include <QMessageBox>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QUrl>
#include <QPixmap>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->table->setModel(f.afficher());

    ui->lineEdit_1->setValidator( new QIntValidator(0, 999999, this));
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator =new
            QRegExpValidator(rx,this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_11->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_11->setValidator(validator);
=======
    this->ui->stackedWidget->setCurrentIndex(5);
    this->ui->stackedWidget_7->setCurrentIndex(0);

    ui->table->setModel(e.afficher());
    ui->table_3->setModel(cc.afficher());
    ui->table_6->setModel(cs.afficher());

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
>>>>>>> 9cdc5de51a5e4b9e00fe648bc684815af01e3d83

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
    ui->stackedWidget->setCurrentIndex(2);
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
    ui->stackedWidget->setCurrentIndex(2);
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
    ui->stackedWidget->setCurrentIndex(2);
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
<<<<<<< HEAD
    ui->stackedWidget->setCurrentIndex(0);
=======
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
        }
        else QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                    QObject::tr("Vérifiez vos coordonnées."), QMessageBox::Cancel);


>>>>>>> 9cdc5de51a5e4b9e00fe648bc684815af01e3d83
}

void MainWindow::on_LogoutBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_LogoutBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_LogoutBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_LogoutBtn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_txtBtn_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_txtBtn_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_txtBtn_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_txtBtn_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_HomeBtn_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_LogoutBtn_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_buttonBox_2_accepted()
{
    QString nom =ui->lineEdit->text();
    QString prenom =ui->lineEdit_11->text();
    QString email =ui->lineEdit_2->text();
    QString adresse =ui->lineEdit_3->text();
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


void MainWindow::on_PdfBtn_3_clicked()
{
    ui->table->setModel(f.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{
    {
        int id =ui->lineEdit_4->text().toUInt();
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

void MainWindow::on_pushButton_4_clicked()
{
      int id =ui->lineEdit_5->text().toUInt();
      QString nom =ui->lineEdit_6->text();
      QString prenom =ui->lineEdit_7->text();
      QString email =ui->lineEdit_8->text();
      QString adresse =ui->lineEdit_9->text();
      int num_tel =ui->lineEdit_10->text().toInt();
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

void MainWindow::on_table_activated(const QModelIndex &index)
{
    QString val=ui->table->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from FOURNISSEURS  where ID_FOURNISEUR='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or EMAIL='"+val+"' or NUM_TEL='"+val+"' or ADRESSE='"+val+"' ");

            if (qry.exec())
            { while (qry.next())
                {
                    ui->lineEdit_5->setText(qry.value(0).toString());
                    ui->lineEdit_6->setText(qry.value(1).toString());
                    ui->lineEdit_7->setText(qry.value(2).toString());
                    ui->lineEdit_8->setText(qry.value(3).toString());
                    ui->lineEdit_9->setText(qry.value(5).toString());
                    ui->lineEdit_10->setText(qry.value(4).toString());
                    ui->lineEdit_4->setText(qry.value(0).toString());


                }
            }

}

void MainWindow::on_lineEdit_12_textChanged(const QString &arg1)
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
             ui->lineEdit_12->clear();}

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
    ui->table->setModel(f.afficher_fournisseurs_trierf());
}

void MainWindow::on_trierNbutton_clicked()
{
     ui->table->setModel(f.afficher_fournisseurs_trierfn());
}

void MainWindow::on_trierAbutton_clicked()
{
    ui->table->setModel(f.afficher_fournisseurs_trierfa());
}

<<<<<<< HEAD
=======
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




>>>>>>> 9cdc5de51a5e4b9e00fe648bc684815af01e3d83
