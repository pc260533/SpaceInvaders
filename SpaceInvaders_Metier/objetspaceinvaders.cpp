#include "objetspaceinvaders.h"

ObjetSpaceInvaders::ObjetSpaceInvaders(QString cheminFichier, int positionX, int positionY) {
    this->cheminFichier = cheminFichier;
    this->positionX = positionX;
    this->positionY = positionY;
    this->pixmap = QPixmap(cheminFichier);
    this->hauteur = this->pixmap.size().height();
    this->largeur = this->pixmap.size().width();
    this->hauteurEcran = 600;
    this->largeurEcran = 800;
    this->setPos(this->positionX, this->positionY);
}

ObjetSpaceInvaders::~ObjetSpaceInvaders() {

}

int ObjetSpaceInvaders::getPositionX() const {
    return this->positionX;
}

void ObjetSpaceInvaders::setPositionX(int value) {
    this->positionX = value;
}

int ObjetSpaceInvaders::getPositionY() const {
    return this->positionY;
}

void ObjetSpaceInvaders::setPositionY(int value) {
    this->positionY = value;
}

int ObjetSpaceInvaders::getHauteurEcran() const {
    return this->hauteurEcran;
}

int ObjetSpaceInvaders::getLargeurEcran() const {
    return this->largeurEcran;
}

int ObjetSpaceInvaders::getHauteur() const {
    return this->hauteur;
}

int ObjetSpaceInvaders::getLargeur() const {
    return this->largeur;
}

int ObjetSpaceInvaders::getMilieuX() const {
    return this->positionX + (this->largeur / 2);
}

int ObjetSpaceInvaders::getMilieuY() const {
    return this->positionY + (this->hauteur / 2);
}

void ObjetSpaceInvaders::deplacerXY(int deplacementX, int deplacementY) {
    this->positionX += deplacementX;
    this->positionY += deplacementY;
    this->setPos(this->positionX, this->positionY);
    //this->setX(this->positionX + deplacementX);
    //this->moveBy(deplacementX, deplacementY);
}

QRectF ObjetSpaceInvaders::boundingRect() const {
    return QRectF(0, 0, this->largeur, this->hauteur);
}

void ObjetSpaceInvaders::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, this->pixmap);
}

void ObjetSpaceInvaders::advance(int phase) {
    this->evoluerDansLeTemsp();
}
