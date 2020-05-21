#ifndef JOUEUR_H
#define JOUEUR_H

#include "objetspaceinvadersbougeableclavier.h"



class Joueur : public ObjetSpaceInvadersBougeableClavier {

public:
    Joueur(SpaceInvaders* spaceInvaders, QString cheminFichier, int positionX, int positionY);


    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;
    void effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) override;

    // ObjetSpaceInvadersBougeableClavier interface
public:
    void onKeyPressedEvent(QKeyEvent *event) override;

};

#endif // JOUEUR_H
