#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("data");
db.setUserName("fatma");//inserer nom de l'utilisateur
db.setPassword("fatma");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return  test;

/*else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
*/


}
