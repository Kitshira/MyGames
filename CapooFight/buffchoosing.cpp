#include "buffchoosing.h"
#include "ui_buffchoosing.h"
#include "configuresmanage.h"
BuffChoosing::BuffChoosing(GameWidget* parent1,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuffChoosing)
{
    parentwidget=parent1;

    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);

    connect(ui->DEF,&QPushButton::clicked,[=](){
        parent1->CapooEnhance(1);
        this->hide();
    });

    connect(ui->ATK,&QPushButton::clicked,[=](){
        parent1->CapooEnhance(2);
        this->hide();
    });

    connect(ui->Speed,&QPushButton::clicked,[=](){
        parent1->CapooEnhance(3);
        this->hide();
    });
}

BuffChoosing::~BuffChoosing()
{
    delete ui;
}
