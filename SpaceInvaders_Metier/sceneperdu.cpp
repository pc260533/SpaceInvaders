#include "sceneperdu.h"

ScenePerdu::ScenePerdu(): SceneFinDeJeu() {
    this->perduTextItem = nullptr;
}

ScenePerdu::~ScenePerdu() {
    this->supprimerObjetSpaceInvadersTexte(this->perduTextItem);
    delete this->perduTextItem;
}

void ScenePerdu::initialiserObjetsJeu() {
    SceneFinDeJeu::initialiserObjetsJeu();
    QFont fontSpaceInvaders = this->getFontSpaceInvaders();
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
