#include "ennemimystere.h"

EnnemiMystere::EnnemiMystere(int positionX, int positionY)
    : QObject(nullptr), ObjetSpaceInvadersPixmapEvoluable(":/ressources/images/images/ennemiMystere.png", positionX, positionY) {
    this->vitesseEnnemiMystere = 5;
    this->directionEnnemiMystere = 1;
}

EnnemiMystere::~EnnemiMystere() {

}

void EnnemiMystere::evoluerDansLeTemsp() {
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmapEvoluable*>(item));
    }
    this->deplacerXY(this->vitesseEnnemiMystere * this->directionEnnemiMystere, 0);
    if ((this->getPositionX() >= 2800) || (this->getPositionX() + this->getLargeur() <= -2000)) {
        this->directionEnnemiMystere *= -1;
    }
}

void EnnemiMystere::effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmapEvoluable) {
    if (objetSpaceInvadersPixmapEvoluable) {
        QString objetType = objetSpaceInvadersPixmapEvoluable->getTypeObjet();
        if (objetType == "BalleJoueur") {
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmapEvoluable);
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(this);
        }
    }
}

QString EnnemiMystere::getTypeObjet() {
    return "EnnemiMystere";
}


int EnnemiMystere::getScoreEnnemi() {
    return 100;
}
