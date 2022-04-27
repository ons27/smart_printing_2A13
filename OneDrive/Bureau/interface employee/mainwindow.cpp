#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QMessageBox>
#include "QMessageBox"
#include"conge.h"
#include <QApplication>
#include <QIntValidator>
#include <QStackedWidget>
#include <QDateEdit>
#include<QSqlQuery>
#include <QComboBox>
#include<QFileDialog>
//#include<QTcpSocket>






#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(5);
    ui->table->setModel(e.afficher());
    QRegExp rx("[a-zA-Z]+");
    QValidator *validatior = new
            QRegExpValidator (rx ,this) ;


    ui->lineEdit->setValidator(validatior);
    ui->lineEdit_5->setValidator(validatior);
    ui->lineEdit_8->setValidator(validatior);
    ui->lineEdit_9->setValidator(validatior);

    ui->lineEdit_3->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_4->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_11->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_12->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_7->setValidator(new QIntValidator(0, 999999,this));

}


MainWindow::~MainWindow()
{
    delete ui;
}

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
