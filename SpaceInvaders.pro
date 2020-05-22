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
    SpaceInvaders_Metier/balle.cpp \
    SpaceInvaders_Metier/balleennemi.cpp \
    SpaceInvaders_Metier/ballejoueur.cpp \
    SpaceInvaders_Metier/ennemi.cpp \
    SpaceInvaders_Metier/ennemi1.cpp \
    SpaceInvaders_Metier/ennemi2.cpp \
    SpaceInvaders_Metier/ennemi3.cpp \
    SpaceInvaders_Metier/ennemimystere.cpp \
    SpaceInvaders_Metier/iennemi.cpp \
    SpaceInvaders_Metier/iobjetspaceinvadersbougeableclavier.cpp \
    SpaceInvaders_Metier/iobjetspaceinvadersevoluable.cpp \
    SpaceInvaders_Metier/iobjetspaceinvaderstireur.cpp \
    SpaceInvaders_Metier/joueur.cpp \
    SpaceInvaders_Metier/mur.cpp \
    SpaceInvaders_Metier/objetspaceinvaders.cpp \
    SpaceInvaders_Metier/objetspaceinvadersgroupe.cpp \
    SpaceInvaders_Metier/objetspaceinvaderspixmap.cpp \
    SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.cpp \
    SpaceInvaders_Metier/objetspaceinvaderstexte.cpp \
    SpaceInvaders_Metier/partiedemur.cpp \
    SpaceInvaders_Metier/scene.cpp \
    SpaceInvaders_Metier/scenefindejeu.cpp \
    SpaceInvaders_Metier/scenegagne.cpp \
    SpaceInvaders_Metier/scenejeu.cpp \
    SpaceInvaders_Metier/scenemenu.cpp \
    SpaceInvaders_Metier/sceneperdu.cpp \
    SpaceInvaders_Metier/sceneround.cpp \
    SpaceInvaders_Metier/scenespaceinvaders.cpp \
    SpaceInvaders_Metier/vagueennemis.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    SpaceInvaders_Metier/balle.h \
    SpaceInvaders_Metier/balleennemi.h \
    SpaceInvaders_Metier/ballejoueur.h \
    SpaceInvaders_Metier/ennemi.h \
    SpaceInvaders_Metier/ennemi1.h \
    SpaceInvaders_Metier/ennemi2.h \
    SpaceInvaders_Metier/ennemi3.h \
    SpaceInvaders_Metier/ennemimystere.h \
    SpaceInvaders_Metier/iennemi.h \
    SpaceInvaders_Metier/iobjetspaceinvadersbougeableclavier.h \
    SpaceInvaders_Metier/iobjetspaceinvadersevoluable.h \
    SpaceInvaders_Metier/iobjetspaceinvaderstireur.h \
    SpaceInvaders_Metier/joueur.h \
    SpaceInvaders_Metier/mur.h \
    SpaceInvaders_Metier/objetspaceinvaders.h \
    SpaceInvaders_Metier/objetspaceinvadersgroupe.h \
    SpaceInvaders_Metier/objetspaceinvaderspixmap.h \
    SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h \
    SpaceInvaders_Metier/objetspaceinvaderstexte.h \
    SpaceInvaders_Metier/partiedemur.h \
    SpaceInvaders_Metier/scene.h \
    SpaceInvaders_Metier/scenefindejeu.h \
    SpaceInvaders_Metier/scenegagne.h \
    SpaceInvaders_Metier/scenejeu.h \
    SpaceInvaders_Metier/scenemenu.h \
    SpaceInvaders_Metier/sceneperdu.h \
    SpaceInvaders_Metier/sceneround.h \
    SpaceInvaders_Metier/scenespaceinvaders.h \
    SpaceInvaders_Metier/vagueennemis.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources/ressources.qrc
