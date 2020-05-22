#include "ennemi2.h"

Ennemi2::Ennemi2(int positionX, int positionY): Ennemi(":/ressources/images/images/ennemi2_0.png", positionX, positionY) {

}

Ennemi2::~Ennemi2() {

}

QString Ennemi2::getTypeObjet() {
    return "Ennemi2";
}

QString Ennemi2::getCheminFichierAnimationEnnemi1() {
    return ":/ressources/images/images/ennemi2_0.png";
}

QString Ennemi2::getCheminFichierAnimationEnnemi2() {
    return ":/ressources/images/images/ennemi2_1.png";
}

int Ennemi2::getScoreEnnemi() {
    return 30;
}
