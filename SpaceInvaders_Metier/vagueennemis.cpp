#include "vagueennemis.h"

VagueEnnemis::VagueEnnemis() {
    this->listeEnnemis = QList<Ennemi*>();
    this->vitesseX = 5;
    this->vitesseY = 10;
    this->direction = 1;
    this->positionDebutX = 50;
    this->positionDebutY = 50;
    this->creerVague();
}

VagueEnnemis::~VagueEnnemis() {

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

        /*ennemi->deplacerXY(this->vitesseX * this->direction, 0);

        if ((ennemi->getPositionX() + ennemi->getLargeur()) >= (ennemi->getLargeurEcran() - 50)) {
            this->direction = -1;
            ennemi->deplacerXY(2 * this->vitesseX * this->direction, 0);
            int indexDernier = this->listeEnnemis.indexOf(ennemi);
            for (int i = 0; i < indexDernier; i++) {
                this->listeEnnemis.at(i)->deplacerXY(2 * this->vitesseX * this->direction, 0);
            }
            this->descendreVagueEnnemis();
        }
        else if (ennemi->getPositionX() <= 50) {
            this->direction = 1;
            ennemi->deplacerXY(2 * this->vitesseX * this->direction, 0);
            int indexDernier = this->listeEnnemis.indexOf(ennemi);
            for (int i = 0; i < indexDernier; i++) {
                this->listeEnnemis.at(i)->deplacerXY(2 * this->vitesseX * this->direction, 0);
            }
            this->descendreVagueEnnemis();
        }*/

    }
}

void VagueEnnemis::creerVague() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            if (i < 2) {
                Ennemi3* ennemi3 = new Ennemi3((j + 1) * this->positionDebutX, (i + 1) * this->positionDebutY);
                this->ajouterEnnemi(ennemi3);
                this->addToGroup(ennemi3);
            }
            else if (i < 4) {
                Ennemi2* ennemi2 = new Ennemi2((j + 1) * this->positionDebutX, (i + 1) * this->positionDebutY);
                this->ajouterEnnemi(ennemi2);
                this->addToGroup(ennemi2);
            }
            else {
                Ennemi1* ennemi1 = new Ennemi1((j + 1) * this->positionDebutX, (i + 1) * this->positionDebutY);
                this->ajouterEnnemi(ennemi1);
                this->addToGroup(ennemi1);
            }
        }
    }
}

void VagueEnnemis::ajouterEnnemi(Ennemi *ennemi) {
    this->listeEnnemis.push_back(ennemi);
}

void VagueEnnemis::supprimerEnnemi(Ennemi *ennemi) {
    this->listeEnnemis.removeOne(ennemi);
}

bool VagueEnnemis::contientAucunEnnemis() {
    return this->listeEnnemis.empty();
}

void VagueEnnemis::detruireVagueEnnemi() {
    this->listeEnnemis.clear();
}

void VagueEnnemis::advance(int phase) {
    /*if (!phase)
        return;*/
    //qDebug() << "advance vague ennemis";
    this->deplacerVagueEnnemis();
    QGraphicsItemGroup::advance(phase);
}
