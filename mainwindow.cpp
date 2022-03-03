#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commandes.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->table->setModel(c.afficher());
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
    commandes c(adresse,quantite,prix_unitaire, prix_total);

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
       bool test=c.modifier_commandes(adresse,quantite,prix_unitaire,prix_total);
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("modifié \n"
                                                "click to cancel"), QMessageBox::Cancel);
       }
   else
       QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}
