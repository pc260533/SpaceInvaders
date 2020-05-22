#include "joueur.h"

Joueur::Joueur(int positionX, int positionY)
    :  QObject(nullptr), IObjetSpaceInvadersBougeableClavier(":/ressources/images/images/joueur.png", positionX, positionY) {
    this->vitesseJoueur = 5;
    this->nombreViesJoueur = 3;
    this->enVieJoueur = true;
    this->positionXInitiale = positionX;
    this->positionYInitiale = positionY;
    this->estDeplacementGauche = false;
    this->estDeplacementDroite = false;
    this->estEnTir = false;
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

void Joueur::decrementerVieDuJoueur() {
    this->nombreViesJoueur--;
    if (this->nombreViesJoueur <= 0) {
        this->enVieJoueur = false;
    }
}

void Joueur::evoluerDansLeTemsp() {
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmapEvoluable*>(item));
    }
    if (this->estDeplacementGauche) {
        if (this->getPositionX() > 0) {
            this->deplacerXY(-this->vitesseJoueur, 0);
        }
    }
    else if (this->estDeplacementDroite) {
        if (this->getPositionX() < this->getLargeurEcran() - this->getLargeur()) {
            this->deplacerXY(this->vitesseJoueur, 0);
        }
    }
}

void Joueur::effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) {
    if (objetSpaceInvadersPixmap) {
        QString objetType = objetSpaceInvadersPixmap->getTypeObjet();
        if (objetType == "BalleEnnemi") {
            this->decrementerVieDuJoueur();
            this->intialiserLaPositionDuJoueur();
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmap);
            emit this->nombreViesJoueurDiminue();
        }
        else if ((objetType == "Ennemi1") || (objetType == "Ennemi2") || (objetType == "Ennemi3")) {
            this->decrementerVieDuJoueur();
            emit this->nombreViesJoueurDiminue();
        }
    }
}

QString Joueur::getTypeObjet() {
    return "Joueur";
}

void Joueur::onKeyPressedEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        this->estDeplacementGauche = true;
    }
    else if (event->key() == Qt::Key_Right) {
        this->estDeplacementDroite = true;
    }
    /*La vitesse else if (event->key() == Qt::Key_Space) {
        this->tirer();
        this->estEnTir = true;
    }*/
    else if ((event->key() == Qt::Key_Space) && (!this->estEnTir) && (!event->isAutoRepeat())) {
        this->tirer();
        this->estEnTir = true;
    }
}

void Joueur::onKeyReleasedEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        this->estDeplacementGauche = false;
    }
    else if (event->key() == Qt::Key_Right) {
        this->estDeplacementDroite = false;
    }
    else if ((event->key() == Qt::Key_Space) && (!event->isAutoRepeat())) {
        this->estEnTir = false;
    }
}

void Joueur::tirer() {
    BalleJoueur* balleJoueur = new BalleJoueur(this->getMilieuX() - 2, this->getMilieuY());
    emit this->nouveauObjetSpaceInvadersPixmapDansJeu(balleJoueur);
}
