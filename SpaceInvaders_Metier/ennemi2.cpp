#include "ennemi2.h"

Ennemi2::Ennemi2(int positionX, int positionY): Ennemi(":/ressources/images/images/ennemi2_0.png", positionX, positionY) {

}

Ennemi2::~Ennemi2() {

}

void Ennemi2::initialiserFichiersAnimations() {
    this->setCheminFichierAnimationEnnemi1(":/ressources/images/images/ennemi2_0.png");
    this->setCheminFichierAnimationEnnemi2(":/ressources/images/images/ennemi2_1.png");
}
