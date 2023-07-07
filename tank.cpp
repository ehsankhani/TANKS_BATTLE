#include "Tank.h"

Tank::Tank(QString name, int speed, int power, int shild, int color)
{
    this->Name = name;
    this->Speed = speed;
    this->Power = power;
    this->Shild = shild;
    this->Color = color;
}

QString Tank::GetName()
{
    return this->Name;
}

int Tank::GetSpeed()
{
    return this->Speed;
}

int Tank::GetPower()
{
    return this->Power;
}

int Tank::GetShild()
{
    return this->Shild;
}

int Tank::GetColor()
{
    return this->Color;
}
