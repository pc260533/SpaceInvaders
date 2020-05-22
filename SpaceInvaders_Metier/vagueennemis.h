#ifndef VAGUEENNEMIS_H
#define VAGUEENNEMIS_H

#include "ennemi.h"
#include "ennemi1.h"
#include "ennemi2.h"
#include "ennemi3.h"
#include "objetspaceinvadersgroupe.h"

#include <QList>
#include <QRandomGenerator>


class VagueEnnemis : public ObjetSpaceInvadersGroupe {

private:
    QList<Ennemi*> listeEnnemis;
    int vitesseX;
    int vitesseY;
    int direction;
    int compteurDeplacement;
    int compteurDeplacementMaximal;
    int chanceDeTirEnnemi;

private:
    void creerVague();
    void descendreVagueEnnemis();
    bool testChangementDeDirectionVagueEnnemis(Ennemi* ennemi);
    void deplacerVagueEnnemis();
    void miseAJourChanceDeTirEnnemi();
    void miseAJourCompteurDeplacementMaximal();

public:
    VagueEnnemis(int positionX, int positionY);
    virtual ~VagueEnnemis() override;
    QList<Ennemi*> getListeEnnemis() const;
    void ajouterEnnemi(Ennemi* ennemi);
    void supprimerEnnemi(Ennemi* ennemi);
    bool contientAucunEnnemis();

    // IObjetSpaceInvadersEvoluable interface
public:
    void evoluerDansLeTemsp() override;

};

#endif // VAGUEENNEMIS_H
