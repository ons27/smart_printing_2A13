#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //affichage
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(4);
    ui->table->setModel(e.afficher());
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
