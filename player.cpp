#include "player.h"
#include "qstring.h"
#include "Tank.h"

Player::Player(QString name, Tank *tank, int health)
{
    this->Name = name;
    this->tank = tank;
    this->Health = health;
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
