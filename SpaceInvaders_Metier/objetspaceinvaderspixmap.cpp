#include "objetspaceinvaderspixmap.h"

ObjetSpaceInvadersPixmap::ObjetSpaceInvadersPixmap(QString cheminFichier, int positionX, int positionY) {
    this->cheminFichier = cheminFichier;
    this->positionX = positionX;
    this->positionY = positionY;
    this->pixmap = QPixmap(cheminFichier);
    this->setPixmap(this->pixmap);
    this->hauteur = this->pixmap.size().height();
    this->largeur = this->pixmap.size().width();
    this->hauteurEcran = 600;
    this->largeurEcran = 800;
    this->setPos(this->positionX, this->positionY);
}

ObjetSpaceInvadersPixmap::~ObjetSpaceInvadersPixmap() {

}

int ObjetSpaceInvadersPixmap::getPositionX() const {
    return this->positionX;
}

void ObjetSpaceInvadersPixmap::setPositionX(int value) {
    this->positionX = value;
}

int ObjetSpaceInvadersPixmap::getPositionY() const {
    return this->positionY;
}

void ObjetSpaceInvadersPixmap::setPositionY(int value) {
    this->positionY = value;
}

int ObjetSpaceInvadersPixmap::getHauteurEcran() const {
    return this->hauteurEcran;
}

int ObjetSpaceInvadersPixmap::getLargeurEcran() const {
    return this->largeurEcran;
}

int ObjetSpaceInvadersPixmap::getHauteur() const {
    return this->hauteur;
}

int ObjetSpaceInvadersPixmap::getLargeur() const {
    return this->largeur;
}

int ObjetSpaceInvadersPixmap::getMilieuX() const {
    return this->positionX + (this->largeur / 2);
}

int ObjetSpaceInvadersPixmap::getMilieuY() const {
    return this->positionY + (this->hauteur / 2);
}

void ObjetSpaceInvadersPixmap::deplacerXY(int deplacementX, int deplacementY) {
    this->positionX += deplacementX;
    this->positionY += deplacementY;
    this->setPos(this->positionX, this->positionY);
    //this->setX(this->positionX + deplacementX);
    //this->moveBy(deplacementX, deplacementY);
}

void ObjetSpaceInvadersPixmap::changerImage(QString cheminFichier) {
    this->pixmap = QPixmap(cheminFichier);
    this->setPixmap(this->pixmap);
}

/*QRectF ObjetSpaceInvaders::boundingRect() const {
    return QRectF(0, 0, this->largeur, this->hauteur);
}*/

/*void ObjetSpaceInvaders::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, this->pixmap);
}*/

void ObjetSpaceInvadersPixmap::advance(int phase) {
    this->evoluerDansLeTemsp();
}
