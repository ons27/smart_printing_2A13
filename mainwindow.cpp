#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include "notification.h"
#include <QMessageBox>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include <QApplication>
#include <QIntValidator>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtCore>



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->ui->stackedWidget->setCurrentIndex(0);
    this->ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton_9->setVisible(false);
    ui->table->setModel(p.afficher());



    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).



}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    qDebug() << "les donees ont ete lus";
    if(data=="1"){
        qDebug() << "1 a ete recu";
       // ui->label_19->setText(data);
        ui->label_19->setText(" Access allowed to an employee "); // si les données reçues de arduino via la liaison série sont égales à 1
        ui->pushButton_9->setVisible(true);

     }
    else
    {
        qDebug() << "0 a ete recu";
       // ui->label_19->setText(data);
        ui->label_19->setText(" Alert : someone is trying to enter the room "); // si les données reçues de arduino via la liaison série sont égales à 1


    }



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

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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
        check4=p.checkchar(nomfournisseurcheck);


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

    QSqlQuery query;
             query.prepare("select prix from produit where prix < 6");
             query.exec();
             query.next();
             int q=query.value(0).toInt();
             QString nomP=query.value(0).toString();
             if(q<=6)
             {
                notification n;
                n.notification_system();
             }

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
    check4=p.checkchar(nomfournisseurcheck);

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
void MainWindow::on_recherche3_textChanged(const QString &arg1)
{
    QString ch = arg1;

                         if (ch=="")
                         {
                             ui->table->setModel(p.afficher());
                         }
                         else
                         {
                           ui->table->setModel(p.afficher_nomrech(ch)) ;
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


QString currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}



void MainWindow::on_pdf_clicked()
{
    {
          QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
          qDebug()<<dir;
          QPdfWriter pdf(dir+"/PdfList.pdf");
                                 QPainter painter(&pdf);
                                int i = 4000;

                                painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/Admin/Desktop/logo.png"));
                                    painter.drawText(900,650,"IPrintz");

                                     //painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Users/Admin/Desktop/logo.png"));

                                     painter.setPen(Qt::red);
                                     painter.setFont(QFont("Time New Roman", 25));
                                     painter.drawText(3000,1400,"Liste Des Produits");
                                     painter.setPen(Qt::black);
                                     painter.setFont(QFont("Time New Roman", 15));
                                     painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                     painter.drawRect(100,3000,9400,500);
                                     painter.setFont(QFont("Time New Roman", 9));
                                     painter.drawText(300,3300,"ID");
                                     painter.drawText(2300,3300,"Category");
                                     painter.drawText(4300,3300,"Quantity");
                                     painter.drawText(6300,3300,"Name");
                                     painter.drawText(7500,3300,"Price");
                                     painter.drawText(8500,3300,"Provider");

                                     painter.drawRect(100,3000,9400,10700);


                                     QTextDocument previewDoc;
                                     QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");


                                     QTextCursor cursor(&previewDoc);



                                     QSqlQuery query;
                                     query.prepare("select * from produits");
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


}


void MainWindow::on_Excel_clicked()
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
                                                 QObject::tr("Export Successfully.\n"
                                                             "Click OK to exit."), QMessageBox::Ok);
                   }
}




void MainWindow::on_statistics_clicked()//Statistiques
{

// set dark background gradient:
    ui->stackedWidget->setCurrentIndex(3);
        QLinearGradient gradient(0, 0, 0, 400);
        gradient.setColorAt(0, QColor(90, 90, 90));
        gradient.setColorAt(0.38, QColor(105, 105, 105));
        gradient.setColorAt(1, QColor(70, 70, 70));
        ui->plot->setBackground(QBrush(gradient));
// create empty bar chart objects:
        QCPBars *barQuantite = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
        barQuantite->setAntialiased(false);
        barQuantite->setStackingGap(1);

        QCPBars *barPrix = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
        barPrix->setAntialiased(false);
        barPrix->setStackingGap(1);
         //couleurs
        barQuantite->setName("Product statistics by QUANTITY");
        barQuantite->setPen(QPen(QColor(219, 129, 129).lighter(130)));
        barQuantite->setBrush(QColor(219, 129, 129));
        barPrix->setName("Product statistics by PRICE");
        barPrix->setPen(QPen(QColor(242, 201, 131).lighter(150)));
        barPrix->setBrush(QColor(242, 201, 131));

// Placer les bars sur elles mêmes
        barQuantite->moveAbove(barPrix);
        barPrix->moveAbove(barQuantite);

         //axe des abscisses
        QVector<double> ticks;
        QVector<QString> labels;
        p.statistique(&ticks,&labels);

        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(ticks, labels);
        ui->plot->xAxis->setTicker(textTicker);
        ui->plot->xAxis->setTickLabelRotation(60);
        ui->plot->xAxis->setSubTicks(false);
        ui->plot->xAxis->setTickLength(0,4);
        ui->plot->xAxis->setRange(0,4);
        ui->plot->xAxis->setBasePen(QPen(Qt::white));
        ui->plot->xAxis->setTickPen(QPen(Qt::white));
        ui->plot->xAxis->grid()->setVisible(true);
        ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        ui->plot->xAxis->setTickLabelColor(Qt::white);
        ui->plot->xAxis->setLabelColor(Qt::white);

        // axe des ordonnées
        ui->plot->yAxis->setRange(0,12.1);
        ui->plot->yAxis->setPadding(5);
        ui->plot->yAxis->setLabel("Statistics");
        ui->plot->yAxis->setBasePen(QPen(Qt::white));
        ui->plot->yAxis->setTickPen(QPen(Qt::white));
        ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
        ui->plot->yAxis->grid()->setSubGridVisible(true);
        ui->plot->yAxis->setTickLabelColor(Qt::white);
        ui->plot->yAxis->setLabelColor(Qt::white);
        ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
        ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

        // ajout des données  (statistiques de la quantité et du prix)//

        QVector<double> PlaceData,PlaceData2;
        QSqlQuery q1("select QUANTITE from PRODUITS");
        QSqlQuery q2("select PRIX_UNITAIRE from PRODUITS");

        while (q1.next()) {
                      int  nbr_fautee = q1.value(0).toInt();
                      PlaceData<< nbr_fautee;
                        }
        while (q2.next()) {
                      int  nbr_fautee = q2.value(0).toInt();
                      PlaceData2<< nbr_fautee;
                        }
        barQuantite->setData(ticks, PlaceData);
        barPrix->setData(ticks, PlaceData2);

//setup legend
        ui->plot->legend->setVisible(true);
        ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
        ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
        ui->plot->legend->setBorderPen(Qt::NoPen);
        QFont legendFont = font();
        legendFont.setPointSize(10);
        ui->plot->legend->setFont(legendFont);
        ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}


void MainWindow::on_statCategorie_clicked()
{
   QSqlQueryModel * model= new QSqlQueryModel();
                             model->setQuery("select * from produits where CATEGORIE = 'VETEMENTS' ");
                             float cat1=model->rowCount();
                             model->setQuery("select * from produits where CATEGORIE = 'PAPIERS' ");
                             float cat2=model->rowCount();
                             model->setQuery("select * from produits where CATEGORIE = 'PHOTOGRAPHIE' ");
                             float cat3=model->rowCount();
                             model->setQuery("select * from produits where CATEGORIE = 'ENCRE' ");
                             float cat4=model->rowCount();
                             model->setQuery("select * from produits where CATEGORIE = 'AUTRES' ");
                             float cat5=model->rowCount();
                             float total=cat1+cat2+cat3+cat4+cat5;
                             QString a=QString("VETEMENTS "+QString::number((cat1*100)/total,'f',2)+"%" );
                             QString b=QString("PAPIERS "+QString::number((cat2*100)/total,'f',2)+"%" );
                             QString c=QString("PHOTOGRAPHIE "+QString::number((cat3*100)/total,'f',2)+"%" );
                             QString d=QString("ENCRE "+QString::number((cat4*100)/total,'f',2)+"%" );
                             QString e=QString("AUTRES "+QString::number((cat5*100)/total,'f',2)+"%" );

                             QPieSeries *series = new QPieSeries();
                             series->append(a,cat1);
                             series->append(b,cat2);
                             series->append(c,cat3);
                             series->append(d,cat4);
                             series->append(e,cat5);

                     if (cat1!=0)
                     {QPieSlice *slice = series->slices().at(0);
                      slice->setLabelVisible();
                      slice->setPen(QPen());}
                     if (cat2!=0)
                     {
                              // Add label, explode and define brush for 2nd slice
                              QPieSlice *slice1 = series->slices().at(1);
                              //slice1->setExploded();
                              slice1->setLabelVisible();
                     }
                     if(cat3!=0)
                     {
                              // Add labels to rest of slices
                              QPieSlice *slice2 = series->slices().at(2);
                              slice2->setLabelVisible();
                     }
                     if(cat4!=0)
                     {
                              // Add labels to rest of slices
                              QPieSlice *slice3 = series->slices().at(3);
                              slice3->setLabelVisible();
                     }
                     if(cat5!=0)
                     {
                              // Add labels to rest of slices
                              QPieSlice *slice4 = series->slices().at(4);
                              slice4->setLabelVisible();
                     }
                             // Create the chart widget
                             QChart *chart = new QChart();
                             // Add data to chart with title and hide legend
                             chart->addSeries(series);
                             chart->setTitle("Pourcentage Produits : nombre de Produits : "+ QString::number(total));
                             chart->legend()->hide();
                             // Used to display the chart
                             QChartView *chartView = new QChartView(chart);
                             chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->resize(1000,500);
                             chartView->show();




}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_10_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    A.write_to_arduino("1");
}
