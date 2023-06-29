#ifndef BUFFCHOOSING_H
#define BUFFCHOOSING_H

#include <QWidget>
#include <gamewidget.h>
namespace Ui {
class BuffChoosing;
}

class BuffChoosing : public QWidget
{
    Q_OBJECT

public:
    explicit BuffChoosing(GameWidget * parent1,QWidget *parent = nullptr);
    ~BuffChoosing();

private:
    Ui::BuffChoosing *ui;
    GameWidget* parentwidget;
};

#endif // BUFFCHOOSING_H
