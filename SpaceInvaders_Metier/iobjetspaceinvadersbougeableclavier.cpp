#include "iobjetspaceinvadersbougeableclavier.h"

IObjetSpaceInvadersBougeableClavier::IObjetSpaceInvadersBougeableClavier(QString cheminFichier, int positionX, int positionY)
    : ObjetSpaceInvaders(cheminFichier, positionX, positionY) {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

IObjetSpaceInvadersBougeableClavier::~IObjetSpaceInvadersBougeableClavier() {

}
