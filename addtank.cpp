#include "addtank.h"
#include "ui_addtank.h"
#include "qmessagebox.h"
#include "Tank.h"
#include "game.h"

AddTank::AddTank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTank)
{
    ui->setupUi(this);
    this->result = false;
}

AddTank::~AddTank()
{
    delete ui;
}

extern Game *game;
void AddTank::on_BtnOk_clicked()
{
    QString tankName = ui->TxtName->text().trimmed();
    if(tankName == "")
    {
        QMessageBox::question(this, "Message", "Enter Tank Name", QMessageBox::Ok);
        ui->TxtName->setFocus();
        return;
    }
    try
    {
        QString speed = ui->TxtSpeed->text().trimmed();
        if(speed == "")
        {
            QMessageBox::question(this, "Message", "Enter Tank Speed", QMessageBox::Ok);
            ui->TxtSpeed->setFocus();
            return;
        }
        int tankSpeed = speed.toInt();
        if(tankSpeed >= 1 && tankSpeed <= 5)
        {
            QString power = ui->TxtBulletPower->text().trimmed();
            if(power == "")
            {
                QMessageBox::question(this, "Message", "Enter Tank Power", QMessageBox::Ok);
                ui->TxtBulletPower->setFocus();
                return;
            }
            int tankPower = power.toInt();
            if(tankPower >= 1 && tankPower <= 5)
            {
                QString shild = ui->TxtShild->text().trimmed();
                if(shild == "")
                {
                    QMessageBox::question(this, "Message", "Enter Tank Shild", QMessageBox::Ok);
                    ui->TxtShild->setFocus();
                    return;
                }
                int tankShild = shild.toInt();
                if(tankShild >= 10 && tankShild <= 100)
                {
                    bool find = false;
                    for(int i = 0; i < game->Tanks.length(); i++)
                    {
                        if(game->Tanks[i].GetName() == tankName)
                        {
                            find = true;
                            break;
                        }
                    }
                    if(find)
                    {
                        QMessageBox::question(this, "Message", "A tank with this name has already been registered", QMessageBox::Ok);
                        ui->TxtName->setFocus();
                        return;
                    }
                    this->tank = new Tank(tankName, tankSpeed, tankPower, tankShild, ui->CmbColor->currentIndex() + 1);
                    result = true;
                    QMessageBox::question(this, "Message", "Tank information saved successfully", QMessageBox::Ok);
                    this->close();
                }
                else
                {
                    QMessageBox::question(this, "Message", "Tank shild tolerance should be between 10 and 100", QMessageBox::Ok);
                    ui->TxtShild->setFocus();
                }
            }
            else
            {
                QMessageBox::question(this, "Message", "The firepower of the tank should be between 1 and 5", QMessageBox::Ok);
                ui->TxtBulletPower->setFocus();
            }
        }
        else
        {
            QMessageBox::question(this, "Message", "Tank speed should be between 1 and 5", QMessageBox::Ok);
            ui->TxtSpeed->setFocus();
        }
    }
    catch(QString)
    {
        QMessageBox::question(this, "Message", "The information entered is invalid", QMessageBox::Ok);
    }
}
