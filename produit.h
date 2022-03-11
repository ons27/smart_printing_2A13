#ifndef produit_H
#define produit_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>


class produit
{
public:
    //setters
    void Set_nom(QString val) ;
    void Set_categorie(QString val) ;
    void Set_prix(int val) ;
    void Set_quantite(int val) ;
    //getters
    int get_id();
    QString get_categorie();
    QString get_nom();
    int get_prix();
    int get_quantite();
    int get_idfournisseur(QString nomfournisseur);

    //constructeurs
    produit();
    produit(QString,QString,int,int,int);


    bool ajouter();

   bool  modifier_produit(int,QString,QString,int,int,int);

    bool supprimer(int idd);
    QSqlQueryModel * afficher();

    bool checkchar(QString);
        bool checkint(QString);

void on_recherche_textChanged(const QString &arg1);
void on_recherche2_textChanged(const QString &arg1);

    QSqlQueryModel *afficher_idrech(QString);
    QSqlQueryModel *afficher_catrech(QString);

    QSqlQueryModel *tri_Categorie();
    QSqlQueryModel *tri_ID();
    QSqlQueryModel *tri_quantite();





private:
    int id;
    QString nom;
    QString categorie;
    int prix;
    int quantite;
    int idfournisseur;
};

#endif // produit_H
