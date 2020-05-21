#include "objetspaceinvaders.h"

ObjetSpaceInvaders::ObjetSpaceInvaders(SpaceInvaders* spaceInvaders, QString cheminFichier, int positionX, int positionY) {
    this->spaceInvaders = spaceInvaders;
    this->cheminFichier = cheminFichier;
    this->positionX = positionX;
    this->positionY = positionY;
    this->pixmap = QPixmap(cheminFichier);
    this->hauteur = this->pixmap.size().height();
    this->largeur = this->pixmap.size().width();
    this->hauteurEcran = this->spaceInvaders->getLongueur();
}

ObjetSpaceInvaders::~ObjetSpaceInvaders() {

}

SpaceInvaders *ObjetSpaceInvaders::getSpaceInvaders() const {
    return this->spaceInvaders;
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

void ObjetSpaceInvaders::deplacerXY(int deplacementX, int deplacementY) {
    this->positionX += deplacementX;
    this->positionY += deplacementY;
}


QRectF ObjetSpaceInvaders::boundingRect() const {
    return QRectF(0, 0, this->largeur, this->hauteur);
}

void ObjetSpaceInvaders::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(this->positionX, this->positionY, this->pixmap);
}


void ObjetSpaceInvaders::advance(int phase) {
    this->evoluerDansLeTemsp();
}