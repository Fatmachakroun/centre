#include "personnel.h"

personnel::personnel()
{
    id=0;
    nom_utilisateur="";
    mail="";
    mdp="";
}
personnel::personnel(int id, QString nom_utilisateur,QString mail,QString mdp)
{
    this->id=id;
    this->nom_utilisateur=nom_utilisateur;
    this->mail=mail;
    this->mdp=mdp;
}
personnel::personnel(QString nom_utilisateur,QString mail,QString mdp)
{
    this->nom_utilisateur=nom_utilisateur;
    this->mail=mail;
    this->mdp=mdp;
}
personnel::personnel(QString mail,QString mdp)
{
    this->mail=mail;
    this->mdp=mdp;
}
QString personnel::get_nom_utilisateur(){return nom_utilisateur;}
QString personnel::get_mail(){return mail;}
QString personnel::get_mdp(){return mdp;}
bool personnel::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PERSONNEL (NOM_UTULISATEUR,MAIL,MDP) VALUES (:nom_utilisateur,:mail,:mdp)");
    query.bindValue(":nom_utilisateur",nom_utilisateur);
    query.bindValue(":mail",mail);
    query.bindValue(":mdp",mdp);
    return  query.exec();

}
bool personnel::connecter()
{
    QSqlQuery query;
    query.prepare("select * from PERSONNEL where MAIL = :mail and MDP = :mdp");
    query.bindValue(":mail",mail);
    query.bindValue(":mdp",mdp);
    return  query.exec();

}
