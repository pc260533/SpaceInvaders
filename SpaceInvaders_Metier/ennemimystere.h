#ifndef ENNEMIMYSTERE_H
#define ENNEMIMYSTERE_H

#include "objetspaceinvaderspixmap.h"



class EnnemiMystere : public ObjetSpaceInvadersPixmap {

private:
    int vitesseEnnemiMystere;
    int directionEnnemiMystere;

public:
    EnnemiMystere(int positionX, int positionY);

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;
    void effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) override;
    void suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // ENNEMIMYSTERE_H
