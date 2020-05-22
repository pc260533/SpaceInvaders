#include "ennemimystere.h"

EnnemiMystere::EnnemiMystere(int positionX, int positionY)
    : ObjetSpaceInvadersPixmap(":/ressources/images/images/ennemiMystere.png", positionX, positionY) {
    this->vitesseEnnemiMystere = 5;
    this->directionEnnemiMystere = 1;
}

void EnnemiMystere::evoluerDansLeTemsp() {
    this->deplacerXY(this->vitesseEnnemiMystere * this->directionEnnemiMystere, 0);
    if ((this->getPositionX() >= 2800) || (this->getPositionX() + this->getLargeur() <= -2000)) {
        this->directionEnnemiMystere *= -1;
    }
}

void EnnemiMystere::effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {

}

void EnnemiMystere::nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) {
}

void EnnemiMystere::suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) {
}
