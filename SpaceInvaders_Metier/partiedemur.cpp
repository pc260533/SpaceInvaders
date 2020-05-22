#include "partiedemur.h"

PartieDeMur::PartieDeMur(int positionX, int positionY) :
    QObject(nullptr), ObjetSpaceInvadersPixmapEvoluable(":/ressources/images/images/partieDeMur.png", positionX, positionY) {

}

PartieDeMur::~PartieDeMur() {

}

void PartieDeMur::evoluerDansLeTemsp() {
    for (QGraphicsItem* item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmapEvoluable*>(item));
    }
}

void PartieDeMur::effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) {
    if (objetSpaceInvadersPixmap) {
        QString objetType = objetSpaceInvadersPixmap->getTypeObjet();
        if (objetType == "BalleJoueur") {
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmap);
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(this);
        }
        else if (objetType == "BalleEnnemi") {
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmap);
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(this);
        }
    }
}

QString PartieDeMur::getTypeObjet() {
    return "PartieDeMur";
}
