#ifndef CONGE_H
#define CONGE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include <QDialog>
#include <QtDebug>
#include <QObject>


class Conge
{
    QString nom, prenom,email;
    QString date_fin,date_debut;
    int id_conge;


public:


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int id_conge);
    bool modifier(int,QString,QString,QString,QString,QString);



   //constructeur
Conge(){}
Conge(int,QString,QString,QString,QString,QString);
//getters
QString getnom(){return nom;}
QString getprenom(){return prenom;}
QString getemail(){return email;}

int getid_conge(){return id_conge;}
QString getdate_fin(){return date_fin;}
QString getdate_debut(){return date_debut;}
//Settters
void Setnom(QString n){nom=n;}
void Setprenom(QString p){prenom=p;}
void setemail(QString e){email=e;}

void Setid(int id_conge){this->id_conge=id_conge;}
void setdate_fin(QString des){date_fin=des;}
void setdate_debut(QString dep){date_debut=dep;}
// Fonctionnalites de base relative a l'entie   abonnement



};

/*
class conge
{
public:
conge();
conge(QString,QString,QString,int,int);
//getters :
QString getnom();
QString getprenom();
QString getemail ();
QString getdate_debut();
QString getdate_fin();
int getid();

//setters
void setnom (QString);
void setprenom (QString);
void setemail (QString);
void setdate_debut (QString);
void setdate_fin (QString);




bool ajouter();
QSqlQueryModel* afficher();
bool supprimer (int id);



private:
   QString nom , prenom , email , date_debut , date_fin;
int id ;
};







*/


#endif // CONGE_H
