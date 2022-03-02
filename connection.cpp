#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("yasmine");//inserer nom de l'utilisateur
db.setPassword("yasmine18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
