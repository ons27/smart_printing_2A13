#include "commandes.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include <QTextBrowser>
#include <QFileDialog>
#include<QMessageBox>
#include <QtPrintSupport/QPrinter>

using namespace std;


commandes::commandes()
{
    id=0;
   adresse=" ";
   quantite=0;
   prix_unitaire=0;
   prix_total=0;
   id_clients=0;
      id_empl=0;
      id_produits=0;


}


commandes::commandes(QString adresse,int quantite,int prix_unitaire,int prix_total,int id_clients,int id_empl,int id_produits)
{

   this->adresse=adresse.toUpper();
  this->prix_unitaire=prix_unitaire;
    this->prix_total=prix_total;
   this->quantite=quantite;
    this->id_clients=id_clients;
    this->id_empl=id_empl;
this->id_produits=id_produits;

}


int commandes::get_id(){return id;}
void commandes::Set_adresse(QString val) { adresse = val; }
QString commandes::get_adresse(){return adresse;}

void commandes::Set_prix_unitaire(int val) { prix_unitaire = val; }
int commandes:: get_prix_unitaire(){return prix_unitaire;}

void commandes::Set_prix_total(int val) { prix_total = val; }
int commandes::get_prix_total(){return prix_total;}

void commandes::Set_quantite(int val) { quantite = val; }
int commandes::get_quantite(){return quantite;}
void commandes::set_id_clients(int val) { id_clients = val; }
int commandes::get_id_clients(){return id_clients;}

void commandes::set_id_empl(int val) { id_empl = val; }
int commandes::get_id_empl(){return id_empl;}

void commandes::set_id_produits(int val) { id_produits = val; }
int commandes::get_id_produits(){return id_produits;}



bool commandes::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    //QString res = QString::number(id);
    query.prepare("INSERT INTO commandes (adresse,prix_unitaire,prix_total,quantite,id_clients,id_empl,id_produits)"
                          "VALUES (:adresse, :prix_unitaire, :prix_total, :quantite, :id_clients, :id_empl, :id_produits)");  //thez mel classe li fel QT lel BD
    //query.bindValue(":ID_COMMANDES",id);//
    query.bindValue(":adresse",adresse);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":prix_total",prix_total);
    query.bindValue(":quantite",quantite);
    query.bindValue(":id_clients",id_clients);
          query.bindValue(":id_empl",id_empl);
           query.bindValue(":id_produits",id_produits);

    return query.exec();
}


QSqlQueryModel *commandes::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM commandes");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("adresse"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix_unitaire"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix_total"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("date"));
 model->setHeaderData(6, Qt::Horizontal,QObject::tr("id_clients"));
  model->setHeaderData(7, Qt::Horizontal,QObject::tr("id_empl"));
  model->setHeaderData(8, Qt::Horizontal,QObject::tr("id_produits"));


 return model;
}


bool commandes::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from commandes where ID_COMMANDES = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}


bool commandes::modifier_commandes(int id, QString adresse,int quantite,int prix_unitaire,int prix_total,int id_clients,int id_empl,int id_produits)
{

    QSqlQuery qry;
        qry.prepare("UPDATE commandes set adresse=(?),quantite=(?),prix_unitaire=(?),prix_total=(?),id_clients=(?),id_empl=(?),id_produits=(?) where ID_COMMANDES=(?) ");
        qry.addBindValue(adresse);
        qry.addBindValue(prix_unitaire);
        qry.addBindValue(quantite);
        qry.addBindValue(prix_total);
        qry.addBindValue(id_clients);
        qry.addBindValue(id_empl);
         qry.addBindValue(id_produits);

        qry.addBindValue(id);
   return  qry.exec();
}
/*QSqlQueryModel * commandes::trier_par_quantite()
{
QSqlQuery * q = new  QSqlQuery ();
                 QSqlQueryModel *model = new  QSqlQueryModel ();
                 model->setQuery("SELECT * FROM commandes order by quantite ASC");
                 q->exec();
                 model->setQuery(*q);
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("quantite"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_unitaire"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_total"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_clients"));
                 model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_empl"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_produits"));
                 return model;
}*/

QSqlQueryModel * commandes::trier_par_quantite()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM commandes ORDER BY quantite ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix_unitaire"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix_total"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("id_clients"));
     model->setHeaderData(7, Qt::Horizontal,QObject::tr("id_empl"));
     model->setHeaderData(8, Qt::Horizontal,QObject::tr("id_produits"));


    return model;
}
QSqlQueryModel * commandes::trier_par_identifiant()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM commandes ORDER BY ID_commandes ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix_unitaire"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix_total"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("id_clients"));
     model->setHeaderData(7, Qt::Horizontal,QObject::tr("id_empl"));
     model->setHeaderData(8, Qt::Horizontal,QObject::tr("id_produits"));


    return model;
}
QSqlQueryModel * commandes::trier_par_prix()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM commandes ORDER BY PRIX_UNITAIRE ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix_unitaire"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix_total"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("id_clients"));
     model->setHeaderData(7, Qt::Horizontal,QObject::tr("id_empl"));
     model->setHeaderData(8, Qt::Horizontal,QObject::tr("id_produits"));


    return model;
}

QSqlQueryModel * commandes::recherche(const QString id_commandes)
    {

        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from commandes where(id_commandes LIKE '"+id_commandes+"%')");
       // model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("quantite"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("adresse"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix_unitaire"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix_total"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("date"));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("id_clients"));
         model->setHeaderData(6, Qt::Horizontal,QObject::tr("id_empl"));
         model->setHeaderData(7, Qt::Horizontal,QObject::tr("id_produits"));

            return model;

    }
void commandes::exporterpdf(QTextBrowser *text)
    {
      // QString tt;
        QSqlQuery qry;
        std::list<QString> tt;
        qry.exec("select * from commandes");
        while(qry.next())
        {
            tt.push_back("ID_commandes: "+qry.value(0).toString()+"\n"+"quantite "+qry.value(1).toString()+"\n"+"adresse: "+qry.value(2).toString()+"\n"+"prix_unitaire: "+qry.value(3).toString()+"\n"+"prix_total: "+qry.value(4).toString()+"\n"+"id_clients: "+qry.value(5).toString()+"\n"+"id_empl: "+qry.value(6).toString()+"\n"+"id_produits: "+qry.value(7).toString()+"\n");

        }

        for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
        {
            text->setText(text->toPlainText()+*it + "\n");
        }

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        text->print(&printer);
        QMessageBox::information(nullptr, QObject::tr("Export PDF"),
                                  QObject::tr("Export avec succes .\n"
                                              "Click OK to exit."), QMessageBox::Ok);
    }
