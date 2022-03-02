#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->table->setModel(p.afficher());
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
    QString categorie =ui->lineEdit_2->text();
    int quantite =ui->lineEdit_4->text().toInt();
    int prix =ui->lineEdit_3->text().toInt();
    produit p(nom,categorie,prix,quantite);

    bool test=p.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Product successfully added  \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Error") , QObject::tr("No Product Added"),QMessageBox::Cancel);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

}


void MainWindow::on_PdfBtn_3_clicked()
{
    ui->table->setModel(p.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{
    int id =ui->lineEdit_5->text().toUInt();
       bool test=p.supprimer(id);
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("Produit Supprimé \n"
                                                "click to cancel"), QMessageBox::Cancel);
       }
   else
       QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("suppression non effectuée"),QMessageBox::Cancel);

       ui->lineEdit_5->clear();

}

void MainWindow::on_pushButton_4_clicked()
{
    int id =ui->lineEdit_6->text().toInt();
        QString nom =ui->lineEdit_7->text();
        QString categorie =ui->lineEdit_8->text();
        int prix =ui->lineEdit_9->text().toInt();
        int quantite =ui->lineEdit_10->text().toInt();
        bool test=p.modifier_produit(id,nom,categorie,prix,quantite);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Product modified successfully  \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("No Modification done. "),QMessageBox::Cancel);

        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
}
