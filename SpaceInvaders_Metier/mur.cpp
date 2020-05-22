#include "mur.h"

Mur::Mur(int positionX, int positionY) : ObjetSpaceInvadersGroupe(positionX, positionY) {
    this->listePartieDeMur = QList<PartieDeMur*>();
    this->creerMur();
}

Mur::~Mur() {

}

void Mur::ajouterPartieDeMur(PartieDeMur *partieDeMur) {
    this->listePartieDeMur.push_back(partieDeMur);
}

void Mur::supprimerPartieDeMur(PartieDeMur *partieDeMur) {
    this->listePartieDeMur.removeOne(partieDeMur);
}

void Mur::creerMur() {
    for (int i = 0; i < 6; i++) {
        if (i < 4) {
            for (int j = 0; j < 12; j++) {
                PartieDeMur *partieDeMur = new PartieDeMur(this->getPositionX() + (j + 1) * 8, this->getPositionY() + (i * 8));
                this->ajouterPartieDeMur(partieDeMur);
                this->addToGroup(partieDeMur);
            }
        }
        else {
            for (int j = 0; j < 4; j++) {
                PartieDeMur *partieDeMur = new PartieDeMur(this->getPositionX() + (j + 1) * 8, this->getPositionY() + (i * 8));
                this->ajouterPartieDeMur(partieDeMur);
                this->addToGroup(partieDeMur);
            }
            for (int j = 8; j < 12; j++) {
                PartieDeMur *partieDeMur = new PartieDeMur(this->getPositionX() + (j + 1) * 8, this->getPositionY() + (i * 8));
                this->ajouterPartieDeMur(partieDeMur);
                this->addToGroup(partieDeMur);
            }
        }
    }
}

void Mur::evoluerDansLeTemsp() {

}
