#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H
#include <QGraphicsTextItem>

class MessageItem: public QGraphicsTextItem{
public:
    MessageItem(QString message, int color, QGraphicsItem *parent=0);
    void SetMessage(QString message);
};

#endif // MESSAGEITEM_H
