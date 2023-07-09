#include "playerinfoui.h"
#include "ui_playerinfoui.h"
#include "qmessagebox.h"
#include "game.h"
#include "player.h"

extern Game *game;
PlayerInfoUI::PlayerInfoUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerInfoUI)
{
    ui->setupUi(this);
    this->Parent = parent;
    for(int i = 0; i < game->Tanks.length(); i++)
    {
        ui->CmbTankPlayerOne->addItem(game->Tanks[i].GetName());
        ui->CmbTankPlayerTwo->addItem(game->Tanks[i].GetName());
    }
    for(int i = 0; i < game->Maps.length(); i++)
    {
        ui->CmbMap->addItem(game->Maps[i].GetName());
    }
}

PlayerInfoUI::~PlayerInfoUI()
{
    delete ui;
}

void PlayerInfoUI::on_CmbTankPlayerOne_currentIndexChanged(const QString &arg1)
{
    for(int i = 0; i < game->Tanks.length(); i++)
    {
        if(game->Tanks[i].GetName() == arg1)
        {
            ui->LblTankNameOne->setText("Name : " + game->Tanks[i].GetName());
            ui->LblTankSpeedOne->setText("Speed : " + QString::number(game->Tanks[i].GetSpeed()));
            ui->LblTankPowerOne->setText("bullet Power : " + QString::number(game->Tanks[i].GetPower()));
            ui->LblTankShildOne->setText("Sheild : " + QString::number(game->Tanks[i].GetShild()));
            QString result = "Color : ";
            switch (game->Tanks[i].GetColor())
            {
            case 1:
                result += "Red";
                break;
            case 2:
                result += "Green";
                break;
            case 3:
                result += "Yellow";
                break;
            case 4:
                result += "Black";
                break;
            case 5:
                result += "Blue";
                break;
            }
            ui->LblTankColorOne->setText(result);
            break;
        }
    }
}

void PlayerInfoUI::on_CmbTankPlayerTwo_currentIndexChanged(const QString &arg1)
{
    for(int i = 0; i < game->Tanks.length(); i++)
    {
        if(game->Tanks[i].GetName() == arg1)
        {
            ui->LblTankNameTwo->setText("Name : " + game->Tanks[i].GetName());
            ui->LblTankSpeedTwo->setText("Speed : " + QString::number(game->Tanks[i].GetSpeed()));
            ui->LblTankPowerTwo->setText("bullet Power : " + QString::number(game->Tanks[i].GetPower()));
            ui->LblTankShildTwo->setText("Sheild : " + QString::number(game->Tanks[i].GetShild()));
            QString result = "Color : ";
            switch (game->Tanks[i].GetColor())
            {
            case 1:
                result += "Red";
                break;
            case 2:
                result += "Green";
                break;
            case 3:
                result += "Yellow";
                break;
            case 4:
                result += "Black";
                break;
            case 5:
                result += "Blue";
                break;
            }
            ui->LblTankColorTwo->setText(result);
            break;
        }
    }
}

void PlayerInfoUI::on_BtnPlay_clicked()
{
    if(ui->TxtNamePlayerOne->text().trimmed() == "")
    {
        QMessageBox::question(this, "Message", "Please Enter Player One Name", QMessageBox::Ok);
        ui->TxtNamePlayerOne->setFocus();
    }
    else if(ui->TxtNamePlayerTwo->text().trimmed() == "")
    {
        QMessageBox::question(this, "Message", "Please Enter Player Two Name", QMessageBox::Ok);
        ui->TxtNamePlayerTwo->setFocus();
    }
    else
    {
        int tankOne = -1, tankTwo = -1;
        for(int i = 0; i < game->Tanks.length(); i++)
        {
            if(game->Tanks[i].GetName() == ui->CmbTankPlayerOne->currentText())
            {
                tankOne = i;
            }

            if(game->Tanks[i].GetName() == ui->CmbTankPlayerTwo->currentText())
            {
                tankTwo = i;
            }
        }
        int mapIndex = -1;
        for(int i = 0; i < game->Maps.length(); i++)
        {
            if(game->Maps[i].GetName() == ui->CmbMap->currentText())
            {
                mapIndex = i;
                break;
            }
        }
        Player *playerOne = new Player(ui->TxtNamePlayerOne->text().trimmed(), &game->Tanks[tankOne], true);
        Player *playerTwo = new Player(ui->TxtNamePlayerTwo->text().trimmed(), &game->Tanks[tankTwo], false);
        game->Start(playerOne, playerTwo, mapIndex, this->Parent);
        StartGame = true;
        this->close();
    }
}
