#include "conge.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QObject>


Conge::Conge(int idc,QString nomc,QString prenomc,QString emailc,QString datedebut,QString datefin)
{
    this->idc=idc;
    this->nomc=nomc;
    this->prenomc=prenomc;
    this->emailc=emailc;
      this->datedebut=datedebut;
    this->datefin=datefin;


}
bool Conge::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idc);

    //prepare() prend la requete en paramaetre pour la preparer a l'execution.
    query.prepare("INSERT INTO conge (datedebut,datefin,idc,nomc,prenomc,emailc) "
                  "VALUES (:datedebut,:datefin, :idc, :nomc ,:prenomc ,:emailc )");
    query.bindValue(":idc", res);
    query.bindValue(":nomc", nomc);
    query.bindValue(":prenomc", prenomc);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":emailc", emailc);
     query.bindValue(":datefin", datefin);


    return query.exec();
}
QSqlQueryModel * Conge::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from conge");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("datefin"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("email"));
    return model;
}
bool Conge::supprimer(int idc)
{
    QSqlQuery query;
    QString res=QString::number(idc);
       query.prepare("DELETE FROM conge WHERE idc= :idc");
       query.bindValue(":idc",res);
       return  query.exec();
}
bool Conge::modifier(int idc)
{
    QSqlQuery query;
    QString res = QString::number(idc);
    query.prepare("UPDATE conge SET datedebut:=datedebut,datefin:=datefin,idc:=idc,nomc:=nomc,prenomc:=prenomc,emailc:=emailc");
    query.bindValue(":idc", res);
    query.bindValue(":nomc", nomc);
    query.bindValue(":prenomc", prenomc);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":emailc", emailc);
    return query.exec();
}


