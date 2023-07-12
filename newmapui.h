#ifndef NEWMAPUI_H
#define NEWMAPUI_H

#include <QDialog>

namespace Ui {
class NewMapUI;
}

class NewMapUI : public QDialog
{
    Q_OBJECT

public:
    explicit NewMapUI(QWidget *parent = nullptr);
    ~NewMapUI();

private slots:
    void on_BtnOk_clicked();

private:
    Ui::NewMapUI *ui;
};

#endif // NEWMAPUI_H
