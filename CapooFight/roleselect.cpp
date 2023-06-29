#include "roleselect.h"
#include "ui_roleselect.h"
#include "initialmenu.h"
#include "gamewidget.h"
#include "configuresmanage.h"
RoleSelect::RoleSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoleSelect)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);

    connect(ui->ExitButton,&QPushButton::clicked,this,&RoleSelect::close);

    connect(ui->BackButton,&QPushButton::clicked,this,&RoleSelect::BackToInitialMenu);

    connect(ui->ModeFighter,&QPushButton::clicked,this,&RoleSelect::ModeFighterStart);

    connect(ui->ModeGunner,&QPushButton::clicked,this,&RoleSelect::ModeGunnerStart);
}

RoleSelect::~RoleSelect()
{
    delete ui;
}

void RoleSelect::BackToInitialMenu()
{
    InitialMenu* newgamewidget = new InitialMenu();
    newgamewidget->show();
    this->close();
}

void RoleSelect::ModeFighterStart()
{
    Datas * m = new Datas(0);
    m->readConfig();
    m->setGameValue("TYPE",0);
    m->TYPE=0;
    m->writeConfig();
    m->readConfig();
    m->clearConfig();
    GameWidget* gamewidget = new GameWidget(m);
    gamewidget->show();
    this->close();
}

void RoleSelect::ModeGunnerStart()
{
    Datas * m = new Datas(0);
    m->readConfig();
    m->setGameValue("TYPE",1);
    m->TYPE=1;
    m->writeConfig();
    m->readConfig();
    m->clearConfig();
    GameWidget* gamewidget = new GameWidget(m);
    gamewidget->show();
    this->close();
}
