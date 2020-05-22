#include "iobjetspaceinvadersbougeableclavier.h"

IObjetSpaceInvadersBougeableClavier::IObjetSpaceInvadersBougeableClavier(QString cheminFichier, int positionX, int positionY)
    : ObjetSpaceInvadersPixmapEvoluable(cheminFichier, positionX, positionY) {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

IObjetSpaceInvadersBougeableClavier::~IObjetSpaceInvadersBougeableClavier() {

}
