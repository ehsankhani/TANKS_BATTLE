#include "addtank.h"
#include "ui_addtank.h"
#include "qmessagebox.h"
#include "Tank.h"

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
            QMessageBox::question(this, "لطفا سرعت تانک را وارد کنید", "پیغام", QMessageBox::Ok);
            ui->TxtSpeed->setFocus();
            return;
        }
        int tankSpeed = speed.toInt();
        if(tankSpeed >= 1 && tankSpeed <= 5)
        {
            QString power = ui->TxtBulletPower->text().trimmed();
            if(power == "")
            {
                QMessageBox::question(this, "لطفا قدرت شلیک تانک را وارد کنید", "پیغام", QMessageBox::Ok);
                ui->TxtBulletPower->setFocus();
                return;
            }
            int tankPower = power.toInt();
            if(tankPower >= 1 && tankPower <= 5)
            {
                QString shild = ui->TxtShild->text().trimmed();
                if(shild == "")
                {
                    QMessageBox::question(this, "لطفا تحمل زره تانک را وارد کنید", "پیغام", QMessageBox::Ok);
                    ui->TxtShild->setFocus();
                    return;
                }
                int tankShild = shild.toInt();
                if(tankShild >= 10 && tankShild <= 100)
                {
                    this->tank = new Tank(tankName, tankSpeed, tankPower, tankShild, ui->CmbColor->currentIndex() + 1);
                    result = true;
                    QMessageBox::question(this, "اطلاعات تانک با موفقیت ذخیره شد", "پیغام", QMessageBox::Ok);
                    this->close();
                }
                else
                {
                    QMessageBox::question(this, "تحمل زره تانک باید بین 10 تا 100 باشد", "پیغام", QMessageBox::Ok);
                    ui->TxtShild->setFocus();
                }
            }
            else
            {
                QMessageBox::question(this, "قدرت شلیک تانک باید بین 1 تا 5 باشد", "پیغام", QMessageBox::Ok);
                ui->TxtBulletPower->setFocus();
            }
        }
        else
        {
            QMessageBox::question(this, "سرعت تانک باید بین 1 تا 5 باشد", "پیغام", QMessageBox::Ok);
            ui->TxtSpeed->setFocus();
        }
    }
    catch(QString)
    {
        QMessageBox::question(this, "اطلاعات وارد شده نامعتبر است", "پیغام", QMessageBox::Ok);
    }
}
