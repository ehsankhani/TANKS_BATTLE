#include "player.h"
#include "qstring.h"
#include "Tank.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

Player::Player(QString name, Tank *tank, bool firstPlayer, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->FirstPlayer = firstPlayer;
    this->Name = name;
    this->tank = tank;
    this->Health = tank->GetShild();
    if(this->FirstPlayer)
    {
        if(tank->GetColor() == 1)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Red_Down.png"));
        }
        else if(tank->GetColor() == 2)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Green_Down.png"));
        }
        else if(tank->GetColor() == 3)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Yellow_Down.png"));
        }
        else if(tank->GetColor() == 4)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Black_Down.png"));
        }
        else
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Blue_Down.png"));
        }
    }
    else
    {
        if(tank->GetColor() == 1)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Red_UP.png"));
        }
        else if(tank->GetColor() == 2)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Green_UP.png"));
        }
        else if(tank->GetColor() == 3)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Yellow_UP.png"));
        }
        else if(tank->GetColor() == 4)
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Black_UP.png"));
        }
        else
        {
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Blue_UP.png"));
        }
    }
    QTimer *flagtimer = new QTimer();
    connect(flagtimer, SIGNAL(timeout()), this, SLOT(set_flag()));
    flagtimer -> start(1000);
}

QString Player::GetName()
{
    return this->Name;
}
int Player::GetHealth()
{
    return this->Health;
}

void Player::BeingShot(int firePower)
{
    this->Health -= firePower;
}

void Player::keyPressEvent(QKeyEvent *event)
{

}

void Player::set_flag()
{
    flag = true;
}
