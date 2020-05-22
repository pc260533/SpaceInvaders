#include "ennemimystere.h"

EnnemiMystere::EnnemiMystere(int positionX, int positionY)
    : QObject(nullptr), ObjetSpaceInvadersPixmap(":/ressources/images/images/ennemiMystere.png", positionX, positionY) {
    this->vitesseEnnemiMystere = 5;
    this->directionEnnemiMystere = 1;
}

EnnemiMystere::~EnnemiMystere() {

}

void EnnemiMystere::evoluerDansLeTemsp() {
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmap*>(item));
    }
    this->deplacerXY(this->vitesseEnnemiMystere * this->directionEnnemiMystere, 0);
    if ((this->getPositionX() >= 2800) || (this->getPositionX() + this->getLargeur() <= -2000)) {
        this->directionEnnemiMystere *= -1;
    }
}

void EnnemiMystere::effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {
    if (objetSpaceInvadersPixmap) {
        QString objetType = objetSpaceInvadersPixmap->getTypeObjet();
        if (objetType == "BalleJoueur") {
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmap);
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
