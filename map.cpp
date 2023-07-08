#include "map.h"

Map::Map(QString name, QList<QList<int>> board)
{
    this->Board = board;
    this->Name = name;
}

QString Map::GetName()
{
    return this->Name;
}

QList<QList<int>> Map::GetBoard()
{
    return this->Board;
}

void Map::SetBoard(int i, int j, int value)
{
    this->Board[i][j] = value;
}
