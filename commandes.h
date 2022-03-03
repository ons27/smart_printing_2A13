#ifndef commandesS_H
#define commandesS_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>


class commandes
{
public:
    commandes();
    commandes(QString,int,int,int);
    int get_id();
    void Set_adresse(QString val) ;
    QString get_adresse();
    void Set_prix_unitaire(int val) ;
    int get_prix_unitaire();
    void Set_prix_total(int val) ;
    int get_prix_total();
    void Set_quantite(int val) ;
    int get_quantite();
    bool ajouter();
    bool  modifier_commandes(QString,int,int,int);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
private:
    int id;
    int quantite;
    QString adresse;
    int prix_unitaire;
    int prix_total;
};

#endif // commandes_H
