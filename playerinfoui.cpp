#include "playerinfoui.h"
#include "ui_playerinfoui.h"

PlayerInfoUI::PlayerInfoUI(QList<Tank> tanks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerInfoUI)
{
    ui->setupUi(this);
    this->Tanks = tanks;
    for(int i = 0; i < this->Tanks.length(); i++)
    {
        ui->CmbTankPlayerOne->addItem(this->Tanks[i].GetName());
        ui->CmbTankPlayerTwo->addItem(this->Tanks[i].GetName());
    }
}

PlayerInfoUI::~PlayerInfoUI()
{
    delete ui;
}
