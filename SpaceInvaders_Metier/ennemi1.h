#ifndef ENNEMI1_H
#define ENNEMI1_H

#include "ennemi.h"



class Ennemi1 : public Ennemi {

public:
    Ennemi1(int positionX, int positionY);
    virtual ~Ennemi1() override;

    // Ennemi interface
public:
    QString getCheminFichierAnimationEnnemi1() override;
    QString getCheminFichierAnimationEnnemi2() override;

};

#endif // ENNEMI1_H
