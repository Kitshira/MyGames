#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <QProgressBar>
#include "map.h"
#include "herocapoo.h"
#include "obstacle.h"
#include "enemy.h"
#include "gameoverwinwidget.h"
#include "gameoverlosewidget.h"
#include "bossenemy.h"
#include "attacktrace.h"
#include "chest.h"

namespace Ui {
class GameWidget;
}

class BuffChoosing;

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    GameWidget(Datas* a,QWidget *parent = nullptr);
    ~GameWidget();
    void paintEvent(QPaintEvent * event);
    void Playing();
    void keyPressEvent(QKeyEvent *event);
    void updatePosition();
    int updatetime();
    void GamePause();
    void GameContinue();
    void shoot(HeroCapoo* x,int a,int b);
    void shoot(BossEnemy* x,int a,int b);
    void ChooseABuff();
    void CapooEnhance(int type);
    void BackToRoleSelect();
    void SaveAt1();
    void SaveAt2();
    void SaveAt3();
    void WriteAtWidget(Datas * a);
private:
    Ui::GameWidget *ui;
    QTimer m_ImageTimer;
    QTimer m_WeaponTimer;
    QTimer m_Second;
    QTimer Boss_WeaponTimer;
    QTimer AttackTraceTimer;
    int timeremain;
    int flag;
    QLabel *timelabel;
    Map m_map;
    int mode;
    HeroCapoo m_capoo;
    obstacle obs[5];
    QVector<enemy*> enemys;
    QVector<AttackTrace*> attacktraces;
    QVector<Chest*> chests;
    BossEnemy* boss;
    QProgressBar BloodBar;
    BuffChoosing* buffchoosewidget;
    Datas* dataspointer;
};

#endif // GAMEWIDGET_H
