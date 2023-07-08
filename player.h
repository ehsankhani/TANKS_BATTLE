#ifndef PLAYER_H
#define PLAYER_H
#include "qstring.h"
#include "Tank.h"

class Player
{
private:
    QString Name;
    Tank *tank;
    int Health;
public:
    Player(QString name, Tank *tank, int health);
    QString GetName();
    int GetHealth();
    void BeingShot(int firePower);
};

#endif // PLAYER_H
