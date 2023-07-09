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
    bool flag = true;
    bool dirFlag = true;
    int Direction;
public slots:
    void set_flag();
    void set_dirFlag();
    QString GetName();
    int GetHealth();
    void ChangeDirection(int direction);
    void BeingShot(int firePower);
    void Fire();
    void SetImage();
};

#endif // PLAYER_H
