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
        QMessageBox::question(this, "پیغام", "لطفا نام تانک را وارد کنید", QMessageBox::Ok);
        ui->TxtName->setFocus();
        return;
    }
    try
    {
        QString speed = ui->TxtSpeed->text().trimmed();
        if(speed == "")
        {
            QMessageBox::question(this, "پیغام", "لطفا سرعت تانک را وارد کنید", QMessageBox::Ok);
            ui->TxtSpeed->setFocus();
            return;
        }
        int tankSpeed = speed.toInt();
        if(tankSpeed >= 1 && tankSpeed <= 5)
        {
            QString power = ui->TxtBulletPower->text().trimmed();
            if(power == "")
            {
                QMessageBox::question(this, "پیغام", "لطفا قدرت شلیک تانک را وارد کنید", QMessageBox::Ok);
                ui->TxtBulletPower->setFocus();
                return;
            }
            int tankPower = power.toInt();
            if(tankPower >= 1 && tankPower <= 5)
            {
                QString shild = ui->TxtShild->text().trimmed();
                if(shild == "")
                {
                    QMessageBox::question(this, "پیغام", "لطفا تحمل زره تانک را وارد کنید", QMessageBox::Ok);
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
                        QMessageBox::question(this, "پیغام", "تانکی با این اسم قبلا ثبت شده است", QMessageBox::Ok);
                        ui->TxtName->setFocus();
                        return;
                    }
                    this->tank = new Tank(tankName, tankSpeed, tankPower, tankShild, ui->CmbColor->currentIndex() + 1);
                    result = true;
                    QMessageBox::question(this, "پیغام", "اطلاعات تانک با موفقیت ذخیره شد", QMessageBox::Ok);
                    this->close();
                }
                else
                {
                    QMessageBox::question(this, "پیغام", "تحمل زره تانک باید بین 10 تا 100 باشد", QMessageBox::Ok);
                    ui->TxtShild->setFocus();
                }
            }
            else
            {
                QMessageBox::question(this, "پیغام", "قدرت شلیک تانک باید بین 1 تا 5 باشد", QMessageBox::Ok);
                ui->TxtBulletPower->setFocus();
            }
        }
        else
        {
            QMessageBox::question(this, "پیغام", "سرعت تانک باید بین 1 تا 5 باشد", QMessageBox::Ok);
            ui->TxtSpeed->setFocus();
        }
    }
    catch(QString)
    {
        QMessageBox::question(this, "پیغام", "اطلاعات وارد شده نامعتبر است", QMessageBox::Ok);
    }
}
