#include "balleennemi.h"

BalleEnnemi::BalleEnnemi(int positionX, int positionY): QObject(nullptr), Balle(":/ressources/images/images/balleEnnemi.png", positionX, positionY) {

}

void BalleEnnemi::evoluerDansLeTemsp() {
    this->deplacerXY(0, 2);
    if (this->getPositionY() + this->getHauteur() > this->getHauteurEcran()) {
        qDebug() << "émission suppresion balle ennemi";
        emit suppressionObjetSpaceInvadersPixmapDansJeu(this);
    }
}

void BalleEnnemi::effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {

}
