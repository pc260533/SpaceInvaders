#include "ballejoueur.h"

BalleJoueur::BalleJoueur(int positionX, int positionY): QObject(nullptr), Balle(":/ressources/images/images/balleJoueur.png", positionX, positionY) {

}

BalleJoueur::~BalleJoueur() {

}

void BalleJoueur::evoluerDansLeTemsp() {
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmapEvoluable*>(item));
    }

    this->deplacerXY(0, -10);
    if (this->getPositionY() + this->getHauteur() < 0) {
        //qDebug() << "émission suppresion balle joueur";
        emit suppressionObjetSpaceInvadersPixmapDansJeu(this);
    }
}

void BalleJoueur::effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmapEvoluable) {
    if (objetSpaceInvadersPixmapEvoluable) {
        QString objetType = objetSpaceInvadersPixmapEvoluable->getTypeObjet();
        if (objetType == "BalleEnnemi") {
            emit suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmapEvoluable);
            emit suppressionObjetSpaceInvadersPixmapDansJeu(this);
        }
    }
}

QString BalleJoueur::getTypeObjet() {
    return "BalleJoueur";
}

