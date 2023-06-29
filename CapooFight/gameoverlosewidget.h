#ifndef GAMEOVERLOSEWIDGET_H
#define GAMEOVERLOSEWIDGET_H

#include <QWidget>

namespace Ui {
class gameoverlosewidget;
}

class gameoverlosewidget : public QWidget
{
    Q_OBJECT
    friend class InitialMenu;
public:
    explicit gameoverlosewidget(QWidget *parent = nullptr);
    ~gameoverlosewidget();
    void BackToInitialMenu();

private:
    Ui::gameoverlosewidget *ui;
};

#endif // GAMEOVERLOSEWIDGET_H
