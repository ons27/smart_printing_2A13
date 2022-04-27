#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQueryModel>
#include <QTextBrowser>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>

class Employee
{
public:
    //constructeurs
    Employee();
    Employee(QString,QString,QString,int,int);
//getters :
    QString getnom();
    QString getprenom();
    QString getemail ();
    int getage ();
    int getid();
    int getsalaire();
//setters
    void setnom (QString);
    void setprenom (QString);
    void setemail (QString);
    void setage(int);
    void setsalaire(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int id);
    bool modifier(int,QString,QString,QString,int,int);
    QSqlQueryModel * tri();
        QSqlQueryModel * tri1();
        QSqlQueryModel * tri2();

          QSqlQueryModel* RechercheByNom(QString);
          QSqlQueryModel* RechercheByPrenom(QString);
          QSqlQueryModel* RechercheByemail(QString);



//ss
 private:
    QString nom , prenom , email;
 int age ,id, salaire ;
};

#endif // EMPLOYEE_H