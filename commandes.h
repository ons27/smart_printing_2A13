#ifndef Commandes_H
#define Commandes_H

#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>
#include <QTextBrowser>
#include <QFileDialog>
#include<QMessageBox>

#include <QtPrintSupport/QPrinter>

class commandes
{
public:

    commandes();
    commandes(QString,int,int,int,int,int,int);
    int get_id();
    void Set_adresse(QString val) ;
    QString get_adresse();
    void Set_prix_unitaire(int val) ;
    int get_prix_unitaire();
    void Set_prix_total(int val) ;
    int get_prix_total();
    void Set_quantite(int val) ;
    int get_quantite();
    void set_id_clients(int val);
        int get_id_clients();
        void set_id_empl(int val);
        int get_id_empl();
        void set_id_produits(int val);
        int get_id_produits();

    bool ajouter();
    bool  modifier_commandes(int, QString,int,int,int,int,int,int);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
    QSqlQueryModel * trier_par_quantite();
    QSqlQueryModel * trier_par_identifiant();
    QSqlQueryModel * trier_par_prix();
    QSqlQueryModel * recherche(const QString id_commandes);
    void exporterpdf(QTextBrowser *text);

private:
    int id;
    int quantite;
    QString adresse;
    int prix_unitaire;
    int prix_total;
    int id_clients, id_empl,id_produits;

};

#endif // commandes_H
