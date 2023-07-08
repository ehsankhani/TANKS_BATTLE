#include "map.h"

Map::Map(QString name, QList<QList<int>> board)
{
    this->Board = board;
    this->Name = name;
}
QList<QList<int>> Map::GetBoard()
{
    return this->Board;
}

QString Map::GetName()
{
    return this->Name;
}
