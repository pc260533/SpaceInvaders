#include "joueur.h"

Joueur::Joueur(int positionX, int positionY)
    : QObject(nullptr), ObjetSpaceInvadersPixmapEvoluable(":/ressources/images/images/joueur.png", positionX, positionY) {
    this->vitesseJoueur = 5;
    this->nombreViesJoueur = 3;
    this->enVieJoueur = true;
    this->positionXInitiale = positionX;
    this->positionYInitiale = positionY;
    this->estDeplacementGauche = false;
    this->estDeplacementDroite = false;
    this->estEnTir = false;
    this->playerTirJoueur = new QMediaPlayer();
    this->playerTirJoueur->setMedia(QUrl("qrc:/ressources/musiques/musiques/tirJoueur.wav"));
    this->playerJoueurTouche = new QMediaPlayer();
    this->playerJoueurTouche->setMedia(QUrl("qrc:/ressources/musiques/musiques/joueurTouche.mp3"));
}

Joueur::~Joueur() {
    delete this->playerTirJoueur;
    this->playerTirJoueur = nullptr;
    delete this->playerJoueurTouche;
    this->playerJoueurTouche = nullptr;
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
    if (this->playerJoueurTouche->state() == QMediaPlayer::PlayingState) {
        this->playerJoueurTouche->setPosition(0);
    }
    this->playerJoueurTouche->play();
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

void Joueur::effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmapEvoluable) {
    if (objetSpaceInvadersPixmapEvoluable) {
        QString objetType = objetSpaceInvadersPixmapEvoluable->getTypeObjet();
        if (objetType == "BalleEnnemi") {
            this->decrementerVieDuJoueur();
            this->intialiserLaPositionDuJoueur();
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmapEvoluable);
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

void Joueur::onKeyPressedEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left) {
        this->estDeplacementGauche = true;
    }
    else if (event->key() == Qt::Key_Right) {
        this->estDeplacementDroite = true;
    }
    else if ((event->key() == Qt::Key_Space) && (!this->estEnTir) && (!event->isAutoRepeat())) {
        this->tirer();
        this->estEnTir = true;
    }
}

void Joueur::onKeyReleasedEvent(QKeyEvent* event) {
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
    if (this->playerTirJoueur->state() == QMediaPlayer::PlayingState) {
        this->playerTirJoueur->setPosition(0);
    }
    this->playerTirJoueur->play();
    BalleJoueur* balleJoueur = new BalleJoueur(this->getMilieuX() - 2, this->getMilieuY());
    emit this->nouveauObjetSpaceInvadersPixmapDansJeu(balleJoueur);
}
