#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(QString,QString,QString,QString,QString,int);

    QString getnom();
    QString getprenom();
    QString getemail ();
    QString getstreet();
    QString getgenre();
    int getage ();
    int getid();

    void setnom (QString);
    void setprenom (QString);
    void setemail (QString);
    void setstreet(QString);
    void setgenre(QString);
    void setage(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel * tri();
    QSqlQueryModel * tri_age();
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * tri_prenom();



    bool supprimer (int id);
    bool modifier(int,QString,QString,QString,QString,QString,int);


 private:
    QString nom , prenom , email , street, genre;
    int age ,id ;
};

#endif // CLIENT_H
