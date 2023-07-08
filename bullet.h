#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int Direction;
    int Power;
    bool FirstPlayer;
public:
    Bullet(int direction, int power, bool firstPlayer);

public slots:
    void move();
};

#endif // BULLET_H
