#include "scenegagne.h"

SceneGagne::SceneGagne(): SceneFinDeJeu() {
    this->gagneTextItem = nullptr;
}

SceneGagne::~SceneGagne() {
    this->supprimerObjetSpaceInvadersTexte(this->gagneTextItem);
    delete this->gagneTextItem;
}

void SceneGagne::initialiserObjetsJeu() {
    SceneFinDeJeu::initialiserObjetsJeu();
    QFont fontSpaceInvaders = this->getFontSpaceInvaders();
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
