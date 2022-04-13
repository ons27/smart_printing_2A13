#ifndef fournisseurs_H
#define fournisseurs_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QMessageBox>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QUrl>
#include <QPixmap>



class fournisseurs
{
public:
    fournisseurs();
    fournisseurs(QString,QString,QString,QString,int);
    int get_id();
    void Set_nom(QString val) ;
    QString get_nom();
    void Set_prenom(QString val) ;
    QString get_prenom();
    void Set_email(QString val) ;
    QString get_email();
    void Set_adresse(QString val) ;
    QString get_adresse();
    void Set_num_tel(int val);
    int get_num_tel();

    bool ajouter();
    bool  modifier_fournisseurs(int,QString,QString,QString,QString,int);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
QSqlQueryModel * afficher_fournisseurs_trierf();
QSqlQueryModel * afficher_fournisseurs_trierfn();
QSqlQueryModel * afficher_fournisseurs_trierfa();

private:
    int id;
    QString nom;
    QString prenom;
    QString adresse;
    QString email;
    int num_tel;

};


#endif // fournisseurs_H
