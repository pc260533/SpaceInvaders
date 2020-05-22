#ifndef ENNEMI2_H
#define ENNEMI2_H

#include "ennemi.h"



class Ennemi2 : public Ennemi {

public:
    Ennemi2(int positionX, int positionY);
    virtual ~Ennemi2() override;

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

#endif // ENNEMI2_H
