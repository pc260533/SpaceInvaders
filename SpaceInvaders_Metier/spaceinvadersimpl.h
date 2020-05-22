#ifndef SPACEINVADERSIMPL_H
#define SPACEINVADERSIMPL_H

#include "ennemimystere.h"
#include "joueur.h"
#include "spaceinvaders.h"
#include "vagueennemis.h"



class SpaceInvadersImpl : public SpaceInvaders {

private:
    Joueur *joueur;
    VagueEnnemis *vagueEnnemis;
    EnnemiMystere *ennemiMystere;

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
