QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

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
    SpaceInvaders_Metier/iobjetspaceinvadersbougeableclavier.cpp \
    SpaceInvaders_Metier/iobjetspaceinvadersevoluable.cpp \
    SpaceInvaders_Metier/iobjetspaceinvaderstireur.cpp \
    SpaceInvaders_Metier/objetspaceinvaders.cpp \
    SpaceInvaders_Metier/objetspaceinvadersgroupe.cpp \
    SpaceInvaders_Metier/objetspaceinvaderspixmap.cpp \
    SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.cpp \
    SpaceInvaders_Metier/objetspaceinvaderstexte.cpp \
    SpaceInvaders_Metier/scene.cpp \
    SpaceInvaders_ObjetSpaceInvaders/balle.cpp \
    SpaceInvaders_ObjetSpaceInvaders/balleennemi.cpp \
    SpaceInvaders_ObjetSpaceInvaders/ballejoueur.cpp \
    SpaceInvaders_ObjetSpaceInvaders/ennemi.cpp \
    SpaceInvaders_ObjetSpaceInvaders/ennemi1.cpp \
    SpaceInvaders_ObjetSpaceInvaders/ennemi2.cpp \
    SpaceInvaders_ObjetSpaceInvaders/ennemi3.cpp \
    SpaceInvaders_ObjetSpaceInvaders/ennemimystere.cpp \
    SpaceInvaders_ObjetSpaceInvaders/iennemi.cpp \
    SpaceInvaders_ObjetSpaceInvaders/joueur.cpp \
    SpaceInvaders_ObjetSpaceInvaders/mur.cpp \
    SpaceInvaders_ObjetSpaceInvaders/partiedemur.cpp \
    SpaceInvaders_ObjetSpaceInvaders/vagueennemis.cpp \
    SpaceInvaders_Scene/scenefindejeu.cpp \
    SpaceInvaders_Scene/scenegagne.cpp \
    SpaceInvaders_Scene/scenejeu.cpp \
    SpaceInvaders_Scene/scenemenu.cpp \
    SpaceInvaders_Scene/sceneperdu.cpp \
    SpaceInvaders_Scene/sceneround.cpp \
    SpaceInvaders_Scene/scenespaceinvaders.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    SpaceInvaders_Metier/iobjetspaceinvadersbougeableclavier.h \
    SpaceInvaders_Metier/iobjetspaceinvadersevoluable.h \
    SpaceInvaders_Metier/iobjetspaceinvaderstireur.h \
    SpaceInvaders_Metier/objetspaceinvaders.h \
    SpaceInvaders_Metier/objetspaceinvadersgroupe.h \
    SpaceInvaders_Metier/objetspaceinvaderspixmap.h \
    SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h \
    SpaceInvaders_Metier/objetspaceinvaderstexte.h \
    SpaceInvaders_Metier/scene.h \
    SpaceInvaders_ObjetSpaceInvaders/balle.h \
    SpaceInvaders_ObjetSpaceInvaders/balleennemi.h \
    SpaceInvaders_ObjetSpaceInvaders/ballejoueur.h \
    SpaceInvaders_ObjetSpaceInvaders/ennemi.h \
    SpaceInvaders_ObjetSpaceInvaders/ennemi1.h \
    SpaceInvaders_ObjetSpaceInvaders/ennemi2.h \
    SpaceInvaders_ObjetSpaceInvaders/ennemi3.h \
    SpaceInvaders_ObjetSpaceInvaders/ennemimystere.h \
    SpaceInvaders_ObjetSpaceInvaders/iennemi.h \
    SpaceInvaders_ObjetSpaceInvaders/joueur.h \
    SpaceInvaders_ObjetSpaceInvaders/mur.h \
    SpaceInvaders_ObjetSpaceInvaders/partiedemur.h \
    SpaceInvaders_ObjetSpaceInvaders/vagueennemis.h \
    SpaceInvaders_Scene/scenefindejeu.h \
    SpaceInvaders_Scene/scenegagne.h \
    SpaceInvaders_Scene/scenejeu.h \
    SpaceInvaders_Scene/scenemenu.h \
    SpaceInvaders_Scene/sceneperdu.h \
    SpaceInvaders_Scene/sceneround.h \
    SpaceInvaders_Scene/scenespaceinvaders.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources/ressources.qrc

win32:RC_FILE += winicon.rc
