#ifndef MAP_H
#define MAP_H
#include <QList>
#include <QString>

class Map
{
private:
    QString Name;
    QList<QList<int>> Board;
public:
    Map(QString name, QList<QList<int>> board);
    QString GetName();
    QList<QList<int>> GetBoard();
    void SetBoard(int i, int j, int value);
};

#endif // MAP_H
