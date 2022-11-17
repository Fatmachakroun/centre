#include "formoffre.h"
#include "ui_formoffre.h"
#include <QMessageBox>
FormOffre::FormOffre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOffre)
{
    ui->setupUi(this);
}

FormOffre::~FormOffre()
{
    delete ui;
}

void FormOffre::on_pushButton_clicked()
{
    ui->tableView->setModel(tmp.afficher());
}


void FormOffre::on_pushButton_ajouter_offre_clicked()
{
    QString nom_offre = ui->lineEdit_nomoffre->text();
    QString description = ui->lineEdit_decription->text();
    int prix = ui->lineEdit_prix->text().toInt();
    offre o (nom_offre,description,prix);
    bool test=o.ajouter();
    if(test)
    {
        QMessageBox msgBox;
        msgBox.setText("offre ajoutee avec succes.");
        msgBox.exec();
    }

}


void FormOffre::on_pushButton_supprimer_clicked()
{
   int id = ui->lineEdit_idoffre2->text().toInt();
   bool test = tmp.supprimer(id);
   if(test)
   {
       QMessageBox msgBox;
       msgBox.setText("offre supprimee avec succes.");
       msgBox.exec();
   }
}


/*void FormOffre::on_pushButton_rechercher_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    QString val=ui->lineEdit_nomoffre_3->text();
    val="%"+val+"%";
    request.prepare("SELECT * FROM OFFRE WHERE NOM_OFFRE LIKE:val");
    request.bindValue(":val",val);
    request.exec();
    modal->setQuery(request);
    ui->tableView->setModel(modal);

}
*/

/*void FormOffre::on_pushButton_trier_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
    request.prepare("select * from OFFRE order by NOM_OFFRE DESC");
    request.exec();
    modal->setQuery(request);
    ui->tableView->setModel(modal);
}*/


void FormOffre::on_pushButton_modifier_clicked()
{
   int id= ui->lineEdit_idoffre->text().toInt();
   QString nom_offre=ui->lineEdit_nomoffre_2->text();
   QString description=ui->lineEdit_decription_2->text();
   int prix= ui->lineEdit_prix_2->text().toInt();
   QSqlQuery qry;
   qry.prepare("update OFFRE set NOM_OFFRE=:nom_offre,DESCRIPTION=:description,PRIX=:prix where ID=:id ");
   qry.bindValue(":id",id);
   qry.bindValue(":nom_offre",nom_offre);
   qry.bindValue(":description",description);
   qry.bindValue(":prix",prix);
   qry.exec();
   QMessageBox msgBox;
   msgBox.setText("offre modifiee avec succes.");
   msgBox.exec();
   ui->tableView->setModel(tmp.afficher());//refresh
}


void FormOffre::on_pushButton_stat_clicked()
{
    S =new statistique();
    S->show();
}


void FormOffre::on_pushButton_rechercher_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
           QString type=ui->comboBox_2->currentText();
           if (type=="Nom offre"){
               QString val=ui->lineEdit_recherche->text();
               val="%"+val+"%";
               request.prepare("SELECT * FROM OFFRE WHERE NOM_OFFRE LIKE:val");
               request.bindValue(":val",val);
           }
           else if (type=="ID"){
               int val=ui->lineEdit_recherche->text().toInt();
               request.prepare("SELECT * FROM OFFRE WHERE ID =:val");
               request.bindValue(":val",val);
           }else if (type=="Prix"){
               int val=ui->lineEdit_recherche->text().toInt();
               request.prepare("SELECT * FROM OFFRE WHERE PRIX =:val");
               request.bindValue(":val",val);
           }

           request.exec();
           modal->setQuery(request);
           ui->tableView->setModel(modal);
}


void FormOffre::on_pushButton_trier_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
           QString type=ui->comboBox->currentText();
           if (type=="Nom offre"){
               request.prepare("select * from OFFRE order by NOM_OFFRE DESC ");

           }else if (type=="ID"){
               request.prepare("select * from OFFRE order by ID DESC");
           }else if (type=="Prix"){
               request.prepare("select * from OFFRE order by PRIX DESC");
           }
           request.exec();
           modal->setQuery(request);
           ui->tableView->setModel(modal);
}


void FormOffre::on_pushButton_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tableView->model()->rowCount();
            const int columnCount = ui->tableView->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView->isColumnHidden(column)) {
                        QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
           QTextDocument *document = new QTextDocument();
           document->setHtml(strStream);
           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPageSize(QPageSize::A4);
           printer.setOutputFileName(fileName);
           QTextDocument doc;
           doc.setHtml(document->toPlainText());
            doc.print(&printer);
}


void FormOffre::on_pushButton_3_clicked()
{
    ui->tableView_2->setModel(cmp.afficher());
}


void FormOffre::on_pushButton_supprimer_4_clicked()
{
    int id = ui->lineEdit_idclient->text().toInt();
    bool test = cmp.supprimer(id);
    if(test)
    {
        QMessageBox msgBox;
        msgBox.setText("offre supprimee avec succes.");
        msgBox.exec();
    }
}


void FormOffre::on_pushButton_4_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tableView_2->model()->rowCount();
            const int columnCount = ui->tableView_2->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView_2->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_2->isColumnHidden(column)) {
                        QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
           QTextDocument *document = new QTextDocument();
           document->setHtml(strStream);
           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPageSize(QPageSize::A4);
           printer.setOutputFileName(fileName);
           QTextDocument doc;
           doc.setHtml(document->toPlainText());
            doc.print(&printer);
}


void FormOffre::on_pushButton_rechercher_4_clicked()
{
        QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->comboBox_recherche->currentText();
               if (type=="Nom_utulisateur"){
                   QString val=ui->lineEdit_recherche_client->text();
                   val="%"+val+"%";
                   request.prepare("SELECT * FROM CLIENT WHERE NOM_UTULISATEUR LIKE:val");
                   request.bindValue(":val",val);
               }
               else if (type=="ID"){
                   int val=ui->lineEdit_recherche_client->text().toInt();
                   request.prepare("SELECT * FROM CLIENT WHERE ID =:val");
                   request.bindValue(":val",val);
               }else if (type=="Mail"){
                   QString val=ui->lineEdit_recherche_client->text();
                   request.prepare("SELECT * FROM CLIENT WHERE MAIL =:val");
                   request.bindValue(":val",val);
               }

               request.exec();
               modal->setQuery(request);
               ui->tableView_2->setModel(modal);
}


void FormOffre::on_pushButton_trier_4_clicked()
{
            QSqlQueryModel *modal=new QSqlQueryModel();
                    QSqlQuery request;
                   QString type=ui->comboBox_tri->currentText();
                   if (type=="Nom_utulisateur"){
                       request.prepare("select * from CLIENT order by NOM_UTULISATEUR DESC ");

                   }else if (type=="ID"){
                       request.prepare("select * from CLIENT order by ID DESC");
                   }else if (type=="Mail"){
                       request.prepare("select * from CLIENT order by MAIL DESC");
                   }
                   request.exec();
                   modal->setQuery(request);
                   ui->tableView_2->setModel(modal);
}

