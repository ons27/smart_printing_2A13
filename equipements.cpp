#include "equipements.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>


using namespace std;


equipement::equipement()
{
   nom=" ";
   marque=" ";
   prix=0;
   etat=" ";
}

equipement::equipement(QString nom,QString marque,float prix,QString etat)
{

   this->nom=nom.toUpper();
   this->marque=marque.toUpper();
   this->prix=prix;
   this->etat=etat.toUpper();
}


int equipement::get_id(){return id;}
void equipement::Set_nom(QString val) { nom = val; }
QString equipement::get_nom(){return nom;}
void equipement::Set_marque(QString val) { nom = val; }
QString equipement:: get_marque(){return marque;}
void equipement::Set_etat(QString val) { nom = val; }
QString equipement::get_etat(){return etat;}
void equipement::Set_prix(float val) { nom = val; }
float equipement::get_prix(){return prix;}


bool equipement::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    query.prepare("INSERT INTO equipement (NOM,MARQUE,PRIX,ETAT)"
                          "VALUES (:nom, :marque, :prix, :etat)");  //thez mel classe li fel QT lel BD
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":prix",prix);
    query.bindValue(":etat",etat);
    return query.exec();
}


QSqlQueryModel *equipement::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM equipement");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("MARQUE"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("PRIX"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("STATUS"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("DATE"));
 return model;
}


bool equipement::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from equipement where ID_EQ = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}


bool equipement :: modifier_equipement(   int id ,QString nom,QString marque,int prix,QString etat)
{

    QSqlQuery qry;
        qry.prepare("UPDATE equipement set NOM=(?),marque=(?),prix=(?),etat=(?) where ID_EQ=(?) ");
        qry.addBindValue(nom);
        qry.addBindValue(marque);
        qry.addBindValue(prix);
        qry.addBindValue(etat);
         qry.addBindValue(id);
   return  qry.exec();
}

bool equipement::check (int id )
{
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM equipement where ID_EQ= :id");
    qry.bindValue(":id",id);
    return  qry.exec();
}
