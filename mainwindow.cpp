#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseurs.h"
#include "produit.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QDesktopServices>
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
    ui->stackedWidget->setCurrentIndex(0);
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

