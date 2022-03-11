#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->table->setModel(c.afficher());
    ui->lineEdit_11->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_3->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_6->setValidator(new QIntValidator(0, 999999,this));
    ui->lineEdit_7->setValidator(new QIntValidator(0, 999999,this));


    QRegExp rx("[a-zA-Z,@,.]+");
    QValidator *validator = new
            QRegExpValidator(rx,this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_13->setValidator(validator);
    ui->lineEdit_8->setValidator(validator);
    ui->lineEdit_9->setValidator(validator);
    ui->lineEdit_10->setValidator(validator);
    ui->lineEdit_17->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);


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
    QString prenom =ui->lineEdit_5->text();
    QString email =ui->lineEdit_2->text();
    QString street =ui->lineEdit_13->text();
    QString genre =ui->comboBox->currentText();

    int age =ui->lineEdit_3->text().toInt();

    Client c(nom,prenom,email,street,genre,age);

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
    int id =ui->lineEdit_6->text().toUInt();
    bool test=c.supprimer(id);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimé \n" "click to cancel"),QMessageBox::Cancel);

    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    {
        int id=ui->lineEdit_7->text().toUInt();
        QString nom=ui->lineEdit_8->text();
        QString prenom=ui->lineEdit_9->text();
        QString email=ui->lineEdit_10->text();
        QString street=ui->lineEdit_17->text();
        QString genre=ui->comboBox_2->currentText();

        int age=ui->lineEdit_11->text().toUInt();


        bool test=c.modifier(id,nom,prenom,email,street,genre,age);
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

/*void MainWindow::on_table_activated(const QModelIndex &index)
{
    QString val=ui->table->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from CLIENT1  where id='"+val+"' or nom='"+val+"' or prenom='"+val+"' or email='"+val+"' or street='"+val+"' or genre='"+val+"' or age='"+val+"'");

        if (qry.exec())
        { while (qry.next())
            {
                ui->lineEdit_7->setText(qry.value(0).toString());
                ui->lineEdit_8->setText(qry.value(1).toString());
                ui->lineEdit_9->setText(qry.value(2).toString());
                ui->lineEdit_10->setText(qry.value(3).toString());
                ui->lineEdit_17->setText(qry.value(4).toString());
                ui->comboBox_2->setCurrentText(qry.value(5).toString());
                ui->lineEdit_11->setText(qry.value(6).toString());


                ui->lineEdit_6->setText(qry.value(0).toString()); //pour supprimer


            }
        }
}*/
