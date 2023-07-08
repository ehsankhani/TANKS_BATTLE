#include "winnerinfo.h"
#include "ui_winnerinfo.h"

WinnerInfo::WinnerInfo(QString playerName, QString tankName, int score, int shild, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerInfo)
{
    ui->setupUi(this);
    ui->LblPlayerName->setText(playerName);
    ui->LblTank->setText(tankName);
    ui->LblScore->setText(QString::number(score));
    ui->LblShild->setText(QString::number(shild));
}

WinnerInfo::~WinnerInfo()
{
    delete ui;
}
