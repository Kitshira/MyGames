#include "shopwidget.h"
#include "ui_shopwidget.h"
#include "initialmenu.h"
#include "configuresmanage.h"
#include <QMovie>
ShopWidget::ShopWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopWidget)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);

    connect(ui->BackButton,&QPushButton::clicked,this,&ShopWidget::BackToInitialMenu);

    ui->lcdNumber->display(Datas::GoldRemain);
    ui->lcdNumber_2->display(Datas::TOTALSPEBuff);
    ui->lcdNumber_3->display(Datas::TOTALDEFBuff);

    connect(ui->BackButton,&QPushButton::clicked,this,&ShopWidget::BackToInitialMenu);

    connect(ui->RunFaster,&QPushButton::clicked,this,&ShopWidget::SPEUP);

    connect(ui->GrowStronger,&QPushButton::clicked,this,&ShopWidget::DEFUP);

    QMovie * movie = new QMovie(PATH_SHOW);
    movie->setParent(ui->label_6);
    connect(ui->Love,&QPushButton::clicked,movie,&QMovie::start);
    connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
      if (frameNumber == movie->frameCount() - 1) {
        movie->stop();
        movie->deleteLater();
      }
    });
}

ShopWidget::~ShopWidget()
{
    delete ui;
}
void ShopWidget::BackToInitialMenu()
{
    InitialMenu* newgamewidget = new InitialMenu();
    newgamewidget->show();
    this->close();
}
void ShopWidget::SPEUP(){
    Datas* a=new Datas(0);
    if(a->getGameValue("GoldRemain")<5){
        return;
    }
    int ns=a->TOTALSPEBuff;
    int ng=a->GoldRemain;
    a->setGameValue("TOTALSPEBuff",ns+5);
    a->setGameValue("GoldRemain",ng-5);
    ui->lcdNumber->display(Datas::GoldRemain);
    ui->lcdNumber_2->display(Datas::TOTALSPEBuff);
}
void ShopWidget::DEFUP(){
    Datas* a=new Datas(0);
    if(a->getGameValue("GoldRemain")<5){
        return;
    }
    int nd=a->TOTALDEFBuff;
    int ng=a->GoldRemain;
    a->setGameValue("TOTALDEFBuff",nd+5);
    a->setGameValue("GoldRemain",ng-5);
    ui->lcdNumber->display(Datas::GoldRemain);
    ui->lcdNumber_3->display(Datas::TOTALDEFBuff);
}
