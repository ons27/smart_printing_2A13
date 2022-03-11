#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QMessageBox>

/*#include <QApplication>
#include <QIntValidator>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtCore>*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->ui->stackedWidget->setCurrentIndex(0);
    this->ui->stackedWidget->setCurrentIndex(1);
    ui->table->setModel(p.afficher());

    //controle de saisie
       /*ui->lineEdit_4->setValidator( new QIntValidator(0, 999999, this));
       ui->lineEdit_3->setValidator( new QIntValidator(0, 999999, this));
       QRegExp rx("[a-zA-Z ]+");
       QValidator *validator = new
               QRegExpValidator(rx,this);
       ui->lineEdit_2->setValidator(validator);
       ui->lineEdit->setValidator(validator);*/

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
    ui->table->setModel(p.afficher());
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
    ui->table->setModel(p.afficher());
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

    //controle

        bool check1=true;
        bool check2=true;
        bool check3=true;
        bool check4=true;


        QString nomcheck=ui->lineEdit->text();
        QString quantitecheck=ui->lineEdit_4->text();
        QString prixcheck=ui->lineEdit_3->text();
        QString nomfournisseurcheck=ui->lineEdit_2->text();

        check1=p.checkchar(nomcheck);
        check2=p.checkint(prixcheck);
        check3=p.checkint(quantitecheck);
        check4=p.checkint(nomfournisseurcheck);


    QString nom =ui->lineEdit->text();
    QString categorie =ui->comboBox->currentText();
    int quantite =ui->lineEdit_4->text().toInt();
    int prix =ui->lineEdit_3->text().toInt();
    QString nomfournisseur=ui->lineEdit_2->text();
    int idfournisseur;
    idfournisseur=p.get_idfournisseur(nomfournisseur);
    produit p(nom,categorie,prix,quantite,idfournisseur);


    if (check1&&check2&&check3&&check4)
    {
         bool test=p.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Product successfully added  \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Error") , QObject::tr("No Product Added"),QMessageBox::Cancel);
    }
    }
    else
    {  QMessageBox::critical(nullptr, QObject::tr("erreur"),
                                       QObject::tr("Verify your informations. \n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);}


    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

}


/*void MainWindow::on_PdfBtn_3_clicked()
{
    ui->table->setModel(p.afficher());
}*/

void MainWindow::on_pushButton_3_clicked()
{
    int id =ui->lineEdit_5->text().toUInt();
       bool test=p.supprimer(id);
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("Produit Supprimé \n"
                                                "click to cancel"), QMessageBox::Cancel);
           ui->table->setModel(p.afficher());
       }
   else
       QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("suppression non effectuée"),QMessageBox::Cancel);

       ui->lineEdit_5->clear();
       ui->lineEdit_6->clear();
       ui->lineEdit_7->clear();
      ui->comboBox_2->clear();
       ui->lineEdit_9->clear();
       ui->lineEdit_10->clear();

}

void MainWindow::on_pushButton_4_clicked()
{

    bool check1=true;
    bool check2=true;
    bool check3=true;
    bool check4=true;


    QString nomcheck=ui->lineEdit_7->text();
    QString quantitecheck=ui->lineEdit_10->text();
    QString prixcheck=ui->lineEdit_9->text();
    QString nomfournisseurcheck=ui->lineEdit_8->text();

    check1=p.checkchar(nomcheck);
    check2=p.checkint(prixcheck);
    check3=p.checkint(quantitecheck);
    check4=p.checkint(nomfournisseurcheck);

    int id =ui->lineEdit_6->text().toInt();
        QString nom =ui->lineEdit_7->text();
        QString categorie =ui->comboBox_2->currentText();
        int prix =ui->lineEdit_9->text().toInt();
        int quantite =ui->lineEdit_10->text().toInt();
        QString nomfournisseur=ui->lineEdit_8->text();
        int idfournisseur;
        idfournisseur=p.get_idfournisseur(nomfournisseur);


        if (check1&&check2&&check3&&check4)
        {
            bool test=p.modifier_produit(id,nom,categorie,prix,quantite,idfournisseur);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Product modified successfully  \n"
                                                 "click to cancel"), QMessageBox::Cancel);
            ui->table->setModel(p.afficher());
        }
    else
        {QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("No Modification done. "),QMessageBox::Cancel);}
        }
        else
        {  QMessageBox::critical(nullptr, QObject::tr("erreur"),
                                           QObject::tr("Verify your informations. \n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);}


        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();


        ui->lineEdit_5->clear();
}



void MainWindow::on_table_activated(const QModelIndex &index)
{
    QString val=ui->table->model()->data(index).toString();
        QSqlQuery qry;
        //qry.prepare("select * from PRODUITS  where ID_PRODUITS='"+val+"' or NOM='"+val+"' or PRIX_UNITAIRE='"+val+"' or QUANTITE='"+val+"' or CATEGORIE='"+val+"'");


        qry.prepare("select produits.*, fournisseurs.nom as fournisseur from PRODUITS join fournisseurs on produits.ID_FOURNISSEUR=FOURNISSEURS.ID_FOURNISSEUR where ID_PRODUITS='"+val+"' or produits.NOM='"+val+"' or PRIX_UNITAIRE='"+val+"' or QUANTITE='"+val+"' or CATEGORIE='"+val+"'");
        if (qry.exec())
        { while (qry.next())
            {
                ui->lineEdit_6->setText(qry.value(0).toString());
                ui->lineEdit_7->setText(qry.value(3).toString());
               ui->comboBox_2->setCurrentText(qry.value(1).toString());
                ui->lineEdit_9->setText(qry.value(4).toString());
                ui->lineEdit_10->setText(qry.value(2).toString());
                ui->lineEdit_8->setText(qry.value(6).toString());

                 ui->lineEdit_5->setText(qry.value(0).toString()); //pour supprimer


            }
        }
}



void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    QString ch = arg1;

                         if (ch=="")
                         {
                             ui->table->setModel(p.afficher());
                         }
                         else
                         {
                           ui->table->setModel(p.afficher_idrech(ch)) ;
                         }
}



void MainWindow::on_recherche2_textChanged(const QString &arg1)
{
    QString ch = arg1;

                         if (ch=="")
                         {
                             ui->table->setModel(p.afficher());
                         }
                         else
                         {
                           ui->table->setModel(p.afficher_catrech(ch)) ;
                         }
}

void MainWindow::on_tri_categorie_clicked()
{
    ui->table->setModel(p.tri_Categorie());
}

void MainWindow::on_tri_id_clicked()
{
    ui->table->setModel(p.tri_ID());

}

void MainWindow::on_tri_quantite_clicked()
{
    ui->table->setModel(p.tri_quantite());
}



