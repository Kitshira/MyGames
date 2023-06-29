#ifndef INITIALMENU_H
#define INITIALMENU_H

#include <QWidget>
#include "roleselect.h"
#include "gameoverwinwidget.h"
#include "shopwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class InitialMenu; }
QT_END_NAMESPACE

class InitialMenu : public QWidget
{
    Q_OBJECT

public:
    InitialMenu(QWidget *parent = nullptr);
    ~InitialMenu();
    void RoleSelecting();
    void entershop();
    void ChooseSaveWidget();
private:
    Ui::InitialMenu *ui;
};
#endif // INITIALMENU_H
