#include "ennemi.h"

int Ennemi::chanceDeTirEnnemi = 9999;

Ennemi::Ennemi(QString cheminFichier, int positionX, int positionY) : ObjetSpaceInvadersPixmap(cheminFichier, positionX, positionY) {
    this->etatAnimationEnnemi = "";
    this->vitesseEnnemi = 5;
    this->compteurChangementAnimation = 1;
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

void Ennemi::miseAJourChanceDeTirEnnemi() {
    Ennemi::chanceDeTirEnnemi--;
}

void Ennemi::evoluerDansLeTemsp() {
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmap*>(item));
    }
    if (this->compteurChangementAnimation == 100) {
        this->animerEnnemi();
        this->compteurChangementAnimation = 1;
    }
    else {
        this->compteurChangementAnimation++;
    }
    int chanceDeTirer = QRandomGenerator::global()->bounded(10000);
    if (chanceDeTirer > Ennemi::chanceDeTirEnnemi) {
        this->tirer();
    }
}

void Ennemi::effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {
    if (objetSpaceInvadersPixmap) {
        QString objetType = objetSpaceInvadersPixmap->getTypeObjet();
        if (objetType == "BalleJoueur") {
            this->changerImage(":/ressources/images/images/explosionEnnemi.png");
            this->miseAJourChanceDeTirEnnemi();
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmap);
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(this);
        }
        else if (objetType == "PartieDeMur") {
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmap);
        }
    }
}

void Ennemi::tirer() {
    BalleEnnemi* balleEnnemi = new BalleEnnemi(this->getMilieuX() - 2, this->getMilieuY());
    emit this->nouveauObjetSpaceInvadersPixmapDansJeu(balleEnnemi);
}
