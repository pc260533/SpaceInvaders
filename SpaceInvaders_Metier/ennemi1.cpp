#include "ennemi1.h"

Ennemi1::Ennemi1(int positionX, int positionY): Ennemi(":/ressources/images/images/ennemi1_0.png", positionX, positionY) {

}

Ennemi1::~Ennemi1() {

}

void Ennemi1::initialiserFichiersAnimations() {
    this->setCheminFichierAnimationEnnemi1(":/ressources/images/images/ennemi1_0.png");
    this->setCheminFichierAnimationEnnemi2(":/ressources/images/images/ennemi1_1.png");
}
