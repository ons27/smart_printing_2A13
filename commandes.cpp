#include "commandes.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>


using namespace std;


commandes::commandes()
{

   adresse=" ";
   quantite=0;
   prix_unitaire=0;
   prix_total=0;

}


commandes::commandes(QString adresse,int quantite,int prix_unitaire,int prix_total)
{

   this->adresse=adresse.toUpper();
  this->prix_unitaire=prix_unitaire;
    this->prix_total=prix_total;
   this->quantite=quantite;

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


bool commandes::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    QString res = QString::number(id);
    query.prepare("INSERT INTO commandes (ID_COMMANDES,adresse,prix_unitaire,prix_total,quantite)"
                          "VALUES (:id, :adresse, :prix_unitaire, :prix_total, :quantite)");  //thez mel classe li fel QT lel BD
    query.bindValue(":id",id);
    query.bindValue(":adresse",adresse);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":prix_total",prix_total);
    query.bindValue(":quantite",quantite);
    return query.exec();
}


QSqlQueryModel *commandes::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM commandes");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("quatite"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("adresse"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix_unitaire"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix_total"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("date"));
 return model;
}


bool commandes::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from commandes where ID_COMMANDES = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}


bool commandes::modifier_commandes(QString adresse,int quantite,int prix_unitaire,int prix_total)
{

    QSqlQuery qry;
        qry.prepare("UPDATE commandes set adresse=(?),quantite=(?),prix_unitaire=(?),prix_total=(?) where ID_COMMANDES=(?) ");
        qry.addBindValue(adresse);
        qry.addBindValue(prix_unitaire);
        qry.addBindValue(quantite);
        qry.addBindValue(prix_total);
         qry.addBindValue(id);
   return  qry.exec();
}

