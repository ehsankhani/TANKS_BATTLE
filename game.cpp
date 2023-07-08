#include "game.h"
#include "player.h"
#include "wall.h"
#include "boxitem.h"
#include "forest.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

Game::Game(QWidget *parent)
{

}

void Game::Start(Player *playerOne, Player *playerTwo, int mapIndex, QWidget *parent)
{
    this->PlayerOne = playerOne;
    this->PlayerTwo = playerTwo;
    this->MapIndex = mapIndex;
    this->Parent = parent;
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    scene->setBackgroundBrush(QBrush(Qt::white));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(this->Maps[MapIndex].GetBoard()[0].length() * 50 + 5, this->Maps[MapIndex].GetBoard().length() * 50 + 35);
    scene->setSceneRect(0, 0, this->Maps[MapIndex].GetBoard()[0].length() * 50 + 5, this->Maps[MapIndex].GetBoard().length() * 50 + 35);
    view->show();
    this->ShildOne = new MessageItem(this->PlayerOne->GetName() + " : " + QString::number(this->PlayerOne->GetHealth()), this->PlayerOne->tank->GetColor());
    this->ShildTwo = new MessageItem(this->PlayerTwo->GetName() + " : " + QString::number(this->PlayerTwo->GetHealth()), this->PlayerTwo->tank->GetColor());
    this->ShildTwo->setPos(1000, 0);
    scene->addItem(ShildOne);
    scene->addItem(ShildTwo);
    for(int i = 0; i < Maps[MapIndex].GetBoard().length(); i++)
    {
        for(int j = 0; j < Maps[MapIndex].GetBoard()[i].length(); j++)
        {
            if(Maps[MapIndex].GetBoard()[i][j] == 1)
            {
                Wall *wall = new Wall(j * 50, i * 50 + 30);
                scene->addItem(wall);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 2)
            {
                BoxItem *box = new BoxItem(j * 50, i * 50 + 30);
                scene->addItem(box);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 3)
            {
                Forest *forest = new Forest(j * 50, i * 50 + 30);
                scene->addItem(forest);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 5)
            {
                scene->addItem(playerOne);
                playerOne->setFlag(QGraphicsItem::ItemIsFocusable);
                playerOne->setFocus();
                playerOne->setPos(j * 50, i * 50 + 30);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 6)
            {
                scene->addItem(PlayerTwo);
                PlayerTwo->setPos(j * 50, i * 50 + 30);
            }
        }
    }
}

void Game::KeySend(int keyInfo)
{
    int currentXPlayerOne = -1, currentYPlayerOne = -1;
    int currentXPlayerTwo = -1, currentYPlayerTwo = -1;
    for(int i = 0; i < this->Maps[MapIndex].GetBoard().length(); i++)
    {
        for(int j = 0; j < this->Maps[MapIndex].GetBoard()[i].length(); j++)
        {
            if(this->Maps[MapIndex].GetBoard()[i][j] == 5)
            {
                currentXPlayerOne = j;
                currentYPlayerOne = i;
            }
            else if(this->Maps[MapIndex].GetBoard()[i][j] == 6)
            {
                currentXPlayerTwo = j;
                currentYPlayerTwo = i;
            }
        }
    }
    if(currentXPlayerOne == -1 || currentXPlayerTwo == -1)
        return;
    if(keyInfo == Qt::Key_Up)
    {
        if(!PlayerOne->dirFlag || currentYPlayerOne == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerOne - 1][currentXPlayerOne] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne - 1, currentXPlayerOne, 5);
        PlayerOne->ChangeDirection(1);
    }
    else if(keyInfo == Qt::Key_Left)
    {
        if(!PlayerOne->dirFlag || currentXPlayerOne == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerOne][currentXPlayerOne - 1] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne - 1, 5);
        PlayerOne->ChangeDirection(2);
    }
    else if(keyInfo == Qt::Key_Right)
    {
        if(!PlayerOne->dirFlag || currentXPlayerOne + 1 >= this->Maps[MapIndex].GetBoard()[currentYPlayerOne].length() || this->Maps[MapIndex].GetBoard()[currentYPlayerOne][currentXPlayerOne + 1] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne + 1, 5);
        PlayerOne->ChangeDirection(3);
    }
    else if(keyInfo == Qt::Key_Down)
    {
        if(!PlayerOne->dirFlag || currentYPlayerOne + 1 >= this->Maps[MapIndex].GetBoard().length() || this->Maps[MapIndex].GetBoard()[currentYPlayerOne + 1][currentXPlayerOne] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne + 1, currentXPlayerOne, 5);
        PlayerOne->ChangeDirection(4);
    }
    else if(keyInfo == Qt::Key_W)
    {
        if(!PlayerTwo->dirFlag || currentYPlayerTwo == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo - 1][currentXPlayerTwo] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo - 1, currentXPlayerTwo, 6);
        PlayerTwo->ChangeDirection(1);
    }
    else if(keyInfo == Qt::Key_A)
    {
        if(!PlayerTwo->dirFlag || currentXPlayerTwo == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo][currentXPlayerTwo - 1] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo - 1, 6);
        PlayerTwo->ChangeDirection(2);
    }
    else if(keyInfo == Qt::Key_D)
    {
        if(!PlayerTwo->dirFlag || currentXPlayerTwo + 1 >= this->Maps[MapIndex].GetBoard()[currentYPlayerTwo].length() || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo][currentXPlayerTwo + 1] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo + 1, 6);
        PlayerTwo->ChangeDirection(3);
    }
    else if(keyInfo == Qt::Key_S)
    {
        if(!PlayerTwo->dirFlag || currentYPlayerTwo + 1 >= this->Maps[MapIndex].GetBoard().length() || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo + 1][currentXPlayerTwo] != 0)
            return;
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo + 1, currentXPlayerTwo, 6);
        PlayerTwo->ChangeDirection(4);
    }
}
