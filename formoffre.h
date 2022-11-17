#ifndef FORMOFFRE_H
#define FORMOFFRE_H
#include "offre.h"
#include "client.h"
#include <QWidget>
#include "statistique.h"
namespace Ui {
class FormOffre;
}

class FormOffre : public QWidget
{
    Q_OBJECT

public:
    explicit FormOffre(QWidget *parent = nullptr);
    ~FormOffre();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_ajouter_offre_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_supprimer_4_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_rechercher_4_clicked();

    void on_pushButton_trier_4_clicked();

private:
    Ui::FormOffre *ui;
    offre tmp;
    client cmp;
    statistique *S;
};

#endif // FORMOFFRE_H
