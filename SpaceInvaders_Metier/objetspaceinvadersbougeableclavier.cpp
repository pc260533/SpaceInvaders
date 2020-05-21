#include "objetspaceinvadersbougeableclavier.h"

ObjetSpaceInvadersBougeableClavier::ObjetSpaceInvadersBougeableClavier(QString cheminFichier, int positionX, int positionY)
    : ObjetSpaceInvaders(cheminFichier, positionX, positionY) {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
}

ObjetSpaceInvadersBougeableClavier::~ObjetSpaceInvadersBougeableClavier() {

}


void ObjetSpaceInvadersBougeableClavier::keyPressEvent(QKeyEvent* event) {
    this->onKeyPressedEvent(event);
}
