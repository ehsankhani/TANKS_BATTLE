#include "player.h"
#include "qstring.h"
#include "Tank.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "game.h"

Player::Player(QString name, Tank *tank, bool firstPlayer, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->FirstPlayer = firstPlayer;
    this->Name = name;
    this->tank = tank;
    this->Health = tank->GetShild();
    if(firstPlayer)
        this->Direction = 4;
    else
        this->Direction = 1;
    this->SetImage();
    QTimer *flagtimer = new QTimer();
    connect(flagtimer, SIGNAL(timeout()), this, SLOT(set_flag()));
    flagtimer -> start(1000);
    QTimer *dirTime = new QTimer();
    connect(dirTime, SIGNAL(timeout()), this, SLOT(set_dirFlag()));
    dirTime -> start(1000 - (this->tank->GetSpeed() * 100));
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

extern Game *game;
void Player::keyPressEvent(QKeyEvent *event)
{
   game->KeySend(event->key());
}

void Player::set_flag()
{
    flag = true;
}

void Player::set_dirFlag()
{
    this->dirFlag = true;
}

void Player::ChangeDirection(int direction)
{
    if(this->dirFlag)
    {
        this->Direction = direction;
        if(direction == 1)
        {
            setPos(x(), y() - 50);
        }
        else if(direction == 2)
        {
            setPos(x() - 50, y());
        }
        else if(direction == 3)
        {
            setPos(x() + 50, y());
        }
        else
        {
            setPos(x(), y() + 50);
        }
        this->SetImage();
        this->dirFlag = false;
    }
}

void Player::SetImage()
{
    if(this->tank->GetColor() == 1)
    {
        if(this->Direction == 1)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Red_UP.png"));
        else if(this->Direction == 2)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Red_Left.png"));
        else if(this->Direction == 3)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Red_Right.png"));
        else
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Red_Down.png"));
    }
    else if(this->tank->GetColor() == 2)
    {
        if(this->Direction == 1)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Green_UP.png"));
        else if(this->Direction == 2)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Green_Left.png"));
        else if(this->Direction == 3)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Green_Right.png"));
        else
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Green_Down.png"));
    }
    else if(this->tank->GetColor() == 3)
    {
        if(this->Direction == 1)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Yellow_UP.png"));
        else if(this->Direction == 2)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Yellow_Left.png"));
        else if(this->Direction == 3)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Yellow_Right.png"));
        else
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Yellow_Down.png"));
    }
    else if(this->tank->GetColor() == 4)
    {
        if(this->Direction == 1)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Black_UP.png"));
        else if(this->Direction == 2)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Black_Left.png"));
        else if(this->Direction == 3)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Black_Right.png"));
        else
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Black_Down.png"));
    }
    else
    {
        if(this->Direction == 1)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Blue_UP.png"));
        else if(this->Direction == 2)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Blue_Left.png"));
        else if(this->Direction == 3)
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Blue_Right.png"));
        else
            setPixmap(QPixmap(":/new/Images/TankImages/Tank_Blue_Down.png"));
    }
}
