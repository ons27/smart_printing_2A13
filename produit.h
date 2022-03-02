#ifndef produit_H
#define produit_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>

// id, nom, category, price, quantity
class produit
{
public:
    produit();
    produit(QString,QString,int,int);
    int get_id();

    void Set_nom(QString val) ;
    QString get_nom();

    void Set_categorie(QString val) ;
    QString get_categorie();

    void Set_prix(int val) ;
    int get_prix();

    void Set_quantite(QString val) ;
    int get_quantite();

    bool ajouter();
    bool  modifier_produit(int,QString,QString,int,int);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();

private:
    int id;
    QString nom;
    QString categorie;
    int prix;
    int quantite;
};

#endif // produit_H
