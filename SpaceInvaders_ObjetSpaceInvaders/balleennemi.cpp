#include "balleennemi.h"

BalleEnnemi::BalleEnnemi(int positionX, int positionY)
    : QObject(nullptr), Balle(":/ressources/images/images/balleEnnemi.png", positionX, positionY) {

}

BalleEnnemi::~BalleEnnemi() {

}

void BalleEnnemi::evoluerDansLeTemsp() {
    this->deplacerXY(0, 2);
    if (this->getPositionY() + this->getHauteur() > this->getHauteurEcran()) {
        emit suppressionObjetSpaceInvadersPixmapDansJeu(this);
    }
}

void BalleEnnemi::effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmapEvoluable) {
    Q_UNUSED(objetSpaceInvadersPixmapEvoluable);
}

QString BalleEnnemi::getTypeObjet() {
    return "BalleEnnemi";
}
