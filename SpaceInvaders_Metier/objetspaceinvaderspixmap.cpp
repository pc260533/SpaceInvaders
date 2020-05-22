#include "objetspaceinvaderspixmap.h"

ObjetSpaceInvadersPixmap::ObjetSpaceInvadersPixmap(QString cheminFichier, int positionX, int positionY) : ObjetSpaceInvaders(positionX, positionY) {
    this->cheminFichier = cheminFichier;
    this->pixmap = QPixmap(cheminFichier);
    this->setPixmap(this->pixmap);
    this->hauteur = this->pixmap.size().height();
    this->largeur = this->pixmap.size().width();
    this->setPos(this->getPositionX(), this->getPositionY());
}

ObjetSpaceInvadersPixmap::~ObjetSpaceInvadersPixmap() {

}

int ObjetSpaceInvadersPixmap::getHauteur() const {
    return this->hauteur;
}

int ObjetSpaceInvadersPixmap::getLargeur() const {
    return this->largeur;
}

int ObjetSpaceInvadersPixmap::getMilieuX() const {
    return this->getPositionX() + (this->largeur / 2);
}

int ObjetSpaceInvadersPixmap::getMilieuY() const {
    return this->getPositionX() + (this->hauteur / 2);
}

void ObjetSpaceInvadersPixmap::deplacerXY(int deplacementX, int deplacementY) {
    this->setPositionX(this->getPositionX() + deplacementX);
    this->setPositionY(this->getPositionY() + deplacementY);
    this->setPos(this->getPositionX(), this->getPositionY());
}

void ObjetSpaceInvadersPixmap::changerImage(QString cheminFichier) {
    this->pixmap = QPixmap(cheminFichier);
    this->setPixmap(this->pixmap);
}

void ObjetSpaceInvadersPixmap::advance(int phase) {
    this->evoluerDansLeTemsp();
}
