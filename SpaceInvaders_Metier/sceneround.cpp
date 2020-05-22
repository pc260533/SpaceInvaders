#include "sceneround.h"

SceneRound::SceneRound(): Scene() {
    this->nextRoundTextItem = nullptr;
}

SceneRound::~SceneRound() {
    this->supprimerObjetSpaceInvadersTexte(this->nextRoundTextItem);
    delete this->nextRoundTextItem;
}

void SceneRound::initialiserObjetsJeu() {
    int id = QFontDatabase::addApplicationFont(":/ressources/font/fonts/fontSpaceInvaders.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontSpaceInvaders = QFont(family);
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
