#include "magasin.h"
#include "ui_magasin.h"
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#include <QPrinter>
magasin::magasin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::magasin)
{
    ui->setupUi(this);
}

magasin::~magasin()
{
    delete ui;
}

void magasin::on_pushButton_clicked()
{
     ui->tableView->setModel(tmp.afficher());
}


void magasin::on_pushButton_2_clicked()
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


void magasin::on_pushButton_trier_clicked()
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


void magasin::on_pushButton_rechercher_clicked()
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


void magasin::on_pushButton_stat_clicked()
{
    S =new statistique();
    S->show();
}

