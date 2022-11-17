#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(int,QString,QString,QString);
    client(QString,QString,QString);
    client(QString,QString);
    QString get_nom_utilisateur();
    QString get_mail();
    QString get_mdp();
    bool ajouter();
    bool connecter();
    QSqlQueryModel * afficher();
    bool supprimer (int);

private:
    QString nom_utilisateur, mail, mdp ;
    int id;
};

#endif // CLIENT_H
