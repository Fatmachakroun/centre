#include "client.h"

client::client()
{
    id=0;
    nom_utilisateur="";
    mail="";
    mdp="";
}
client::client(int id, QString nom_utilisateur,QString mail,QString mdp)
{
    this->id=id;
    this->nom_utilisateur=nom_utilisateur;
    this->mail=mail;
    this->mdp=mdp;
}
client::client(QString nom_utilisateur,QString mail,QString mdp)
{
    this->nom_utilisateur=nom_utilisateur;
    this->mail=mail;
    this->mdp=mdp;
}
client::client(QString mail,QString mdp)
{
    this->mail=mail;
    this->mdp=mdp;
}
QString client::get_nom_utilisateur(){return nom_utilisateur;}
QString client::get_mail(){return mail;}
QString client::get_mdp(){return mdp;}
bool client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (NOM_UTULISATEUR,MAIL,MDP) VALUES (:nom_utilisateur,:mail,:mdp)");
    query.bindValue(":nom_utilisateur",nom_utilisateur);
    query.bindValue(":mail",mail);
    query.bindValue(":mdp",mdp);
    return  query.exec();

}
bool client::connecter()
{
    QSqlQuery query;
    query.prepare("select * from CLIENT where MAIL = :mail and MDP = :mdp");
    query.bindValue(":mail",mail);
    query.bindValue(":mdp",mdp);
    return  query.exec();

}
QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_UTULISATEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));

    return model;

}
bool client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE ID = :id");
    query.bindValue(":id",id);
    return query.exec();
}
