#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game:public QGraphicsView
{
private:
    Player *PlayerOne;
    Player *PlayerTwo;
public:
    QGraphicsScene *scene;
    Game(Player *playerOne, Player *playerTwo, QWidget *parent=0);
};

#endif // GAME_H
