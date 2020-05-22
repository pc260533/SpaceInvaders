#include "scenefindejeu.h"

SceneFinDeJeu::SceneFinDeJeu(): Scene() {
    this->rejouerTextItem = nullptr;
}

SceneFinDeJeu::~SceneFinDeJeu() {
    this->supprimerObjetSpaceInvadersTexte(this->rejouerTextItem);
    delete this->rejouerTextItem;
}

void SceneFinDeJeu::initialiserObjetsJeu() {
    QFont fontSpaceInvaders = this->getFontSpaceInvaders();
    fontSpaceInvaders.setPixelSize(50);

    this->rejouerTextItem = new ObjetSpaceInvadersTexte(60, 350);
    this->rejouerTextItem->setTexte("PRESS A TO PLAY AGAIN");
    this->rejouerTextItem->setCouleurTexte(Qt::white);
    this->rejouerTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->rejouerTextItem);
}

void SceneFinDeJeu::initialiserArrierePlan() {
    this->setBackgroundBrush(Qt::black);
}
