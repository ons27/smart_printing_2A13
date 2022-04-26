#include "conge.h"
#include"employee.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QObject>
#include <QSqlQuery>
#include <QtDebug>

#include <QSqlQueryModel>


Conge::Conge(int id_conge,QString nom,QString prenom,QString email,QString date_debut,QString date_fin)
{
    this->id_conge=id_conge;

    this->date_debut=date_debut;
     this->email=email;
    this->nom=nom;
    this->prenom=prenom;
    this->date_fin=date_fin;


}
bool Conge::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id_conge);

    //prepare() prend la requete en paramaetre pour la preparer a l'execution.
    query.prepare("INSERT INTO conge (date_debut,date_fin,id_conge,nom,prenom,email) "
                  "VALUES (:date_debut,:date_fin, :id_conge, :nom ,:prenom ,:email )");
    query.bindValue(":id_conge", res);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":email", email);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
     query.bindValue(":date_fin", date_fin);


    return query.exec();
}
















QSqlQueryModel * Conge::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from conge");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id_conge"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("date_debut"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("date_fin"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("email"));
    return model;
}
bool Conge::supprimer(int id_conge)
{
    QSqlQuery query;
    //QString res=QString::number(id_conge);
       query.prepare("DELETE FROM conge WHERE id_conge= :id_conge");
       query.bindValue(":id_conge",id_conge);
       return  query.exec();
}
bool Conge::modifier( int id_conge,QString nom,QString prenom,QString email,QString date_debut,QString date_fin)
{




    QSqlQuery query;
        query.prepare("UPDATE Conge SET nom=:nom,prenom=:prenom,email=:email,date_debut=:date_debut,date_fin=:date_fin where id_conge=(?) ");
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(email);
         query.addBindValue(date_debut);
        query.addBindValue(date_fin);

         query.addBindValue(id_conge);

   return  query.exec();


}












/*
using namespace std;

conge::conge()
{
id=0;nom=" ";
prenom=" ";
email=" ";
date_fin="";
date_debut="";
}

conge:: conge (QString nom , QString prenom, QString  email,QString date_debut,QString date_fin )
{
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->date_fin=date_fin;
    this->date_debut=date_debut;
}

QString conge::getnom(){return nom;}
QString conge::getprenom(){return prenom;}
QString conge::getemail (){return email;}
QString conge::getdate_fin(){return date_fin; }
int conge::getid(){return id;}
QString conge::getdate_debut(){return date_debut; }
void conge::setnom (QString nom){this->nom=nom;}
void conge::setprenom (QString prenom){this->prenom=prenom;}
void conge::setemail (QString email){this->email=email;}

void conge::setdate_fin (QString date_fin){this->date_fin=date_fin;}
void conge::setdate_debut (QString date_debut){this->date_debut=date_debut;}
bool conge::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
   // QString age_string=QString::number(age);
    //QString salaire_string=QString::number(salaire);
       //prepare la requette sql apre elle envoyer au base de donnee
         query.prepare("INSERT INTO EMPLOYEE (nom, prenom,email,age,salaire ) "
                       "VALUES (:nom, :prenom, :email, :date_debut,:date_fin )");
         //query.bindValue(":id", id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":email", email);
         query.bindValue(":date_fin", date_fin);
         query.bindValue(":date_debut", date_debut);



         return query.exec();
}


bool conge::supprimer(int id )
{   QSqlQuery query;


         query.prepare("delete from EMPLOYEE where id=:id");
         query.bindValue(":id", id);


         return query.exec();




}
QSqlQueryModel*  conge::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM EMPLOYEE ORDER BY id");

    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("date_debut"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("date_fin"));




    return model;
}*/























