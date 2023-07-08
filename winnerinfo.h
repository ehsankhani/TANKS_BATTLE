#ifndef WINNERINFO_H
#define WINNERINFO_H

#include <QDialog>

namespace Ui {
class WinnerInfo;
}

class WinnerInfo : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerInfo(QString playerName, QString tankName, int score, int shild, QWidget *parent = nullptr);
    ~WinnerInfo();

private:
    Ui::WinnerInfo *ui;
};

#endif // WINNERINFO_H
