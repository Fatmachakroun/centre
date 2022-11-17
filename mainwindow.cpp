#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QTabWidget>
#include <QModelIndexList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nom_utulisateur = ui->nom_utulisateur_personnel->text();
    QString mail = ui->mail_personnel->text();
    QString mdp = ui->mdp_personnel->text();
    personnel p (nom_utulisateur,mail,mdp);
    bool test=p.ajouter();
    if(test)
    {
        QMessageBox msgBox;
        msgBox.setText("Personne ajoutee avec succes.");
        msgBox.exec();
    }

}

void MainWindow::on_pushButton_2_clicked()
{
}


void MainWindow::on_ajouter_client_clicked()
{
    QString nom_utulisateur = ui->nom_utulisateur->text();
    QString mail = ui->lineEdit_mail->text();
    QString mdp = ui->mdp->text();
    client c (nom_utulisateur,mail,mdp);
    bool test=c.ajouter();
    if(test)
    {
        QMessageBox msgBox;
        msgBox.setText("client ajoutee avec succes.");
        msgBox.exec();
    }

}


void MainWindow::on_connecter_clicked()
{
    QString mail = ui->lineEdit_mail_2->text();
    QString mdp = ui->mdp_2->text();
    QSqlQuery rqt;
        if(rqt.exec("SELECT MAIL, MDP FROM CLIENT WHERE MAIL='" + mail + "' AND MDP='" + mdp + "'"))
        {
            if(!rqt.next())
                QMessageBox::warning(this, "Echec !", "Mauvais Mai ou mot de passe");
            else
            {
                QMessageBox msgBox;
                msgBox.setText("client connectee avec succes.");
                msgBox.exec();
                M =new magasin();
                M->show();
            }

        }
}


void MainWindow::on_connecter_2_clicked()
{
    QString mail = ui->mail_personnel_2->text();
    QString mdp = ui->mdp_personnel_2->text();
    QSqlQuery rqt;
        if(rqt.exec("SELECT MAIL, MDP FROM PERSONNEL WHERE MAIL='" + mail + "' AND MDP='" + mdp + "'"))
        {
            if(!rqt.next())
                QMessageBox::warning(this, "Echec !", "Mauvais Mai ou mot de passe");
            else
            {
                QMessageBox msgBox;
                msgBox.setText("personnel connectee avec succes.");
                msgBox.exec();
                O =new FormOffre();
                O->show();
            }

        }
}

