#include "ennemi1.h"

Ennemi1::Ennemi1(int positionX, int positionY): Ennemi(":/ressources/images/images/ennemi1_0.png", positionX, positionY) {

}

Ennemi1::~Ennemi1() {

}

QString Ennemi1::getTypeObjet() {
    return "Ennemi1";
}

QString Ennemi1::getCheminFichierAnimationEnnemi1() {
    return ":/ressources/images/images/ennemi1_0.png";
}

QString Ennemi1::getCheminFichierAnimationEnnemi2() {
    return ":/ressources/images/images/ennemi1_1.png";
}

int Ennemi1::getScoreEnnemi() {
    return 20;
}
