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
    int Direction;
    bool FirstPlayer;
    void SetImage();
public:
    Tank *tank;
    Player(QString name, Tank *tank, bool firstPlayer, QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    QString GetName();
    int GetHealth();
    void ChangeDirection(int direction);
    void BeingShot(int firePower);
    bool flag = true;
    bool dirFlag = true;
public slots:
    void set_flag();
    void set_dirFlag();
};

#endif // PLAYER_H
