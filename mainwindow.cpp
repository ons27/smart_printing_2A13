#include <QMessageBox>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "commandes.h"
#include <QSqlQuery>
#include <QIntValidator> //ensures a string contains a valid integer within a specified range
#include <QSqlError>
#include<QSystemTrayIcon>
#include <QRegExp>
#include "connection.h"
#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include "qrcode.h"
#include <QPixmap>


using namespace qrcodegen;
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->table->setModel(c.afficher());
    ui->lineEdit->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_3->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_4->setValidator(new QIntValidator(0, 999999,this));

    ui->lineEdit_13->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_14->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_16->setValidator(new QIntValidator(0, 999999,this));

    /*
        QRegExp rx("[a-zA-Z]+");
        QValidator *validator = new
                QRegExpValidator(rx,this);
        ui->lineEdit_2->setValidator(validator);
        */
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

void MainWindow::on_buttonBox_2_accepted()
{
    QString adresse =ui->lineEdit_2->text();
    int quantite =ui->lineEdit->text().toInt();
    int prix_total =ui->lineEdit_4->text().toFloat();
    int prix_unitaire =ui->lineEdit_3->text().toFloat();
    int id_clients =ui->lineEdit_13->text().toFloat();
           int id_empl =ui->lineEdit_14->text().toFloat();
           int id_produits =ui->lineEdit_16->text().toFloat();
    commandes c(adresse,quantite,prix_unitaire, prix_total,id_clients,id_empl,id_produits);

    bool test=c.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effectue"),QMessageBox::Cancel);

}


void MainWindow::on_PdfBtn_3_clicked()
{
    ui->table->setModel(c.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{

       int id =ui->lineEdit_5->text().toUInt();
        bool test=c.supprimer(id);
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

void MainWindow::on_pushButton_4_clicked()
{
    int id =ui->lineEdit_6->text().toUInt();
      int quantite =ui->lineEdit_7->text().toInt();
       QString adresse =ui->lineEdit_8->text();
       float prix_unitaire =ui->lineEdit_10->text().toFloat();
       float prix_total =ui->lineEdit_9->text().toFloat();
       int id_clients =ui->lineEdit_13->text().toFloat();
              int id_empl =ui->lineEdit_14->text().toFloat();
              int id_produits =ui->lineEdit_16->text().toFloat();

       bool test=c.modifier_commandes(id, adresse,quantite,prix_unitaire, prix_total,id_clients,id_empl,id_produits);
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
            QSqlQuery query;
            query.prepare("select * from commandes  where ID_COMMANDES='"+val+"' or ADRESSE='"+val+"' or QUANTITE='"+val+"' or PRIX_UNITAIRE='"+val+"' or PRIX_TOTAL='"+val+"'");


            if (query.exec())
            { while (query.next())
                {
                    ui->lineEdit_6->setText(query.value(0).toString());
                    ui->lineEdit_7->setText(query.value(1).toString());

                    ui->lineEdit_8->setText(query.value(2).toString());
                    ui->lineEdit_9->setText(query.value(3).toString());
                    ui->lineEdit_10->setText(query.value(4).toString());

                    ui->lineEdit_13->setText(query.value(5).toString());
                    ui->lineEdit_14->setText(query.value(6).toString());
                    ui->lineEdit_16->setText(query.value(7).toString());


                    ui->lineEdit_5->setText(query.value(0).toString()); //pour supprimer


                }
            }
}
void MainWindow::on_pushButton_7_clicked()
{
    ui->table->setModel(c.trier_par_quantite());
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->table->setModel(c.recherche(ui->lineEdit_11->text()));

}


void MainWindow::on_pushButton_clicked()
{

        QTableView *table;
                           table = ui->table;

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
        QString currDate()
        {
            QDate date = QDate::currentDate();
            return date.toString("dd.MM.yyyy");
    }


void MainWindow::on_pushButton_6_clicked()
{
    c.exporterpdf(ui->textBrowser);

}


void MainWindow::on_pushButton_8_clicked()
{
      ui->table->setModel(c.trier_par_identifiant());
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->table->setModel(c.trier_par_prix());
}



void MainWindow::on_qr_clicked()
{

        int tabeq=ui->table->currentIndex().row();
                   QVariant idd=ui->table->model()->data(ui->table->model()->index(tabeq,0));
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
                  ui->label_19->setPixmap(QPixmap::fromImage(im));
    }

