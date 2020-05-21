#include "ennemi.h"

Ennemi::Ennemi(QString cheminFichier, int positionX, int positionY) : ObjetSpaceInvaders(cheminFichier, positionX, positionY) {
    this->initialiserAnimation();
    this->chanceDeTirEnnemi = 1000;
    this->etatAnimationEnnemi = cheminFichierAnimationEnnemi1;
    this->vitesseEnnemi = 5;
}

Ennemi::~Ennemi() {

}

void Ennemi::setCheminFichierAnimationEnnemi1(QString cheminFichierAnimationEnnemi1) {
    this->cheminFichierAnimationEnnemi1 = cheminFichierAnimationEnnemi1;
}

void Ennemi::setCheminFichierAnimationEnnemi2(QString cheminFichierAnimationEnnemi1) {
    this->cheminFichierAnimationEnnemi2 = cheminFichierAnimationEnnemi1;
}

void Ennemi::initialiserAnimation() {
    this->initialiserFichiersAnimations();
}


void Ennemi::evoluerDansLeTemsp() {

}

void Ennemi::effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) {

}

void Ennemi::tirer() {

}
