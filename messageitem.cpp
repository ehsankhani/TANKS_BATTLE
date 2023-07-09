#include "messageitem.h"
#include <QFont>

MessageItem::MessageItem(QString message, int color, QGraphicsItem *parent)
{
    setPlainText(message);
    if(color == 1)
    {
        setDefaultTextColor(Qt::red);
    }
    else if(color == 2)
    {
        setDefaultTextColor(Qt::green);
    }
    else if(color == 3)
    {
        setDefaultTextColor(Qt::yellow);
    }
    else if(color == 4)
    {
        setDefaultTextColor(Qt::black);
    }
    else
    {
        setDefaultTextColor(Qt::blue);
    }
    setFont(QFont("B Titr", 12));
}

void MessageItem::SetMessage(QString message)
{
    setPlainText(message);
}
