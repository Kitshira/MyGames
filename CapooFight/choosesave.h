#ifndef CHOOSESAVE_H
#define CHOOSESAVE_H

#include <QWidget>

namespace Ui {
class ChooseSave;
}

class ChooseSave : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseSave(QWidget *parent = nullptr);
    ~ChooseSave();
    void LoadSave1();
    void LoadSave2();
    void LoadSave3();
private:
    Ui::ChooseSave *ui;
};

#endif // CHOOSESAVE_H
