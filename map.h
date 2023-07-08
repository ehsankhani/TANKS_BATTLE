#ifndef MAP_H
#define MAP_H
#include <QList>
#include <QString>

class Map
{
private:
    QList<QList<int>> Board;
    QString Name;
public:
    Map(QString name, QList<QList<int>> board);
    QList<QList<int>> GetBoard();
    QString GetName();
};

#endif // MAP_H
