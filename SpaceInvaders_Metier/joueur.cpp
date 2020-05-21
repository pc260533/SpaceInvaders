#include "joueur.h"

#include <QDebug>

Joueur::Joueur(SpaceInvaders* spaceInvaders, QString cheminFichier, int positionX, int positionY)
    : ObjetSpaceInvadersBougeableClavier(spaceInvaders, cheminFichier, positionX, positionY) {

}

void Joueur::evoluerDansLeTemsp() {

}

void Joueur::effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) {

}

void Joueur::onKeyPressedEvent(QKeyEvent *event) {
    qDebug() << "test";
}
