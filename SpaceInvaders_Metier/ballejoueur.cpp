#include "ballejoueur.h"

BalleJoueur::BalleJoueur(int positionX, int positionY): QObject(nullptr), Balle(":/ressources/images/images/balleJoueur.png", positionX, positionY) {

}

void BalleJoueur::evoluerDansLeTemsp() {
    this->deplacerXY(0, -2);
    if (this->getPositionY() + this->getHauteur() < 0) {
        qDebug() << "émission suppresion";
        emit suppressionObjetSpaceInvadersDansJeu(this);
    }
}

void BalleJoueur::effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvaders) {

}
