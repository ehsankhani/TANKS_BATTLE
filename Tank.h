#ifndef TANK_H
#define TANK_H
#include "qstring.h"

class Tank
{
private:
    QString Name;
    int Speed;
    int Power;
    int Shild;
    int Color;
public:
    Tank(QString name, int speed, int power, int shild, int color);
    QString GetName();
    int GetSpeed();
    int GetPower();
    int GetShild();
    int GetColor();
    void WriteInFile();
};

#endif // TANK_H
