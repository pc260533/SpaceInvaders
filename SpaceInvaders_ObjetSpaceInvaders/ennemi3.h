#ifndef ENNEMI3_H
#define ENNEMI3_H

#include "ennemi.h"



class Ennemi3 : public Ennemi {

public:
    Ennemi3(int positionX, int positionY);
    virtual ~Ennemi3() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    QString getTypeObjet() override;

    // Ennemi interface
public:
    QString getCheminFichierAnimationEnnemi1() override;
    QString getCheminFichierAnimationEnnemi2() override;

    // IEnnemi interface
public:
    int getScoreEnnemi() override;

};

#endif // ENNEMI3_H
