#include "fournisseurs.h"
#include "produit.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include <QMessageBox>
#include <QPdfWriter>
#include <QDesktopServices>



using namespace std;


fournisseurs::fournisseurs()
{
   nom=" ";
   prenom=" ";
   email=" ";
   adresse=" ";
   num_tel=0;
}


fournisseurs::fournisseurs(QString nom,QString prenom,QString email,QString adresse,int num_tel)
{

   this->nom=nom.toUpper();
   this->prenom=prenom.toUpper();
   this->email=email.toUpper();
   this->adresse=adresse.toUpper();
   this->num_tel=num_tel;

}

int fournisseurs::get_id(){return id;}
void fournisseurs::Set_nom(QString val) { nom = val; }
QString fournisseurs::get_nom(){return nom;}
void fournisseurs::Set_prenom(QString val) { prenom = val; }
QString fournisseurs::get_prenom(){return prenom;}
void fournisseurs::Set_email(QString val) { email = val; }
QString fournisseurs:: get_email(){return email;}
void fournisseurs::Set_adresse(QString val) { adresse = val; }
QString fournisseurs::get_adresse(){return adresse;}
void fournisseurs::Set_num_tel(int val) { num_tel = val; }
int fournisseurs::get_num_tel(){return num_tel;}


bool fournisseurs::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD

    query.prepare("INSERT INTO fournisseurs (NOM,PRENOM,EMAIL,ADRESSE,NUM_TEL)"
                          "VALUES ( :nom, :prenom, :email, :adresse, :num_tel)");  //thez mel classe li fel QT lel BD

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":num_tel",num_tel);
    return query.exec();
}
QSqlQueryModel * fournisseurs::afficher_fournisseurs_trierf()
{
    QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from FOURNISSEURS ORDER BY ID_FOURNISEUR");
       model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISEUR"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("EMAIL"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("NUM_TEL"));
       model->setHeaderData(5, Qt::Horizontal,QObject::tr("ADRESSE"));
       return model;
}

QSqlQueryModel * fournisseurs::afficher_fournisseurs_trierfn()
{
    QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from FOURNISSEURS ORDER BY NOM");
       model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISEUR"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("EMAIL"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("NUM_TEL"));
       model->setHeaderData(5, Qt::Horizontal,QObject::tr("ADRESSE"));
       return model;
}

QSqlQueryModel * fournisseurs::afficher_fournisseurs_trierfa()
{
    QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from FOURNISSEURS ORDER BY ADRESSE");
       model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISEUR"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("EMAIL"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("NUM_TEL"));
       model->setHeaderData(5, Qt::Horizontal,QObject::tr("ADRESSE"));
       return model;
}

QSqlQueryModel *fournisseurs::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM fournisseurs");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISEUR"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("EMAIL"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("NUM_TEL"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("ADRESSE"));
 return model;
}


bool fournisseurs::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from fournisseurs where ID_FOURNISEUR = :id ");
    query.bindValue(":id",id);
    return query.exec();

}


bool fournisseurs :: modifier_fournisseurs(int id,QString nom,QString prenom,QString email,QString adresse,int num_tel)
{
    QSqlQuery qry;
        qry.prepare("UPDATE fournisseurs set NOM=(?),PRENOM=(?),EMAIL=(?),ADRESSE=(?),NUM_TEL=(?) where ID_FOURNISEUR=(?) ");
        qry.addBindValue(nom);
        qry.addBindValue(prenom);
        qry.addBindValue(email);
        qry.addBindValue(adresse);
        qry.addBindValue(num_tel);
        qry.addBindValue(id);
   return  qry.exec();
}




