#ifndef PLAYERINFOUI_H
#define PLAYERINFOUI_H

#include <QDialog>
#include "Tank.h"

namespace Ui {
class PlayerInfoUI;
}

class PlayerInfoUI : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerInfoUI(QList<Tank> tanks, QWidget *parent = nullptr);
    ~PlayerInfoUI();
    QList<Tank> Tanks;
private:
    Ui::PlayerInfoUI *ui;
};

#endif // PLAYERINFOUI_H
