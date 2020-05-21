#ifndef SPACEINVADERSIMPL_H
#define SPACEINVADERSIMPL_H

#include "joueur.h"
#include "spaceinvaders.h"



class SpaceInvadersImpl : public SpaceInvaders {

private:
    Joueur *joueur;

public:
    SpaceInvadersImpl();

    // SpaceInvaders interface
public:
    void actionAExecuterJeuPerdu() override;
    void actionAExecuterJeuGagne() override;
    bool jeuEstGagne() override;
    bool jeuEstPerdu() override;
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;
    void initialiserEvenements() override;
    void onKeyPressEvent(QKeyEvent *event) override;

};

#endif // SPACEINVADERSIMPL_H
