#include "ennemi.h"

Ennemi::Ennemi(QString cheminFichier, int positionX, int positionY) : ObjetSpaceInvadersPixmapEvoluable(cheminFichier, positionX, positionY) {
    this->etatAnimationEnnemi = "";
    this->vitesseEnnemi = 5;
    this->compteurChangementAnimation = 1;
    this->vaEtreDetruit = false;
    this->compteurAvantDestruction = 1;
}

Ennemi::~Ennemi() {

}

void Ennemi::animerEnnemi() {
    if (etatAnimationEnnemi == "") {
        this->etatAnimationEnnemi = this->getCheminFichierAnimationEnnemi1();
    }
    if (this->etatAnimationEnnemi == this->getCheminFichierAnimationEnnemi1()) {
        this->changerImage(this->getCheminFichierAnimationEnnemi2());
        this->etatAnimationEnnemi = this->getCheminFichierAnimationEnnemi2();
    }
    else {
        this->changerImage(this->getCheminFichierAnimationEnnemi1());
        this->etatAnimationEnnemi = this->getCheminFichierAnimationEnnemi1();
    }
}
void Ennemi::evoluerDansLeTemsp() {
    if (this->vaEtreDetruit) {
        if (this->compteurAvantDestruction == 3) {
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(this);
        }
        else {
            this->compteurAvantDestruction++;
        }
    }
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmapEvoluable*>(item));
    }
    if (this->compteurChangementAnimation == 100) {
        this->animerEnnemi();
        this->compteurChangementAnimation = 1;
    }
    else {
        this->compteurChangementAnimation++;
    }

}

void Ennemi::effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmapEvoluable) {
    if (objetSpaceInvadersPixmapEvoluable) {
        QString objetType = objetSpaceInvadersPixmapEvoluable->getTypeObjet();
        if (objetType == "BalleJoueur") {
            this->changerImage(":/ressources/images/images/explosionEnnemi.png");
            this->vaEtreDetruit = true;
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmapEvoluable);
        }
        else if (objetType == "PartieDeMur") {
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmapEvoluable);
        }
    }
}

void Ennemi::tirer() {
    BalleEnnemi* balleEnnemi = new BalleEnnemi(this->getMilieuX() - 2, this->getMilieuY());
    emit this->nouveauObjetSpaceInvadersPixmapDansJeu(balleEnnemi);
}
