#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet_2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("aze");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
