#ifndef ENNEMI3_H
#define ENNEMI3_H

#include "ennemi.h"



class Ennemi3 : public Ennemi {

public:
    Ennemi3(int positionX, int positionY);
    virtual ~Ennemi3() override;

    // Ennemi interface
public:
    QString getCheminFichierAnimationEnnemi1() override;
    QString getCheminFichierAnimationEnnemi2() override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) override;
    void suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // ENNEMI3_H
