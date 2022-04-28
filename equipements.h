#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>


class equipement
{
public:
    equipement();
    equipement(QString,QString,float,QString);
    int get_id();
    void Set_nom(QString val) ;
    QString get_nom();
    void Set_marque(QString val) ;
    QString get_marque();
    void Set_etat(QString val) ;
    QString get_etat();
    void Set_prix(float val) ;
    float get_prix();
    bool ajouter();
    bool  modifier_equipement(int,QString,QString,int,QString);
    bool supprimer(int idd);
    bool check (int id );
    QSqlQueryModel * afficher();
    QSqlQueryModel * trie_id();
    QSqlQueryModel * trie_nom();
    QSqlQueryModel * trie_prix();
    QSqlQueryModel * chercher_id(QString input);
    void notification(QString);
    void Signal();
private:
    int id;
    QString nom;
    QString marque;
    QString etat;
    int prix;
};

#endif // EQUIPEMENTS_H
