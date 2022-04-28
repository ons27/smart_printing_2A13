#ifndef CONJEE_H
#define CONJEE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include <QDialog>

class Congee
{
    QString nom, prenom,email;
    QString date_fin,date_debut;
    int id;


public:
   //constructeur
Congee(){}
Congee(int,QString,QString,QString,QString,QString);
//getters
QString getnom(){return nom;}
QString getprenom(){return prenom;}
QString getemailc(){return email;}

int getid(){return id;}
QString getdatefin(){return date_fin;}
QString getdatedebut(){return date_debut;}
//Settters
void Setnom(QString n){nom=n;}
void Setprenom(QString p){prenom=p;}
void setemailc(QString e){email=e;}

void Setid(int id){this->id=id;}
void setdatefin(QString des){date_fin=des;}
void setdatedebut(QString dep){date_debut=dep;}
// Fonctionnalites de base relative a l'entie   abonnement
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
bool modifier(int);


};
#endif // CONJEE_H
