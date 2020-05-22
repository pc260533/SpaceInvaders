#include "objetspaceinvaders.h"

ObjetSpaceInvaders::ObjetSpaceInvaders(int positionX, int positionY) {
    this->positionX = positionX;
    this->positionY = positionY;
    this->hauteurEcran = 600;
    this->largeurEcran = 800;
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
