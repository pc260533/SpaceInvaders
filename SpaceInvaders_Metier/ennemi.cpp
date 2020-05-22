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

void Ennemi::evoluerDansLeTemsp() {
    /*QList<QGraphicsItem *> localCollidingItems = this->collidingItems();
    int test = localCollidingItems.size();
    if (test > 1) {
        qDebug() << "collision";
    }*/
    //qDebug() << "advance ennemi";
    if (this->compteurChangementAnimation == 100) {
        this->animerEnnemi();
        this->compteurChangementAnimation = 1;
    }
    else {
        this->compteurChangementAnimation++;
    }
    srand(static_cast<unsigned>(time(nullptr)));
    int chanceDeTirer =(rand() % 10000) + 1;
    if (chanceDeTirer > Ennemi::chanceDeTirEnnemi) {
        this->tirer();
    }
}

void Ennemi::effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) {

}

void Ennemi::tirer() {
    BalleEnnemi* balleEnnemi = new BalleEnnemi(this->getMilieuX() - 2, this->getMilieuY());
    emit this->nouveauObjetSpaceInvadersDansJeu(balleEnnemi);
}
