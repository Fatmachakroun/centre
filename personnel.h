#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class personnel
{
public:
    personnel();
    personnel(int,QString,QString,QString);
    personnel(QString,QString,QString);
    personnel(QString,QString);
    QString get_nom_utilisateur();
    QString get_mail();
    QString get_mdp();
    bool ajouter();
    bool connecter();

private:
    QString nom_utilisateur, mail, mdp ;
    int id;
};

#endif // PERSONNEL_H
