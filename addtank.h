#ifndef ADDTANK_H
#define ADDTANK_H

#include <QDialog>
#include "Tank.h"

namespace Ui {
class AddTank;
}

class AddTank : public QDialog
{
    Q_OBJECT

public:
    explicit AddTank(QWidget *parent = nullptr);
    ~AddTank();
    Tank *tank;
    bool result;
private slots:
    void on_BtnOk_clicked();

private:
    Ui::AddTank *ui;
};

#endif // ADDTANK_H
