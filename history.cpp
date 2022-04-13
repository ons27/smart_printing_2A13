#include "history.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QObject>
#include<QDate>
/*
history::history()
{

}
history::history(QString b)
 {
    operation=b;
 }

void history::Ajouter()
{
    QSqlQuery query;


    query.prepare("insert into HISTORIQUE(ID_HISTO,DATE_HISTO,TYPE_OPERATION) values(HISTORIQUE_SEQ.nextval, sysdate, :operation)");
   query.bindValue(":operation",operation);


 query.exec();
}
QSqlQueryModel * history::Afficher( )
{
  QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select DATE_HISTORY, TYPE_OPERATION from HISTORIQUE ;");
       model->setHeaderData(0, Qt::Horizontal,QObject:: tr("date et heure"));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Operation"));

 return model;
}*/
