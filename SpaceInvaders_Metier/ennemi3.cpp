#include "ennemi3.h"

Ennemi3::Ennemi3(int positionX, int positionY): Ennemi(":/ressources/images/images/ennemi3_0.png", positionX, positionY) {

}

Ennemi3::~Ennemi3() {

}

void Ennemi3::initialiserFichiersAnimations() {
    this->setCheminFichierAnimationEnnemi1(":/ressources/images/images/ennemi3_0.png");
    this->setCheminFichierAnimationEnnemi2(":/ressources/images/images/ennemi3_1.png");
}
