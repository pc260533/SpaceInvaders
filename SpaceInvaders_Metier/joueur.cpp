#include "joueur.h"

Joueur::Joueur(int positionX, int positionY)
    :  QObject(nullptr), IObjetSpaceInvadersBougeableClavier(":/ressources/images/images/joueur.png", positionX, positionY) {
    this->vitesseJoueur = 5;
    this->nombreViesJoueur = 3;
    this->enVieJoueur = true;
    this->positionXInitiale = positionX;
    this->positionYInitiale = positionY;
}

int Joueur::getNombreViesJoueur() const {
    return this->nombreViesJoueur;
}

void Joueur::setNombreViesJoueur(int nombreViesJoueur) {
    this->nombreViesJoueur = nombreViesJoueur;
}

void Joueur::intialiserLaPositionDuJoueur() {
    this->setPositionXY(this->positionXInitiale, this->positionYInitiale);
}

void Joueur::evoluerDansLeTemsp() {
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmap*>(item));
    }
}

void Joueur::effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {
    if (objetSpaceInvadersPixmap) {
        QString objetType = objetSpaceInvadersPixmap->getTypeObjet();
        if (objetType == "BalleEnnemi") {
            this->nombreViesJoueur--;
            if (this->nombreViesJoueur <= 0) {
                this->enVieJoueur = false;
            }
            this->intialiserLaPositionDuJoueur();
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmap);
            emit this->nombreViesJoueurDiminue();
        }
    }
}

QString Joueur::getTypeObjet() {
    return "Joueur";
}

void Joueur::onKeyPressedEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        if (this->getPositionX() > 0) {
            this->deplacerXY(-this->vitesseJoueur, 0);
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (this->getPositionX() < this->getLargeurEcran() - this->getLargeur()) {
            this->deplacerXY(this->vitesseJoueur, 0);
        }
    }
    else if (event->key() == Qt::Key_Space) {
        this->tirer();
    }
}

void Joueur::tirer() {
    BalleJoueur* balleJoueur = new BalleJoueur(this->getMilieuX() - 2, this->getMilieuY());
    emit this->nouveauObjetSpaceInvadersPixmapDansJeu(balleJoueur);
}
