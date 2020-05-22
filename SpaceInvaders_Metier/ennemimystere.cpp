#include "ennemimystere.h"

EnnemiMystere::EnnemiMystere(int positionX, int positionY)
    : QObject(nullptr), ObjetSpaceInvadersPixmapEvoluable(":/ressources/images/images/ennemiMystere.png", positionX, positionY) {
    this->vitesseEnnemiMystere = 5;
    this->directionEnnemiMystere = 1;
    this->playerEnnemiMystereEntre = new QMediaPlayer();
    this->playerEnnemiMystereEntre->setMedia(QUrl("qrc:/ressources/musiques/musiques/ennemiMystereEntre.wav"));
    this->playerEnnemiMystereTue = new QMediaPlayer();
    this->playerEnnemiMystereTue->setMedia(QUrl("qrc:/ressources/musiques/musiques/ennemiMystereTue.mp3"));
}

EnnemiMystere::~EnnemiMystere() {
    delete this->playerEnnemiMystereEntre;
    this->playerEnnemiMystereEntre = nullptr;
    delete this->playerEnnemiMystereTue;
    this->playerEnnemiMystereTue = nullptr;
}

void EnnemiMystere::evoluerDansLeTemsp() {
    for (QGraphicsItem *item : this->collidingItems()) {
        this->effetCollision(dynamic_cast<ObjetSpaceInvadersPixmapEvoluable*>(item));
    }
    this->deplacerXY(this->vitesseEnnemiMystere * this->directionEnnemiMystere, 0);
    if ((this->getPositionX() >= 2800) || (this->getPositionX() + this->getLargeur() <= -2000)) {
        this->directionEnnemiMystere *= -1;
    }
    if ((this->getPositionX() + this->getLargeur() == 0) && (this->directionEnnemiMystere == 1)) {
        if (this->playerEnnemiMystereEntre->state() == QMediaPlayer::PlayingState) {
            this->playerEnnemiMystereEntre->setPosition(0);
        }
        this->playerEnnemiMystereEntre->play();
    }
    else if ((this->getPositionX() == this->getLargeurEcran()) && (this->directionEnnemiMystere == -1)) {
        if (this->playerEnnemiMystereEntre->state() == QMediaPlayer::PlayingState) {
            this->playerEnnemiMystereEntre->setPosition(0);
        }
        this->playerEnnemiMystereEntre->play();
    }
}

void EnnemiMystere::effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmapEvoluable) {
    if (objetSpaceInvadersPixmapEvoluable) {
        QString objetType = objetSpaceInvadersPixmapEvoluable->getTypeObjet();
        if (objetType == "BalleJoueur") {
            this->playerEnnemiMystereEntre->stop();
            if (this->playerEnnemiMystereTue->state() == QMediaPlayer::PlayingState) {
                this->playerEnnemiMystereTue->setPosition(0);
            }
            this->playerEnnemiMystereTue->play();
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(objetSpaceInvadersPixmapEvoluable);
            emit this->suppressionObjetSpaceInvadersPixmapDansJeu(this);
        }
    }
}

QString EnnemiMystere::getTypeObjet() {
    return "EnnemiMystere";
}


int EnnemiMystere::getScoreEnnemi() {
    return 100;
}
