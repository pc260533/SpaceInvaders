#include "objetspaceinvaderspixmapevoluable.h"

ObjetSpaceInvadersPixmapEvoluable::ObjetSpaceInvadersPixmapEvoluable(QString cheminFichier, int positionX, int positionY)
    : ObjetSpaceInvadersPixmap(cheminFichier, positionX, positionY) {

}

ObjetSpaceInvadersPixmapEvoluable::~ObjetSpaceInvadersPixmapEvoluable() {

}

void ObjetSpaceInvadersPixmapEvoluable::advance(int phase) {
    if (!phase) {
        return;
    }
    this->evoluerDansLeTemsp();
}
