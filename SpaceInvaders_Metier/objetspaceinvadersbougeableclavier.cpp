#include "objetspaceinvadersbougeableclavier.h"

ObjetSpaceInvadersBougeableClavier::ObjetSpaceInvadersBougeableClavier(SpaceInvaders* spaceInvaders, QString cheminFichier, int positionX, int positionY)
    : ObjetSpaceInvaders(spaceInvaders, cheminFichier, positionX, positionY) {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
}

ObjetSpaceInvadersBougeableClavier::~ObjetSpaceInvadersBougeableClavier() {

}


void ObjetSpaceInvadersBougeableClavier::keyPressEvent(QKeyEvent* event) {
    this->onKeyPressedEvent(event);
}
