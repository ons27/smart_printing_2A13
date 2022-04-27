#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPdfWriter>
#include <QPainter>
#include "conge.h"
#include <QPrinter>
#include <QTextDocument>
#include "QtSql/QSqlRecord"
#include <QDate>
#include<QFileDialog>
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
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->age=age;
    this->salaire=salaire;;
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
void Employee::setsalaire(int salaire){this->salaire=salaire;}

void Employee::setage(int age){this->age=age;}


bool Employee::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
   // QString age_string=QString::number(age);
    //QString salaire_string=QString::number(salaire);
       //prepare la requette sql apre elle envoyer au base de donnee
         query.prepare("INSERT INTO EMPLOYEE (nom, prenom,email,age,salaire ) "
                       "VALUES (:nom, :prenom, :email, :age,:salaire )");
         //query.bindValue(":id", id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":email", email);
          query.bindValue(":age", salaire);
         query.bindValue(":salaire", age);



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
model ->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));




    return model;
}

bool Employee::modifier(int id,QString nom, QString prenom, QString email, int age, int salaire)
{

    QSqlQuery query;
        query.prepare("UPDATE Employee SET nom=:nom,prenom=:prenom,email=:email,age=:age,salaire=:salaire where ID=(?) ");
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(email);
         query.addBindValue(salaire);
        query.addBindValue(age);

         query.addBindValue(id);

   return  query.exec();
}




QSqlQueryModel * Employee::tri()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY CAST(salaire AS number)");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));




    return model;
}
QSqlQueryModel * Employee::tri1()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY CAST(age AS number)");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));




    return model;
}
QSqlQueryModel * Employee::tri2()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY CAST(id AS number)");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));




    return model;
}




QSqlQueryModel* Employee::RechercheByemail(QString r)
{
   QString res= email;

        QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM Employee WHERE email like '%"+r+"%'");
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));

    return model;
}


QSqlQueryModel* Employee::RechercheByNom(QString r)
{
   QString res= nom;
        QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM Employee WHERE nom like '%"+r+"%'");
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));

    return model;
}



QSqlQueryModel* Employee::RechercheByPrenom(QString r)
{
     QString res= prenom;
        QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM Employee WHERE prenom like '%"+r+"%'");//retourner l'adresse dans la base de donnee
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model ->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));

    return model;
}





