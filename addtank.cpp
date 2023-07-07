#include "addtank.h"
#include "ui_addtank.h"
#include "qmessagebox.h"

AddTank::AddTank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTank)
{
    ui->setupUi(this);
}

AddTank::~AddTank()
{
    delete ui;
}

void AddTank::on_BtnOk_clicked()
{
}
