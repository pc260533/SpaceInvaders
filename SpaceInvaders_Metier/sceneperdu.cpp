#include "sceneperdu.h"

ScenePerdu::ScenePerdu(): SceneFinDeJeu() {
    this->rejouerTextItem = nullptr;
    this->perduTextItem = nullptr;
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
}

ScenePerdu::~ScenePerdu() {

}

void ScenePerdu::initialiserObjetsJeu() {
    SceneFinDeJeu::initialiserObjetsJeu();
    int id = QFontDatabase::addApplicationFont(":/ressources/font/fonts/fontSpaceInvaders.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontSpaceInvaders = QFont(family);
    fontSpaceInvaders.setPixelSize(100);

    this->perduTextItem = new ObjetSpaceInvadersTexte(75, 100);
    this->perduTextItem->setTexte("GAME OVER!");
    this->perduTextItem->setCouleurTexte(Qt::red);
    this->perduTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->perduTextItem);
}

void ScenePerdu::initialiserArrierePlan() {
    this->setBackgroundBrush(Qt::black);
}
