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

void PlayerInfoUI::on_CmbTankPlayerOne_currentIndexChanged(const QString &arg1)
{
    for(int i = 0; i < this->Tanks.length(); i++)
    {
        if(this->Tanks[i].GetName() == arg1)
        {
            ui->LblTankNameOne->setText("نام : " + this->Tanks[i].GetName());
            ui->LblTankSpeedOne->setText("سرعت : " + QString::number(this->Tanks[i].GetSpeed()));
            ui->LblTankPowerOne->setText("قدرت : " + QString::number(this->Tanks[i].GetPower()));
            ui->LblTankShildOne->setText("تحمل زره : " + QString::number(this->Tanks[i].GetShild()));
            QString result = "رنگ : ";
            switch (this->Tanks[i].GetColor())
            {
            case 1:
                result += "قرمز";
                break;
            case 2:
                result += "سبز";
                break;
            case 3:
                result += "زرد";
                break;
            case 4:
                result += "سیاه";
                break;
            case 5:
                result += "آبی";
                break;
            }
            ui->LblTankColorOne->setText(result);
            break;
        }
    }
}

void PlayerInfoUI::on_CmbTankPlayerTwo_currentIndexChanged(const QString &arg1)
{
    for(int i = 0; i < this->Tanks.length(); i++)
    {
        if(this->Tanks[i].GetName() == arg1)
        {
            ui->LblTankNameTwo->setText("نام : " + this->Tanks[i].GetName());
            ui->LblTankSpeedTwo->setText("سرعت : " + QString::number(this->Tanks[i].GetSpeed()));
            ui->LblTankPowerTwo->setText("قدرت : " + QString::number(this->Tanks[i].GetPower()));
            ui->LblTankShildTwo->setText("تحمل زره : " + QString::number(this->Tanks[i].GetShild()));
            QString result = "رنگ : ";
            switch (this->Tanks[i].GetColor())
            {
            case 1:
                result += "قرمز";
                break;
            case 2:
                result += "سبز";
                break;
            case 3:
                result += "زرد";
                break;
            case 4:
                result += "سیاه";
                break;
            case 5:
                result += "آبی";
                break;
            }
            ui->LblTankColorTwo->setText(result);
            break;
        }
    }
}
