#include "gameoverlosewidget.h"
#include "ui_gameoverlosewidget.h"
#include "initialmenu.h"
#include "configuresmanage.h"
gameoverlosewidget::gameoverlosewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameoverlosewidget)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);

    connect(ui->Exit,&QPushButton::clicked,this,&gameoverlosewidget::close);
    connect(ui->BackToInitialMenu,&QPushButton::clicked,this,&gameoverlosewidget::BackToInitialMenu);
}

gameoverlosewidget::~gameoverlosewidget()
{
    delete ui;
}

void gameoverlosewidget::BackToInitialMenu()
{
    this->hide();
    InitialMenu* newgamewidget = new InitialMenu();
    newgamewidget->show();
}
