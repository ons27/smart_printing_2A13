#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include "interventions.h"
#include <QMessageBox>
#include<QSystemTrayIcon>
#include <QRegExp>
#include "connection.h"
#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include "qrcode.h"

using namespace qrcodegen;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //affichage
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(4);
    ui->table->setModel(e.afficher());
    ui->table_2->setModel(i.afficher());
    QSqlQuery query;
    QSqlQueryModel *load=new QSqlQueryModel();
    query.prepare("SELECT ID_EQ FROM EQUIPEMENT");
    query.exec();
    load->setQuery(query);
    ui->comboBox_3->setModel(load);
    QSqlQuery qry;
    QSqlQueryModel *looad=new QSqlQueryModel();
    qry.prepare("SELECT ID_EMP FROM EMPLOYES");
    qry.exec();
    looad->setQuery(qry);
    ui->comboBox_4->setModel(looad);

    //input__control
    ui->lineEdit_3->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_6->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_9->setValidator(new QIntValidator(0,999999,this));
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new
            QRegExpValidator (rx,this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_7->setValidator(validator);
    ui->lineEdit_8->setValidator(validator);
    e.Signal();
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
    QString nom =ui->lineEdit->text();
    QString marque =ui->lineEdit_2->text();
    QString etat =ui->comboBox->currentText();
    float prix =ui->lineEdit_3->text().toFloat();
    equipement e(nom,marque,prix,etat);
    bool test=e.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->table->setModel(e.afficher());
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
    int id =ui->lineEdit_5->text().toUInt();
    bool test=e.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_5->clear();
        ui->table->setModel(e.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_4_clicked()
{
    int id =ui->lineEdit_6->text().toUInt();
    QString nom =ui->lineEdit_7->text();
    QString marque =ui->lineEdit_8->text();
    QString etat =ui->comboBox_2->currentText();
    float prix =ui->lineEdit_9->text().toFloat();
    bool test=e.modifier_equipement(id ,nom,marque,prix,etat);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->table->setModel(e.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("modification non effectué"),QMessageBox::Cancel);

}


void MainWindow::on_PdfBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_PdfBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_PdfBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_table_activated(const QModelIndex &index)
{
        QString val=ui->table->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from equipement  where ID_EQ='"+val+"' or NOM='"+val+"' or MARQUE='"+val+"' or ETAT='"+val+"' or PRIX='"+val+"'");

        if (qry.exec())
        { while (qry.next())
            {
                //update
                //id
                ui->lineEdit_6->setText(qry.value(0).toString());
                ui->lineEdit_7->setText(qry.value(1).toString());
                ui->lineEdit_8->setText(qry.value(2).toString());
                ui->lineEdit_9->setText(qry.value(4).toString());
                //
                ui->comboBox_2->setCurrentText(qry.value(1).toString());
                //delete
                //id
                ui->lineEdit_5->setText(qry.value(0).toString()); //pour supprimer


            }
        }
}

void MainWindow::on_PdfBtn_7_clicked()
{
    ui->table->setModel(e.trie_id());
}

void MainWindow::on_PdfBtn_8_clicked()
{
    ui->table->setModel(e.trie_nom());
}

void MainWindow::on_PdfBtn_9_clicked()
{
    ui->table->setModel(e.trie_prix());
}

void MainWindow::on_pushButton_5_clicked()
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


void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM equipement WHERE ID_EQ  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or PRIX  LIKE'"+arg1+"%' or MARQUE LIKE'"+arg1+"%'");
         query->exec();
         if (query->next()) {
         model->setQuery(*query);
         ui->table->setModel(model);
         }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !!\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
          ui->lineEdit_4->clear();}
}

void MainWindow::on_PdfBtn_6_clicked()
{
    ui->table_2->setModel(i.afficher());
    QSqlQuery query;
    QSqlQueryModel *load=new QSqlQueryModel();
    query.prepare("SELECT ID_EQ FROM EQUIPEMENT");
    query.exec();
    load->setQuery(query);
    ui->comboBox_3->setModel(load);
    QSqlQuery qry;
    QSqlQueryModel *looad=new QSqlQueryModel();
    qry.prepare("SELECT ID_EMP FROM EMPLOYES");
    qry.exec();
    looad->setQuery(qry);
    ui->comboBox_4->setModel(looad);
}

void MainWindow::on_pushButton_8_clicked()
{
    QString type =ui->lineEdit_18->text();
    int eq =ui->comboBox_3->currentText().toInt();
    int emp =ui->comboBox_4->currentText().toInt();
    QString etat =ui->comboBox_6->currentText();

    interventions i(type,etat,eq,emp);
    bool test=i.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_18->clear();
        ui->table_2->setModel(i.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}

void MainWindow::on_table_2_activated(const QModelIndex &index)
{
    QString val=ui->table_2->model()->data(index).toString();
    QSqlQuery qry;
    //
    qry.prepare("select * from INTERVENTIONS  where ID_INT='"+val+"' or TYPE_INT='"+val+"' ");
    if (qry.exec())
    { while (qry.next())
        {
            //update
            //id
            ui->lineEdit_12->setText(qry.value(0).toString());
            ui->lineEdit_14->setText(qry.value(1).toString());
            //
            //delete
            //id
            ui->lineEdit_11->setText(qry.value(0).toString()); //pour supprimer


        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int id =ui->lineEdit_11->text().toUInt();
    bool test=i.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_11->clear();
        ui->table_2->setModel(i.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    int id =ui->lineEdit_12->text().toUInt();
    QString type =ui->lineEdit_14->text();
    QString etat = ui->comboBox_5->currentText();
    bool test=i.modifier_interventions(id,type,etat);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_12->clear();
        ui->lineEdit_14->clear();
        ui->table_2->setModel(i.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("modification non effectué"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_9_clicked()
{
                int tabeq=ui->table_2->currentIndex().row();
               QVariant idd=ui->table_2->model()->data(ui->table_2->model()->index(tabeq,0));
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
              ui->label_14->setPixmap(QPixmap::fromImage(im));
}


