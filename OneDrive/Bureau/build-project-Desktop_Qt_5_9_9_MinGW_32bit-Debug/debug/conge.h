#ifndef CONGE_H
#define CONGE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include <QDialog>

class Conge
{
    QString nomc, prenomc,emailc;
    QString datefin,datedebut;
    int idc;


public:
   //constructeur
Conge(){}
Conge(int,QString,QString,QString,QString,QString);
//getters
QString getnom(){return nomc;}
QString getprenom(){return prenomc;}
QString getemailc(){return emailc;}

int getid(){return idc;}
QString getdatefin(){return datefin;}
QString getdatedebut(){return datedebut;}
//Settters
void Setnom(QString n){nomc=n;}
void Setprenom(QString p){prenomc=p;}
void setemailc(QString e){emailc=e;}

void Setid(int id){this->idc=id;}
void setdatefin(QString des){datefin=des;}
void setdatedebut(QString dep){datedebut=dep;}
// Fonctionnalites de base relative a l'entie   abonnement
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
bool modifier(int);


};
#endif // CONGE_H
