#include "produit.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include <QSqlRecord>

/*#include<QSqlQuery>
#include<QObject>
#include<QtDebug>*/


using namespace std;


produit::produit()
{
   nom=" ";
   categorie=" ";
   prix=0;
   quantite=0;
   idfournisseur=0;
}


produit::produit(QString nom,QString categorie,int prix,int quantite,int idfournisseur)
{

   this->nom=nom.toUpper();
   this->categorie=categorie.toUpper();
   this->prix=prix;
   this->quantite=quantite;
    this->idfournisseur=idfournisseur;
}

void produit::Set_nom(QString val) { nom = val; }
void produit::Set_categorie(QString val) { nom = val; }
void produit::Set_prix(int val) { nom = val; }
void produit::Set_quantite(int val) { nom = val; }

int produit::get_id(){return id;}
QString produit::get_nom(){return nom;}
QString produit:: get_categorie(){return categorie;}
int produit::get_prix(){return prix;}
int produit::get_quantite(){return quantite;}




bool produit::ajouter()
{
    QSqlQuery query;  //variable d'accees à la BD
    QString res = QString::number(id);
    query.prepare("INSERT INTO produits (categorie,quantite,nom,prix_unitaire,ID_FOURNISSEUR)"
                        "VALUES (:categorie, :quantite,  :nom,  :prix, :idfournisseur)");               //thez mel classe li fel QT lel BD
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);
    query.bindValue(":idfournisseur",idfournisseur);
    return query.exec();
}

int produit::get_idfournisseur(QString nomfournisseur)                 //Tekhou esm fournisseur w trajaalk el id mteeo
{


     QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select ID_FOURNISSEUR from FOURNISSEURS where NOM='"+nomfournisseur+"'");
   int idf =  model->record(0).value("ID_FOURNISSEUR").toInt();

   return idf;

 }

QSqlQueryModel *produit::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM produits");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("Name"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("Category"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("Price"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("Quantity"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("Provider"));
 return model;
}


bool produit::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from produits where ID_PRODUITS = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}

bool produit :: modifier_produit(int id,QString nom,QString categorie,int prix,int quantite,int idfournisseur)
{

    QSqlQuery query;
        query.prepare("UPDATE produits set nom=(?),categorie=(?),prix_unitaire=(?),quantite=(?), id_fournisseur=(?) where ID_PRODUITS=(?) ");

        query.addBindValue(nom);
        query.addBindValue(categorie);
        query.addBindValue(prix);
        query.addBindValue(quantite);
        query.addBindValue(idfournisseur);
        query.addBindValue(id);


   return  query.exec();
}

bool produit::checkint(QString x) //verifier si la valeur saisie est int ou float
 {
 bool check=true;
 if(x.isEmpty())
 {
     check=false;
     return check;
     }
 else
 {
     for(int i=0;i<x.size();i++)
     {

       if(x[i].isLetter())
         {
          check=false;
          break;
         }
     }
 }

 return check;

 }

 bool produit::checkchar(QString x) //verifier si la valeur est string
 {
 bool check=true;
 if(x.isEmpty())
 {
     check=false;
     return check;
     }
 else
 {
     for(int i=0;i<x.size();i++)
     {

         if(x[i].isDigit())
         {
          check=false;
          break;
         }
     }
 }

 return check;

 }

QSqlQueryModel *produit::afficher_idrech(QString q)
{
         QString res= QString::number(id);
         QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM produits  WHERE ID_PRODUITS like '%"+q+"%'" );
          model->setHeaderData (0, Qt:: Horizontal,QObject::tr ("ID"));
          model->setHeaderData (3, Qt::Horizontal,QObject::tr("Name"));
          model->setHeaderData (1, Qt:: Horizontal,QObject::tr ("Category"));
          model->setHeaderData (4, Qt:: Horizontal,QObject::tr ("Price"));
          model->setHeaderData (2, Qt:: Horizontal,QObject::tr ("Quantity"));

          return model;
    }


QSqlQueryModel *produit::afficher_catrech(QString q)
{
         QString res= categorie;
         QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM produits  WHERE categorie like '%"+q+"%'" );
          model->setHeaderData (0, Qt:: Horizontal,QObject::tr ("ID"));
          model->setHeaderData (3, Qt::Horizontal,QObject::tr("Name"));
          model->setHeaderData (1, Qt:: Horizontal,QObject::tr ("Category"));
          model->setHeaderData (4, Qt:: Horizontal,QObject::tr ("Price"));
          model->setHeaderData (2, Qt:: Horizontal,QObject::tr ("Quantity"));

          return model;
    }
QSqlQueryModel *produit::afficher_nomrech(QString q)
{
         QString res= nom;
         QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM produits  WHERE nom like '%"+q+"%'" );
          model->setHeaderData (0, Qt:: Horizontal,QObject::tr ("ID"));
          model->setHeaderData (3, Qt::Horizontal,QObject::tr("Name"));
          model->setHeaderData (1, Qt:: Horizontal,QObject::tr ("Category"));
          model->setHeaderData (4, Qt:: Horizontal,QObject::tr ("Price"));
          model->setHeaderData (2, Qt:: Horizontal,QObject::tr ("Quantity"));

          return model;
    }



QSqlQueryModel * produit::tri_Categorie()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM produits ORDER BY categorie ASC ");
    model->setHeaderData (0, Qt:: Horizontal,QObject::tr ("ID"));
    model->setHeaderData (3, Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData (1, Qt:: Horizontal,QObject::tr ("Category"));
    model->setHeaderData (4, Qt:: Horizontal,QObject::tr ("Price"));
    model->setHeaderData (2, Qt:: Horizontal,QObject::tr ("Quantity"));

    return model;

}
QSqlQueryModel * produit::tri_ID()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM produits ORDER  BY CAST (ID_PRODUITS as number) ");
    model->setHeaderData (0, Qt:: Horizontal,QObject::tr ("ID"));
    model->setHeaderData (3, Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData (1, Qt:: Horizontal,QObject::tr ("Category"));
    model->setHeaderData (4, Qt:: Horizontal,QObject::tr ("Price"));
    model->setHeaderData (2, Qt:: Horizontal,QObject::tr ("Quantity"));
    return model;

}


QSqlQueryModel * produit::tri_quantite()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM produits ORDER BY quantite ASC");
    model->setHeaderData (0, Qt:: Horizontal,QObject::tr ("ID"));
    model->setHeaderData (3, Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData (1, Qt:: Horizontal,QObject::tr ("Category"));
    model->setHeaderData (4, Qt:: Horizontal,QObject::tr ("Price"));
    model->setHeaderData (2, Qt:: Horizontal,QObject::tr ("Quantity"));
    return model;

}


void produit::statistique(QVector<double>* ticks,QVector<QString> *labels)
 {
     QSqlQuery q;
     int i=0;
     q.exec("select NOM from PRODUITS");
     while (q.next())
     {
         QString identifiant = q.value(0).toString();
         i++;
         *ticks<<i;
         *labels <<identifiant;
     }
 }


