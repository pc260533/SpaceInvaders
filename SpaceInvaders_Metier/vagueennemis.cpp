#include "vagueennemis.h"

VagueEnnemis::VagueEnnemis(int positionX, int positionY) : ObjetSpaceInvadersGroupe(positionX, positionY) {
    this->listeEnnemis = QList<Ennemi*>();
    this->vitesseX = 5;
    this->vitesseY = 10;
    this->direction = 1;
    this->compteurDeplacement = 1;
    this->compteurDeplacementMaximal = 100;
    this->creerVague();
}

VagueEnnemis::~VagueEnnemis() {
    for (Ennemi* ennemi : this->listeEnnemis) {
        delete ennemi;
    }
}

QList<Ennemi *> VagueEnnemis::getListeEnnemis() const {
    return this->listeEnnemis;
}

void VagueEnnemis::descendreVagueEnnemis() {
    for (Ennemi* ennemi : this->listeEnnemis) {
        ennemi->deplacerXY(0, this->vitesseY);
    }
}

bool VagueEnnemis::testChangementDeDirectionVagueEnnemis(Ennemi* ennemi) {
    return (((ennemi->getPositionX() + ennemi->getLargeur()) >= (ennemi->getLargeurEcran() - 50)) || (ennemi->getPositionX() <= 50));
}


void VagueEnnemis::deplacerVagueEnnemis() {
    for (Ennemi* ennemi : this->listeEnnemis) {
        ennemi->deplacerXY(this->vitesseX * this->direction, 0);
        if (this->testChangementDeDirectionVagueEnnemis(ennemi)) {
            this->direction *= -1;
            ennemi->deplacerXY(2 * this->vitesseX * this->direction, 0);
            int indexDernier = this->listeEnnemis.indexOf(ennemi);
            for (int i = 0; i < indexDernier; i++) {
                this->listeEnnemis.at(i)->deplacerXY(2 * this->vitesseX * this->direction, 0);
            }
            this->descendreVagueEnnemis();
        }
    }
}

void VagueEnnemis::miseAJourCompteurDeplacementMaximal() {
    this->compteurDeplacementMaximal -= 2;
}

void VagueEnnemis::creerVague() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            if (i < 2) {
                Ennemi3* ennemi3 = new Ennemi3((j + 1) * this->getPositionX(), (i + 1) * this->getPositionY());
                this->ajouterEnnemi(ennemi3);
                this->addToGroup(ennemi3);
            }
            else if (i < 4) {
                Ennemi2* ennemi2 = new Ennemi2((j + 1) * this->getPositionX(), (i + 1) * this->getPositionY());
                this->ajouterEnnemi(ennemi2);
                this->addToGroup(ennemi2);
            }
            else {
                Ennemi1* ennemi1 = new Ennemi1((j + 1) * this->getPositionX(), (i + 1) * this->getPositionY());
                this->ajouterEnnemi(ennemi1);
                this->addToGroup(ennemi1);
            }
        }
    }
}

void VagueEnnemis::ajouterEnnemi(Ennemi* ennemi) {
    this->listeEnnemis.push_back(ennemi);
}

void VagueEnnemis::supprimerEnnemi(Ennemi* ennemi) {
    this->listeEnnemis.removeOne(ennemi);
    this->removeFromGroup(ennemi);
    this->miseAJourCompteurDeplacementMaximal();
}

bool VagueEnnemis::contientAucunEnnemis() {
    return this->listeEnnemis.empty();
}

void VagueEnnemis::evoluerDansLeTemsp() {
    if (this->compteurDeplacement >= this->compteurDeplacementMaximal) {
        this->deplacerVagueEnnemis();
        this->compteurDeplacement = 1;
    }
    else {
        this->compteurDeplacement++;
    }
}

