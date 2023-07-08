#include "game.h"
#include "player.h"
#include "wall.h"
#include "boxitem.h"
#include "forest.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

Game::Game(Player *playerOne, Player *playerTwo, Map *board, QWidget *parent)
{
    this->PlayerOne = playerOne;
    this->PlayerTwo = playerTwo;
    this->Board = board;
    this->Parent = parent;
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    scene->setBackgroundBrush(QBrush(Qt::white));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(this->Board->GetBoard()[0].length() * 50 + 5, this->Board->GetBoard().length() * 50 + 35);
    scene->setSceneRect(0, 0, this->Board->GetBoard()[0].length() * 50 + 5, this->Board->GetBoard().length() * 50 + 35);
    view->show();
    this->ShildOne = new MessageItem(this->PlayerOne->GetName() + " : " + this->PlayerOne->GetHealth(), this->PlayerOne->tank->GetColor());
    this->ShildTwo = new MessageItem(this->PlayerTwo->GetName() + " : " + this->PlayerTwo->GetHealth(), this->PlayerTwo->tank->GetColor());
    for(int i = 0; i < board->GetBoard().length(); i++)
    {
        for(int j = 0; j < board->GetBoard()[i].length(); j++)
        {
            if(board->GetBoard()[i][j] == 1)
            {
                Wall *wall = new Wall(j * 50, i * 50 + 30);
                scene->addItem(wall);
            }
            else if(board->GetBoard()[i][j] == 2)
            {
                BoxItem *box = new BoxItem(j * 50, i * 50 + 30);
                scene->addItem(box);
            }
            else if(board->GetBoard()[i][j] == 3)
            {
                Forest *forest = new Forest(j * 50, i * 50 + 30);
                scene->addItem(forest);
            }
            else if(board->GetBoard()[i][j] == 5)
            {
                scene->addItem(playerOne);
                playerOne->setFlag(QGraphicsItem::ItemIsFocusable);
                playerOne->setFocus();
                playerOne->setPos(j * 50, i * 50 + 30);
            }
            else if(board->GetBoard()[i][j] == 6)
            {
                scene->addItem(PlayerTwo);
                PlayerTwo->setFlag(QGraphicsItem::ItemIsFocusable);
                PlayerTwo->setFocus();
                PlayerTwo->setPos(j * 50, i * 50 + 30);
            }
        }
    }
}
