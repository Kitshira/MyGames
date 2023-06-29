#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "configuresmanage.h"
#include <buffchoosing.h>
#include <QDebug>
#include <QtMath>
#include "roleselect.h"
#include "initialmenu.h"
GameWidget::GameWidget(Datas* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    m_capoo(a->TYPE,a->C_X,a->C_Y,a->SPEBuff,a->ATKBuff,a->DEFBuff,a->LEVEL,a->EXP,a->HP),
    enemys(10),
    attacktraces(0),
    chests(0)
{
    AttackTraceTimer.setInterval(20);
    AttackTraceTimer.start();
    ui->setupUi(this);
    timeremain = CheckTime;
    timelabel=new QLabel;
    timelabel->setText(QString::number(timeremain));
    timelabel->setParent(this);
    timelabel->setFont(QFont("Arial", 36));
    timelabel->move(38,170);
    timelabel->show();
    flag=1;
    m_ImageTimer.setInterval(20);
    m_WeaponTimer.setInterval(m_capoo.getweapon().getfrequen());
    m_Second.setInterval(1000);
    mode = a->TYPE;
    boss=nullptr;
    update();
    Playing();
    connect(ui->Pause,&QPushButton::clicked,this,&GameWidget::GamePause);
    connect(ui->Continue,&QPushButton::clicked,this,&GameWidget::GameContinue);
    connect(ui->BackToRoleSelect,&QPushButton::clicked,this,&GameWidget::BackToRoleSelect);
    connect(ui->SaveAt1AndBack,&QPushButton::clicked,this,&GameWidget::SaveAt1);
    connect(ui->SaveAt2AndBack,&QPushButton::clicked,this,&GameWidget::SaveAt2);
    connect(ui->SaveAt3AndBack,&QPushButton::clicked,this,&GameWidget::SaveAt3);
    for(int i=0;i<=9;i++){
        enemys[i] = new enemy(0);
    }
    dataspointer=nullptr;
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget:: paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,m_map.getmap());
    for(int i=0;i<=4;i++){
     painter.drawPixmap(obs[i].getx(),obs[i].gety(),obs[i].getimg());
    }
    painter.drawPixmap(m_capoo.getx(),m_capoo.gety(),m_capoo.GetCapoosImage());
    for(int i=0;i<=9;i++){
      if(enemys[i]!=nullptr)painter.drawPixmap(enemys[i]->getx(),enemys[i]->gety(),enemys[i]->getimg());
    }

    if(boss!=nullptr){
        if(m_capoo.getx()>boss->getx()){
            painter.drawPixmap(boss->getx(),boss->gety(),boss->getrightimg());
        }
        else{
            painter.drawPixmap(boss->getx(),boss->gety(),boss->getleftimg());
        }
    }
    for(int i=0;i<attacktraces.size();i++){
        painter.drawPixmap(attacktraces[i]->getx(),attacktraces[i]->gety(),attacktraces[i]->GetImage());
    }
    for(int i=0;i<chests.size();i++){
        painter.drawPixmap(chests[i]->getx(),chests[i]->gety(),chests[i]->getimg());
    }
    QPainter p(this);
    QRect Hpremain(1470, 148, 140, 41);
    QString a("HP:");
    QString value1= QString("%1%").arg(QString::number(m_capoo.gethp()));
    QString valueStr1 = a+value1;
    QFont f = QFont("Microsoft YaHei", 15, QFont::Bold);
    p.setFont(f);
    p.setPen(QColor("#555555"));
    p.drawText(Hpremain, Qt::AlignCenter, valueStr1);

    QRect expremain(1310, 148, 140, 41);
    QString e("EXP:");
    QString value2= QString("%1%").arg(QString::number(m_capoo.getexp()));
    QString valueStr2 = e+value2;
    p.drawText(expremain, Qt::AlignCenter, valueStr2);

    QRect levelr(1150, 148, 140, 41);
    QString l("LEVEL:");
    QString value3= QString::number(m_capoo.getlevel());
    QString valueStr3 = l+value3;
    p.drawText(levelr, Qt::AlignCenter, valueStr3);

    QRect pause(2000,-100,340,41);
    if(!m_Second.isActive())pause.moveTo(720,500);
    QString paused("Press 'G' to Continue");
    p.drawText(pause,Qt::AlignCenter,paused);

    QRect atkbuff(1125, 208, 180, 41);
    QString at("ATKBuff:");
    QString value4= QString::number(m_capoo.getatk());
    QString valueStr4 = at+value4;
    p.drawText(atkbuff, Qt::AlignCenter, valueStr4);

    QRect spebuff(1310, 208, 180, 41);
    QString sp("SPEBuff:");
    QString value5= QString::number(m_capoo.getspebuff());
    QString valueStr5 = sp+value5;
    p.drawText(spebuff, Qt::AlignCenter, valueStr5);

    QRect defbuff(1470, 208, 180, 41);
    QString def("DEFBuff:");
    QString value6= QString::number(m_capoo.getdef());
    QString valueStr6 = def+value6;
    p.drawText(defbuff, Qt::AlignCenter, valueStr6);
}
double distanceTobSqu(int x,int y,QPointF b){
    return (x-b.rx())*(x-b.rx())+(y-b.ry())*(y-b.ry());
}
void GameWidget::keyPressEvent(QKeyEvent *event){
  QRectF m = m_capoo.getRect();
  int flag = 0;
  switch (event->key()){
  case Qt::Key_W:
          if(!m_Second.isActive()){
              return;
          }
          m.moveTo(m_capoo.getx(),m_capoo.gety()-m_capoo.getspe());
          for(int i=0;i<=4;i++){
              if(m.intersects(obs[i].getrect())){
                  flag=1;
                  break;
              }
          }
          if(flag==0)m_capoo.setPosition(m_capoo.getx(),m_capoo.gety()-m_capoo.getspe());
      break;
  case Qt::Key_S:
          if(!m_Second.isActive()){
               return;
          }
          m.moveTo(m_capoo.getx(),m_capoo.gety()+m_capoo.getspe());
          for(int i=0;i<=4;i++){
              if(m.intersects(obs[i].getrect())){
                 flag=1;
                 break;
              }
          }
          if(flag==0)m_capoo.setPosition(m_capoo.getx(),m_capoo.gety()+m_capoo.getspe());
      break;
  case Qt::Key_A:
          if(!m_Second.isActive()){
               return;
          }
          m.moveTo(m_capoo.getx()-m_capoo.getspe(),m_capoo.gety());
          for(int i=0;i<=4;i++){
              if(m.intersects(obs[i].getrect())){
                   flag=1;
                   break;
              }
          }
          if(flag==0){
           m_capoo.setPosition(m_capoo.getx()-m_capoo.getspe(),m_capoo.gety());
           m_capoo.setTowardsleft();
          }
      break;
  case Qt::Key_D:
          if(!m_Second.isActive()){
              return;
          }
          m.moveTo(m_capoo.getx()-m_capoo.getspe(),m_capoo.gety());
          for(int i=0;i<=4;i++){
              if(m.intersects(obs[i].getrect())){
                   flag=1;
                   break;
              }
          }
          if(flag==0){
            m_capoo.setPosition(m_capoo.getx()+m_capoo.getspe(),m_capoo.gety());
            m_capoo.setTowardsright();
          }
      break;
  case Qt::Key_P:
      GamePause();
      break;
  case Qt::Key_G:
      GameContinue();
      break;
  default:
      keyReleaseEvent(event);
      break;
  }
}
int signal(double a){
    if(a>0){
        return 1;
    }
    else if(a==0){
        return 0;
    }
    else{
        return -1;
    }
}
void GameWidget::updatePosition(){
    for(int i=0;i<=9;i++){
       if(enemys[i]==nullptr){
          continue;
       }
       switch(enemys[i]->getmovetype()){
        case 0:{
           int a=enemys[i]->gety()+enemys[i]->getspe()*enemys[i]->getmovetowa();
           int flag=0;
           QRectF b=enemys[i]->getRect();
           b.moveTo(enemys[i]->getx(),a);
           for(int i=0;i<=4;i++){
             if(b.intersects(obs[i].getrect())){
                flag=1;
             }
           }
           if(a>1000||a<190||flag==1){
               enemys[i]->turnmovetowa();
           }
           enemys[i]->setPosition(enemys[i]->getx(),a);
           break;
        }
        case 1:{
            int a=enemys[i]->getx()+enemys[i]->getspe()*enemys[i]->getmovetowa();
            int flag=0;
            QRectF b=enemys[i]->getRect();
            b.moveTo(a,enemys[i]->gety());
            for(int i=0;i<=4;i++){
               if(b.intersects(obs[i].getrect())){
                   flag=1;
               }
            }
            if(a>1600||a<0||flag==1){
               enemys[i]->turnmovetowa();
            }
            enemys[i]->setPosition(a,enemys[i]->gety());
            break;
        }
        case 2:{
             double x=m_capoo.getx()-enemys[i]->getx();
             double y=m_capoo.gety()-enemys[i]->gety();
             double a=signal(x)*(enemys[i]->getspe())*qSqrt(x*x)/qSqrt(x*x+y*y)+enemys[i]->getx();
             double b=signal(y)*(enemys[i]->getspe())*qSqrt(y*y)/qSqrt(x*x+y*y)+enemys[i]->gety();
             QRectF m1=enemys[i]->getRect();
             m1.moveTo(a,b);
             int flag1=0;
             for(int i=0;i<=4;i++){
                 if(m1.intersects(obs[i].getrect())){
                    flag1=1;
                 }
             }
            if(flag1==0){
                 enemys[i]->setPosition(a,b);
                 continue;
            }
            QRectF m2=enemys[i]->getRect();
            m2.moveTo(enemys[i]->getx(),b);
            int flag2=0;
            for(int i=0;i<=4;i++){
               if(m2.intersects(obs[i].getrect())){
                  flag2=1;
               }
            }
            if(flag2==0){
                enemys[i]->setPosition(enemys[i]->getx(),b);
                continue;
            }
            QRectF m3=enemys[i]->getRect();
            m3.moveTo(a,enemys[i]->gety());
            int flag3=0;
            for(int i=0;i<=4;i++){
               if(m3.intersects(obs[i].getrect())){
                  flag3=1;
               }
            }
            if(flag3==0){
                enemys[i]->setPosition(a,enemys[i]->gety());
                continue;
            }
            break;
         }
        default:{
            break;
         }
       }
      }
    if(boss!=nullptr){
      double x=m_capoo.getx()-boss->getx();
      double y=m_capoo.gety()-boss->gety();
      if(x!=0||y!=0){
        double a=signal(x)*(boss->getspe())*qSqrt(x*x)/qSqrt(x*x+y*y)+boss->getx();
        double b=signal(y)*(boss->getspe())*qSqrt(y*y)/qSqrt(x*x+y*y)+boss->gety();
        QRectF m1=boss->getRect();
        int flag1=0,flag2=0;
        m1.moveTo(boss->getx(),b);
        for(int i=0;i<=4;i++){
            if(m1.intersects(obs[i].getrect())){
                flag1=1;
            }
        }
        if(flag1==0){
                flag2=1;
        }
        flag1=0;
        m1.moveTo(a,boss->gety());
        for(int i=0;i<=4;i++){
            if(m1.intersects(obs[i].getrect())){
                flag1=2;
            }
        }
        if(flag1==0){
            flag2=2;
        }
        flag1=0;
        m1.moveTo(a,b);
        for(int i=0;i<=4;i++){
            if(m1.intersects(obs[i].getrect())){
                flag1=3;
            }
        }
        if(flag1==0){
            flag2=3;
        }
        switch (flag2){
            case 1:
                boss->setPosition(boss->getx(),b);
                break;
            case 2:
                boss->setPosition(a,boss->gety());
                break;
            case 3:
                boss->setPosition(a,b);
                break;
            default:
                boss->setPosition(a,b);
        }
       }
    }
    for(int i=0;i<attacktraces.size();i++){
        double a=attacktraces[i]->getx()+attacktraces[i]->getspe()*attacktraces[i]->getcos();
        double b=attacktraces[i]->gety()+attacktraces[i]->getspe()*attacktraces[i]->getsin();
        if(a*b<0){
            delete attacktraces[i];
            attacktraces.erase(attacktraces.begin()+i);
            attacktraces.squeeze();
            break;
        }
        attacktraces[i]->setPosition(a,b);
    }
}
int GameWidget:: updatetime(){
    timeremain--;
    timelabel->setText(QString::number(timeremain));
    if(timeremain==0){
        GameOverWinWidget* gameoverwinwidget = new GameOverWinWidget();
        gameoverwinwidget->show();
        Datas * a=new Datas(0);
        int m=a->getGameValue("GoldRemain");
        a->setGameValue("GoldRemain",m+180);
        this->close();
    }
    return timeremain;
}
void GameWidget::Playing(){
    m_ImageTimer.start();
    m_WeaponTimer.start();
    m_Second.start();
    connect(&m_ImageTimer,&QTimer::timeout,[=](){
        if(m_Second.isActive())updatePosition();
        update();
    });

    connect(&AttackTraceTimer,&QTimer::timeout,[=](){
        for(int i=0;i<attacktraces.size();i++){
            int a=attacktraces[i]->getx();
            int b=attacktraces[i]->gety();
            if(attacktraces[i]->gettype()==1){
                for(int m=0;m<10;m++){
                     if(distanceTobSqu(a,b,enemys[m]->getRect().center())<1200){
                         enemys[m]->behurt(attacktraces[i]->getatt());
                         delete attacktraces[i];
                         attacktraces.erase(attacktraces.begin()+i);
                         attacktraces.squeeze();
                         break;
                    }
                }
                if(boss!=nullptr&&distanceTobSqu(a,b,boss->getRect().center())<1200){
                         boss->behurt(attacktraces[i]->getatt());
                         delete attacktraces[i];
                         attacktraces.erase(attacktraces.begin()+i);
                         attacktraces.squeeze();
                }
             }
            else if(attacktraces[i]->gettype()==0){
                if(distanceTobSqu(m_capoo.getRect().center().x(),m_capoo.getRect().center().y(),attacktraces[i]->GetRect().center())<2000){
                         m_capoo.behurt(attacktraces[i]->getatt());
                         delete attacktraces[i];
                         attacktraces.erase(attacktraces.begin()+i);
                         attacktraces.squeeze();
                }
            }
            }
        for(int i=0;i<10;i++){
            if(!enemys[i]->eexist()){
                int rand=qrand();
                if(rand%7==0||rand%8==0){
                    Chest* a=new Chest(enemys[i]->getx(),enemys[i]->gety());
                    chests.push_back(a);
                }
                if(m_capoo.expup(enemys[i]->gettype())){
                    ChooseABuff();
                }
                delete enemys[i];
                enemys[i]=new enemy(0);
            }
        }
        if(boss!=nullptr&&!boss->eexist()){    /*判断死亡*/
            if(m_capoo.expup(boss->gettype())){
                ChooseABuff();
            }
            Chest* a=new Chest(boss->getx(),boss->gety());
            chests.push_back(a);
            delete boss;
            Boss_WeaponTimer.stop();
            boss=nullptr;
        }
        for(int i=0;i<chests.size();i++){
            if(chests[i]->neveropend()&&distanceTobSqu(m_capoo.getx(),m_capoo.gety(),chests[i]->getRect().center())<6000){
                ChooseABuff();
                chests[i]->open();
            }
            if(chests[i]->gettime()>5000){
                delete chests[i];
                chests.erase(chests.begin()+i);
                chests.squeeze();
            }
        }
    });

    connect(&m_WeaponTimer,&QTimer::timeout,[=](){
        QPointF c = m_capoo.getRect().center();
        int m=c.rx(),n=c.ry(),area=m_capoo.getweapon().getareasqr(),flag=0,shootflag=0;
        for(int i=0;i<=9;i++){
            if(distanceTobSqu(m,n,enemys[i]->getRect().center())<area){
                if(flag==0){
                  flag=1;
                  if(!m_capoo.attack(enemys[i])&&shootflag==0){
                      int a=enemys[i]->getRect().center().x();
                      int b=enemys[i]->getRect().center().y();
                      shoot(&m_capoo,a,b);
                      shootflag=1;
                  }
                }
                m_capoo.AddImage();
            }
            if(distanceTobSqu(m,n,enemys[i]->getRect().center())<enemys[i]->getattackareasqu()){
                m_capoo.behurt(enemys[i]->getatt());
            }
        }
        if(boss!=nullptr){
         /*判定是否可以发起攻击*/
            if(distanceTobSqu(m,n,boss->getRect().center())<(area+10000)){
                m_capoo.attack(boss);   /*攻击函数*/
                if(flag==0){            /*攻击动作*/
                  flag=1;
                }
                m_capoo.AddImage();
            }
            }
            if(flag==0){
                 m_capoo.ResetImage();
            }
    });

    connect(&Boss_WeaponTimer,&QTimer::timeout,[=](){
          if(distanceTobSqu(boss->getx(),boss->gety(),m_capoo.getRect().center())<boss->GetWeapon().getareasqr()){
              int a=m_capoo.getRect().center().x();
              int b=m_capoo.getRect().center().y();
              shoot(boss,a,b);
          }
    });

    connect(&m_Second,&QTimer::timeout,[=](){
          if(updatetime()==50){
              boss=new BossEnemy();
              Boss_WeaponTimer.setInterval(boss->GetWeapon().getfrequen());
              Boss_WeaponTimer.start();
          }
          for(int i=0;i<=9;i++){
              enemys[i]->resetbeingatt();
          }
          if(m_capoo.gethp()<=0){
            GamePause();
            gameoverlosewidget* gameoverlose = new gameoverlosewidget();
            gameoverlose->show();
            Datas * a = new Datas(0);
            int m=a->getGameValue("GoldRemain")+CheckTime-timeremain;
            a->setGameValue("GoldRemain",m);
            this->close();
          }
          for(int i=0;i<chests.size();i++){
              chests[i]->addtime(1000);
          }
    });

}
void GameWidget::GamePause(){
    AttackTraceTimer.stop();
    m_WeaponTimer.stop();
    m_Second.stop();
    Boss_WeaponTimer.stop();
}
void GameWidget::GameContinue(){
    AttackTraceTimer.start();
    m_WeaponTimer.start();
    m_Second.start();
    Boss_WeaponTimer.stop();
}
void GameWidget::shoot(HeroCapoo* h,int x,int y){
    int nowx=h->getx();
    int nowy=h->gety();
    AttackTrace* a;
    a=new AttackTrace(nowx,nowy,h->getweapon().getatt(),1,x-nowx,y-nowy);
    attacktraces.push_back(a);
    return;
}
void GameWidget::shoot(BossEnemy* b,int x,int y){
    int nowx=b->getx();
    int nowy=b->gety();
    AttackTrace* a;
    a=new AttackTrace(nowx,nowy,b->GetWeapon().getatt(),0,x-nowx,y-nowy);
    attacktraces.push_back(a);
    return;
}
void GameWidget::ChooseABuff(){
    GamePause();
    BuffChoosing* buffwidget = new BuffChoosing(this);
    buffwidget->show();
}
void GameWidget::CapooEnhance(int type){
    switch(type){
       case 1:
        m_capoo.DefEn();
        break;
       case 2:
        m_capoo.AtkEn();
        break;
       case 3:
        m_capoo.SpeEn();
        break;
       default:
        break;
    }
}
void GameWidget::BackToRoleSelect(){
    GamePause();
    Datas * a = new Datas(0);
    a->clearConfig();
    a->writeConfig();
    RoleSelect* RoleSelectWidget=new RoleSelect();
    RoleSelectWidget->show();
    this->close();
}
void GameWidget::SaveAt1(){
    GamePause();
    Datas * a=new Datas(1);
    WriteAtWidget(a);
    a->writeConfig();
    InitialMenu* m=new InitialMenu();
    m->show();
    this->close();
}
void GameWidget::SaveAt2(){
    GamePause();
    Datas * a=new Datas(2);
    WriteAtWidget(a);
    a->writeConfig();
    InitialMenu* m=new InitialMenu();
    m->show();
    this->close();
}
void GameWidget::SaveAt3(){
    GamePause();
    Datas * a=new Datas(3);
    WriteAtWidget(a);
    a->writeConfig();
    InitialMenu* m=new InitialMenu();
    m->show();
    this->close();
}
void GameWidget::WriteAtWidget(Datas * a){
    GamePause();
    a->setGameValue("C_X",m_capoo.getx());
    a->setGameValue("C_Y",m_capoo.gety());
    a->setGameValue("ATKBuff",m_capoo.getatk());
    a->setGameValue("DEFBuff",m_capoo.getdef());
    a->setGameValue("SPEBuff",m_capoo.getspebuff());
    a->setGameValue("HPRemain",m_capoo.gethp());
    a->setGameValue("LEVEL",m_capoo.getlevel());
    a->setGameValue("EXP",m_capoo.getexp());
}
