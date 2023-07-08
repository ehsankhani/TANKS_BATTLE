#ifndef PLAYER_H
#define PLAYER_H
#include "qstring.h"
#include "Tank.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QString Name;
    Tank *tank;
    int Health;
public:
    Player(QString name, Tank *tank, QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    QString GetName();
    int GetHealth();
    void BeingShot(int firePower);
    bool flag = true;
public slots:
    void set_flag();
};

#endif // PLAYER_H
