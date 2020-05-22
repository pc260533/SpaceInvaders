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

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // ENNEMIMYSTERE_H
