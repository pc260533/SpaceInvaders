#include "objetspaceinvadersgroupe.h"

ObjetSpaceInvadersGroupe::ObjetSpaceInvadersGroupe(int positionX, int positionY) : ObjetSpaceInvaders(positionX, positionY) {

}

ObjetSpaceInvadersGroupe::~ObjetSpaceInvadersGroupe() {

}

void ObjetSpaceInvadersGroupe::advance(int phase) {
    this->evoluerDansLeTemsp();
}
