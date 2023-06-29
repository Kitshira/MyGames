#include "choosesave.h"
#include "ui_choosesave.h"
#include "gamewidget.h"

ChooseSave::ChooseSave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseSave)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);

    connect(ui->Save1,&QPushButton::clicked,this,&ChooseSave::LoadSave1);
    connect(ui->Save2,&QPushButton::clicked,this,&ChooseSave::LoadSave2);
    connect(ui->Save3,&QPushButton::clicked,this,&ChooseSave::LoadSave3);
}

ChooseSave::~ChooseSave()
{
    delete ui;
}
void ChooseSave::LoadSave1(){
    Datas * m = new Datas(1);
    m->readConfig();
    GameWidget* gamewidget = new GameWidget(m);
    gamewidget->show();
    this->close();
}
void ChooseSave::LoadSave2(){
    Datas * m = new Datas(2);
    m->readConfig();
    GameWidget* gamewidget = new GameWidget(m);
    gamewidget->show();
    this->close();
}
void ChooseSave::LoadSave3(){
    Datas * m = new Datas(3);
    m->readConfig();
    GameWidget* gamewidget = new GameWidget(m);
    gamewidget->show();
    this->close();
}
