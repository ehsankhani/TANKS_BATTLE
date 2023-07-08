#include "player.h"
#include "qstring.h"
#include "Tank.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

Player::Player(QString name, Tank *tank, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->Name = name;
    this->tank = tank;
    this->Health = tank->GetShild();
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

void Player::set_flag()
{
    flag = true;
}
