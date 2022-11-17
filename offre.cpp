#include "offre.h"

offre::offre()
{
nom_offre="";
description="";
prix=0;
}
offre::offre(int id)
{
    this->id=id;
}
offre::offre(int id,QString nom_offre,QString description,int prix)
{
    this->id=id;
    this->nom_offre=nom_offre;
    this->description=description;
    this->prix=prix;
}
offre::offre(QString nom_offre,QString description,int prix)
{
    this->nom_offre=nom_offre;
    this->description=description;
    this->prix=prix;
}
int offre::get_id(){return id;}
QString offre::get_nom_offre(){return nom_offre;}
QString offre::get_description(){return description;}
int offre::get_prix(){return prix;}
bool offre::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO OFFRE (NOM_OFFRE,DESCRIPTION,PRIX) VALUES (:nom_offre,:description,:prix)");
    query.bindValue(":nom_offre",nom_offre);
    query.bindValue(":description",description);
    query.bindValue(":prix",prix);
    return  query.exec();
}
QSqlQueryModel * offre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from OFFRE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OFFRE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
    return model;

}
bool offre::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM OFFRE WHERE ID = :id");
    query.bindValue(":id",id);
    return query.exec();
}
QSqlQueryModel * offre::rechercher(QString nom_offre)
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from OFFRE where NOM_OFFRE = :nom_offre");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OFFRE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
    return model;

}
