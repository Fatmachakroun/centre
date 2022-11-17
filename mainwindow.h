#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "offre.h"
#include "formoffre.h"
#include "personnel.h"
#include "magasin.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_ajouter_client_clicked();

    void on_connecter_clicked();

    void on_connecter_2_clicked();

private:
    Ui::MainWindow *ui;
    FormOffre *O;
    magasin *M;

};

#endif // MAINWINDOW_H
