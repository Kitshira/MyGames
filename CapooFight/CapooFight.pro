QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attacktrace.cpp \
    bossenemy.cpp \
    buffchoosing.cpp \
    chest.cpp \
    choosesave.cpp \
    configuresmanage.cpp \
    enemy.cpp \
    gameoverlosewidget.cpp \
    gameoverwinwidget.cpp \
    gamewidget.cpp \
    herocapoo.cpp \
    main.cpp \
    initialmenu.cpp \
    map.cpp \
    obstacle.cpp \
    roleselect.cpp \
    shopwidget.cpp \
    weapon.cpp

HEADERS += \
    attacktrace.h \
    bossenemy.h \
    buffchoosing.h \
    chest.h \
    choosesave.h \
    configuresmanage.h \
    enemy.h \
    gameoverlosewidget.h \
    gameoverwinwidget.h \
    gamewidget.h \
    herocapoo.h \
    initialmenu.h \
    map.h \
    obstacle.h \
    roleselect.h \
    shopwidget.h \
    weapon.h

FORMS += \
    buffchoosing.ui \
    choosesave.ui \
    gameoverlosewidget.ui \
    gameoverwinwidget.ui \
    gamewidget.ui \
    initialmenu.ui \
    roleselect.ui \
    shopwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgs.qrc
