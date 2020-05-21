#include "joueur.h"

#include <QDebug>

Joueur::Joueur(int positionX, int positionY)
    :  QObject(nullptr), ObjetSpaceInvadersBougeableClavier(":/ressources/images/images/joueur.png", positionX, positionY) {
    this->vitesseJoueur = 5;
    this->nombreViesJoueur = 3;
    this->enVieJoueur = true;
}

void Joueur::evoluerDansLeTemsp() {

}

void Joueur::effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) {

}

void Joueur::onKeyPressedEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        qDebug() << "gauche";
    }
    qDebug() << "test";
    emit this->nouveauObjetSpaceInvadersDansJeu(new Joueur(0, 0));
}
