#ifndef PLAYER_H
#define PLAYER_H
#include "qstring.h"
#include "Tank.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QString Name;
    int Health;
    bool FirstPlayer;
public:
    Tank *tank;
    Player(QString name, Tank *tank, bool firstPlayer, QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    QString GetName();
    int GetHealth();
    void ChangeDirection();
    void BeingShot(int firePower);
    bool flag = true;
    bool dirFlag = true;
public slots:
    void set_flag();
};

#endif // PLAYER_H
