#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "smtp.h"
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
        ui->lineEdit->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_3->clear();
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


void MainWindow::on_table_activated(const QModelIndex &index)
{
    QString val=ui->table->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from CLIENT1  where ID='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or EMAIL='"+val+"' or STREET='"+val+"' or GENRE='"+val+"' or AGE='"+val+"'");

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
}

void MainWindow::on_Psearch_4_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM CLIENT1 WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or PRENOM  LIKE'"+arg1+"%' or EMAIL LIKE'"+arg1+"%' or STREET  LIKE'"+arg1+"%' or GENRE  LIKE'"+arg1+"%' or AGE  LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->table->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !!\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->Psearch_4->clear();}
}

void MainWindow::on_Tri_IdE_2_clicked()
{
    ui->table->setModel(c.tri());
}

void MainWindow::on_Tri_Taille_2_clicked()
{
    ui->table->setModel(c.tri_age());

}

void MainWindow::on_Tri_Taille_3_clicked()
{
    ui->table->setModel(c.tri_nom());

}

void MainWindow::on_Tri_Taille_4_clicked()
{
    ui->table->setModel(c.tri_prenom());
}


void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("ibrahim.khedhiri@esprit.tn", "zpeejnaakttbrhfr","smtp.gmail.com",465,30000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("Client", ui->lineEdit_25->text() , ui->lineEdit_24->text(),ui->textEdit_8->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void MainWindow::on_sendBtn_6_clicked()
{
    connect(ui->sendBtn_6, SIGNAL(clicked()),this, SLOT(sendMail()));
}


void MainWindow::on_Mailing_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_PdfBtn_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_mailing_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_PdfBtn_2_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




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







void MainWindow::on_PdfBtn_5_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




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

void MainWindow::on_PdfBtn_6_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




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

void MainWindow::on_PdfBtn_4_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
              qDebug()<<dir;
              QPdfWriter pdf(dir+"/PdfList.pdf");
                                     QPainter painter(&pdf);
                                    int i = 4000;



                                         painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Qt/iprintz.png"));
                                         //painter.drawPixmap(100,100,780,780,"iprintz");
                                         painter.drawText(900,650,"IPrintz");
                                         painter.setPen(Qt::red);
                                         painter.setFont(QFont("Time New Roman", 25));
                                         painter.drawText(3000,1400,"Liste Des Clients");
                                         painter.setPen(Qt::black);
                                         painter.setFont(QFont("Time New Roman", 15));
                                         painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                         painter.drawRect(100,3000,9400,500);
                                         painter.setFont(QFont("Time New Roman", 9));
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"NOM");
                                         painter.drawText(4300,3300,"PRENOM");
                                         painter.drawText(6300,3300,"EMAIL");
                                         painter.drawText(7500,3300,"ADRESSE");
                                         painter.drawText(8500,3300,"AGE");

                                         painter.drawRect(100,3000,9400,10700);

                                         /*painter.setPen(Qt::red);
                                         painter.setFont(QFont("Times", 50));
                                         painter.drawRect(1000,200,6500,2000);
                                         painter.drawRect(0,3000,9600,500);
                                         painter.setFont(QFont("Arial", 9));
                                         painter.setPen(Qt::black);
                                         painter.drawText(300,3300,"ID");
                                         painter.drawText(2300,3300,"Category");
                                         painter.drawText(4300,3300,"Quantity");
                                         painter.drawText(6300,3300,"Name");
                                         painter.drawText(7500,3300,"Price");
                                         painter.drawText(8500,3300,"Provider");*/


                                         QTextDocument previewDoc;
                                         QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");




                                         QTextCursor cursor(&previewDoc);



                                         QSqlQuery query;
                                         query.prepare("select * from CLIENT1");
                                         query.exec();
                                         while (query.next())
                                         {
                                             painter.drawText(300,i,query.value(0).toString());
                                             painter.drawText(2300,i,query.value(1).toString());
                                             painter.drawText(4300,i,query.value(2).toString());
                                             painter.drawText(6300,i,query.value(3).toString());
                                             painter.drawText(7500,i,query.value(4).toString());
                                             painter.drawText(8500,i,query.value(5).toString());




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
