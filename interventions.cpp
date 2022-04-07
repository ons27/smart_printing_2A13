#include "interventions.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QString>
#include <QFile>
#include <QTextDocument>
#include<QTextStream>
#include<QIODevice>
#include<QDate>
#include <QSystemTrayIcon>


using namespace std;


interventions::interventions()
{
   type=" ";
   etat=" ";
   id_eq=0;
   id_emp=0;
}

interventions::interventions(QString type,QString etat,int id_eq,int id_emp)
{

   this->type=type.toUpper();
   this->etat=etat;
   this->id_eq=id_eq;
   this->id_emp=id_emp;
}


int interventions::get_id(){return id;}
void interventions::Set_type(QString val) { type = val; }
QString interventions::get_type(){return type;}
void interventions::Set_etat(QString val) { etat = val; }
QString interventions:: get_etat(){return etat;}
void interventions::Set_id_eq(int val) { id_eq = val; }
int interventions::get_id_eq(){return id_eq;}
void interventions::Set_id_emp(int val) { id_emp = val; }
int interventions::get_id_emp(){return id_emp;}


bool interventions::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    query.prepare("INSERT INTO interventions (TYPE_INT,ETAT_INT,ID_EQ,ID_EMP)"
                          "VALUES (:type, :etat, :id_eq, :id_emp)");
    query.bindValue(":type",type);
    query.bindValue(":etat",etat);
    query.bindValue(":id_eq",id_eq);
    query.bindValue(":id_emp",id_emp);
    return query.exec();
}


QSqlQueryModel *interventions::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM interventions");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("ID_EQ"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_EMP"));
 return model;
}


bool interventions::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from interventions where ID_INT = :id ");
    query.bindValue(":id",idd);
    return query.exec();
}


bool interventions :: modifier_interventions(int id,QString type,QString etat)
{
        QSqlQuery qry;
        qry.prepare("UPDATE interventions set TYPE_INT=(?),ETAT_INT=(?) where ID_EQ=(?) ");
        qry.addBindValue(type);
        qry.addBindValue(etat);
        qry.addBindValue(id);
        return  qry.exec();
}


