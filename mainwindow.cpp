#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include"conge.h"
#include "equipements.h"
#include "interventions.h"
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
using namespace QtCharts;
using namespace qrcodegen;
using namespace std;




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
        else if((username=="abdou")&&(password=="admin"))
        {
          ui->stackedWidget->setCurrentIndex(7);
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
