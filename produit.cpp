#include "produit.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>


using namespace std;


produit::produit()
{
   nom=" ";
   categorie=" ";
   prix=0;
   quantite=0;
}


produit::produit(QString nom,QString categorie,int prix,int quantite)
{

   this->nom=nom.toUpper();
   this->categorie=categorie.toUpper();
   this->prix=prix;
   this->quantite=quantite;
}


int produit::get_id(){return id;}
void produit::Set_nom(QString val) { nom = val; }
QString produit::get_nom(){return nom;}
void produit::Set_categorie(QString val) { nom = val; }
QString produit:: get_categorie(){return categorie;}
void produit::Set_prix(int val) { nom = val; }
int produit::get_prix(){return prix;}
void produit::Set_quantite(QString val) { nom = val; }
int produit::get_quantite(){return quantite;}



bool produit::ajouter()
{
    QSqlQuery query;  //variable d'accees à la BD
    QString res = QString::number(id);
    query.prepare("INSERT INTO produits (id_produits,categorie,quantite,nom,prix_unitaire)"
                          "VALUES (:id, :categorie, :quantite,  :nom,  :prix)");               //thez mel classe li fel QT lel BD
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);
    return query.exec();
}


QSqlQueryModel *produit::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM produits");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("categorie"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("quantite"));


 //model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("Delete"));
 return model;
}


bool produit::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from produits where ID_PRODUITS = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}


bool produit :: modifier_produit(int id,QString nom,QString categorie,int prix,int quantite)
{

    QSqlQuery qry;
        qry.prepare("UPDATE produits set nom=(?),categorie=(?),prix_unitaire=(?),quantite=(?) where ID_PRODUITS=(?) ");
        qry.addBindValue(nom);
        qry.addBindValue(categorie);
        qry.addBindValue(prix);
        qry.addBindValue(quantite);
         qry.addBindValue(id);
   return  qry.exec();
}

