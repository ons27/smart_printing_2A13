#ifndef INTERVENTIONS_H
#define INTERVENTIONS_H


#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>


class interventions
{
public:
    interventions();
    interventions(QString,QString,int,int);
    int get_id();
    void Set_type(QString val) ;
    QString get_type();
    void Set_etat(QString val) ;
    QString get_etat();
    void Set_id_eq(int val) ;
    int get_id_eq();
    void Set_id_emp(int val) ;
    int get_id_emp();
    QSqlQueryModel * afficher();
    bool ajouter();
    bool  modifier_interventions(int,QString,QString);
    bool supprimer(int idd);
private:
    int id;
    QString type;
    QString etat;
    int id_eq;
    int id_emp;
};
#endif // INTERVENTIONS_H
