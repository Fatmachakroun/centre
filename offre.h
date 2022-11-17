#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class offre
{
public:
    offre();
    offre(int);
    offre(int,QString,QString,int);
    offre(QString,QString,int);
    QString get_nom_offre();
    QString get_description();
    int get_id();
    int get_prix();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);
    QSqlQueryModel * rechercher(QString);
private:
    QString nom_offre, description;
    int id, prix;
};

#endif // OFFRE_H

