#ifndef GAMEOVERWINWIDGET_H
#define GAMEOVERWINWIDGET_H

#include <QWidget>

namespace Ui {
class GameOverWinWidget;
}

class GameOverWinWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverWinWidget(QWidget *parent = nullptr);
    ~GameOverWinWidget();
    void BackToInitialMenu();

private:
    Ui::GameOverWinWidget *ui;
};

#endif // GAMEOVERWINWIDGET_H
