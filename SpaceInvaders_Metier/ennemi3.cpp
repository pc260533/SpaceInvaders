#include "ennemi3.h"

Ennemi3::Ennemi3(int positionX, int positionY): Ennemi(":/ressources/images/images/ennemi3_0.png", positionX, positionY) {

}

Ennemi3::~Ennemi3() {

}

QString Ennemi3::getCheminFichierAnimationEnnemi1() {
    return ":/ressources/images/images/ennemi3_0.png";
}

QString Ennemi3::getCheminFichierAnimationEnnemi2() {
    return ":/ressources/images/images/ennemi3_1.png";
}

void Ennemi3::nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) {
}

void Ennemi3::suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) {
}
