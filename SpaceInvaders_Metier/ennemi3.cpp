#include "ennemi3.h"

Ennemi3::Ennemi3(int positionX, int positionY): Ennemi(":/ressources/images/images/ennemi3_0.png", positionX, positionY) {

}

Ennemi3::~Ennemi3() {

}

QString Ennemi3::getTypeObjet() {
    return "Ennemi3";
}

QString Ennemi3::getCheminFichierAnimationEnnemi1() {
    return ":/ressources/images/images/ennemi3_0.png";
}

QString Ennemi3::getCheminFichierAnimationEnnemi2() {
    return ":/ressources/images/images/ennemi3_1.png";
}

int Ennemi3::getScoreEnnemi() {
    return 50;
}
