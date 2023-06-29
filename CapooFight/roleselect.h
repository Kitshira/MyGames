#ifndef ROLESELECT_H
#define ROLESELECT_H

#include <QWidget>
#include <configuresmanage.h>
namespace Ui {
class RoleSelect;
}

class RoleSelect : public QWidget
{
    Q_OBJECT
    friend class InitialMenu;
public:
    explicit RoleSelect(QWidget *parent = nullptr);
    ~RoleSelect();
    void BackToInitialMenu();
    void ModeFighterStart();
    void ModeGunnerStart();
private:
    Ui::RoleSelect *ui;
};

#endif // ROLESELECT_H
