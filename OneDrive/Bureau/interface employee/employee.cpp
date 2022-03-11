#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>

using namespace std;

Employee::Employee()
{
id=0;nom=" ";
prenom=" ";
email=" ";
salaire=0;
age=0;
}

Employee::Employee(QString nom , QString prenom, QString  email,int age, int salaire  )
{
    this->nom=nom;this->prenom=prenom;this->email=email;this->age=age;this->salaire=salaire;;
}

QString Employee::getnom(){return nom;}
QString Employee::getprenom(){return prenom;}
QString Employee::getemail (){return email;}
int Employee::getage (){return age;}
int Employee::getid(){return id;}
int Employee::getsalaire(){return salaire; }
void Employee::setnom (QString nom){this->nom=nom;}
void Employee::setprenom (QString prenom){this->prenom=prenom;}
void Employee::setemail (QString email){this->email=email;}
void Employee::setage(int age){this->age=age;}

void Employee::setsalaire(int salaire){this->salaire=salaire;}

bool Employee::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
   // QString age_string=QString::number(age);
    //QString salaire_string=QString::number(salaire);

         query.prepare("INSERT INTO EMPLOYEE (nom, prenom,email,age,salaire ) "
                       "VALUES (:nom, :prenom, :email, :age,:salaire )");
         //query.bindValue(":id", id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":email", email);
         query.bindValue(":salaire", age);
         query.bindValue(":age", salaire);


         return query.exec();
}



bool Employee::supprimer(int id )
{   QSqlQuery query;


         query.prepare("delete from EMPLOYEE where id=:id");
         query.bindValue(":id", id);


         return query.exec();




}
QSqlQueryModel* Employee::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM EMPLOYEE ORDER BY id");

    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));



    return model;
}

bool Employee::modifier(int id,QString nom, QString prenom, QString email, int age, int salaire)
{

    QSqlQuery query;
        query.prepare("UPDATE Employee SET nom=:nom,prenom=:prenom,email=:email,age=:age,salaire=:salaire where ID=(?) ");
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(email);
        query.addBindValue(age);
         query.addBindValue(salaire);
 query.addBindValue(id);

   return  query.exec();
}



