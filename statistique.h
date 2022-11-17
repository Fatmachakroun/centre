#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QWidget>
#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class statistique;
}

class statistique : public QWidget
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
    void makePolt();

private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H
