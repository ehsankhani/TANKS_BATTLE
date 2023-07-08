#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "map.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game:public QGraphicsView
{
private:
    Player *PlayerOne;
    Player *PlayerTwo;
    Map *Board;
public:
    QGraphicsScene *scene;
    Game(Player *playerOne, Player *playerTwo, Map *board, QWidget *parent=0);
};

#endif // GAME_H
