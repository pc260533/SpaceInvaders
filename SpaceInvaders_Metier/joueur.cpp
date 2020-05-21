#include "joueur.h"

#include <QDebug>

Joueur::Joueur(int positionX, int positionY)
    :  QObject(nullptr), IObjetSpaceInvadersBougeableClavier(":/ressources/images/images/joueur.png", positionX, positionY) {
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
        if (this->getPositionX() > 0) {
            this->deplacerXY(-this->vitesseJoueur, 0);
        }
        /*qDebug() << "x :" << this->getPositionX() << "    y :" << this->getPositionY();
        qDebug() << "x :" << this->pos().x() << "    y :" << this->pos().y();*/
    }
    else if (event->key() == Qt::Key_Right) {
        if (this->getPositionX() < this->getLargeurEcran() - this->getLargeur()) {
            this->deplacerXY(this->vitesseJoueur, 0);
        }
        /*qDebug() << "x :" << this->getPositionX() << "    y :" << this->getPositionY();
        qDebug() << "x :" << this->pos().x() << "    y :" << this->pos().y();*/
    }
    else if (event->key() == Qt::Key_Space) {
        this->tirer();
    }
}

void Joueur::tirer() {
    BalleJoueur* balleJoueur = new BalleJoueur(this->getMilieuX() - 2, this->getMilieuY());
    emit this->nouveauObjetSpaceInvadersDansJeu(balleJoueur);
}
