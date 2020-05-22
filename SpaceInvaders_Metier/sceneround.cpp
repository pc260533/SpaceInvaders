#include "sceneround.h"

SceneRound::SceneRound(): Scene() {
    this->nextRoundTextItem = nullptr;
}

SceneRound::~SceneRound() {
    this->supprimerObjetSpaceInvadersTexte(this->nextRoundTextItem);
    delete this->nextRoundTextItem;
}

void SceneRound::initialiserObjetsJeu() {
    QFont fontSpaceInvaders = this->getFontSpaceInvaders();
    fontSpaceInvaders.setPixelSize(80);

    this->nextRoundTextItem = new ObjetSpaceInvadersTexte(120, 220);
    this->nextRoundTextItem->setTexte("NEXT ROUND");
    this->nextRoundTextItem->setCouleurTexte(Qt::white);
    this->nextRoundTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->nextRoundTextItem);
}

void SceneRound::initialiserArrierePlan() {
    this->setBackgroundBrush(Qt::black);
}

QString SceneRound::getCheminMusiqueTheme() {
    return "";
}
