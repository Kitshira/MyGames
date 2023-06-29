#include "gameoverwinwidget.h"
#include "ui_gameoverwinwidget.h"
#include "initialmenu.h"
#include "configuresmanage.h"
#include "configuresmanage.h"
GameOverWinWidget::GameOverWinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOverWinWidget)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);

    connect(ui->Exit,&QPushButton::clicked,this,&GameOverWinWidget::close);
    connect(ui->BackToInitialMenu,&QPushButton::clicked,this,&GameOverWinWidget::BackToInitialMenu);
}

GameOverWinWidget::~GameOverWinWidget()
{
    delete ui;
}

void GameOverWinWidget::BackToInitialMenu()
{
    this->hide();
    InitialMenu* newgamewidget = new InitialMenu();
    newgamewidget->show();
}
