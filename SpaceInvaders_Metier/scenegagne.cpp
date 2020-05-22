#include "scenegagne.h"

SceneGagne::SceneGagne(): SceneFinDeJeu() {
    this->gagneTextItem = nullptr;
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
}

SceneGagne::~SceneGagne() {

}

void SceneGagne::initialiserObjetsJeu() {
    SceneFinDeJeu::initialiserObjetsJeu();
    int id = QFontDatabase::addApplicationFont(":/ressources/font/fonts/fontSpaceInvaders.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontSpaceInvaders = QFont(family);
    fontSpaceInvaders.setPixelSize(100);

    this->gagneTextItem = new ObjetSpaceInvadersTexte(135, 100);
    this->gagneTextItem->setTexte("VICTORY!");
    this->gagneTextItem->setCouleurTexte(Qt::green);
    this->gagneTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->gagneTextItem);
}

void SceneGagne::initialiserArrierePlan() {
    this->setBackgroundBrush(Qt::black);
}
