#ifndef MUR_H
#define MUR_H

#include "objetspaceinvadersgroupe.h"
#include "partiedemur.h"

#include <QList>



class Mur : public ObjetSpaceInvadersGroupe {

private:
    QList<PartieDeMur*> listePartieDeMur;

private:
    void creerMur();

public:
    Mur(int positionX, int positionY);
    virtual ~Mur() override;
    QList<PartieDeMur*> getListePartieDeMur() const;
    void ajouterPartieDeMur(PartieDeMur* partieDeMur);
    void supprimerPartieDeMur(PartieDeMur* partieDeMur);

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

};

#endif // MUR_H
