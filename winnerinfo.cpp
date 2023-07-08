#include "winnerinfo.h"
#include "ui_winnerinfo.h"

WinnerInfo::WinnerInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerInfo)
{
    ui->setupUi(this);
}

WinnerInfo::~WinnerInfo()
{
    delete ui;
}
