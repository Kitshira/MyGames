#include "initialmenu.h"
#include "ui_initialmenu.h"
#include "configuresmanage.h"
#include "choosesave.h"

InitialMenu::InitialMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InitialMenu)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);

    connect(ui->NewGameButton,&QPushButton::clicked,this,&InitialMenu::RoleSelecting);
    connect(ui->ExitButton,&QPushButton::clicked,this,&InitialMenu::close);
    connect(ui->ShopButton,&QPushButton::clicked,this,&InitialMenu::entershop);
    connect(ui->LoadSaveButton,&QPushButton::clicked,this,&InitialMenu::ChooseSaveWidget);
}

InitialMenu::~InitialMenu()
{
    delete ui;
}
void InitialMenu::RoleSelecting()
{
    RoleSelect* RoleSelectWidget = new RoleSelect();
    RoleSelectWidget->show();
    this->close();
}
void InitialMenu::entershop()
{
    ShopWidget* shopwidget = new ShopWidget();
    shopwidget->show();
    this->close();
}
void InitialMenu::ChooseSaveWidget()
{
    ChooseSave* a=new ChooseSave();
    a->show();
    this->close();
}
