#ifndef MAGASIN_H
#define MAGASIN_H
#include "offre.h"
#include "client.h"
#include "statistique.h"
#include <QWidget>

namespace Ui {
class magasin;
}

class magasin : public QWidget
{
    Q_OBJECT

public:
    explicit magasin(QWidget *parent = nullptr);
    ~magasin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_stat_clicked();

private:
    Ui::magasin *ui;
    offre tmp;
    statistique *S;
    client cmp;
};

#endif // MAGASIN_H
