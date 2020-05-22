#ifndef VAGUEENNEMIS_H
#define VAGUEENNEMIS_H

#include "ennemi.h"
#include "ennemi1.h"
#include "ennemi2.h"
#include "ennemi3.h"
#include "objetspaceinvadersgroupe.h"

#include <QList>



class VagueEnnemis : public ObjetSpaceInvadersGroupe {

private:
    QList<Ennemi*> listeEnnemis;
    int vitesseX;
    int vitesseY;
    int direction;
    int compteurDeplacement;
    int compteurDeplacementMaximal;

private:
    void creerVague();
    void descendreVagueEnnemis();
    bool testChangementDeDirectionVagueEnnemis(Ennemi* ennemi);
    void deplacerVagueEnnemis();
    void miseAJourCompteurDeplacementMaximal();

public:
    VagueEnnemis(int positionX, int positionY);
    virtual ~VagueEnnemis() override;
    QList<Ennemi*> getListeEnnemis() const;
    void ajouterEnnemi(Ennemi* ennemi);
    void supprimerEnnemi(Ennemi* ennemi);
    bool contientAucunEnnemis();
    void reinitialiserChanceDeTirEnnemi();

    // IObjetSpaceInvadersEvoluable interface
public:
    void evoluerDansLeTemsp() override;

};

#endif // VAGUEENNEMIS_H
