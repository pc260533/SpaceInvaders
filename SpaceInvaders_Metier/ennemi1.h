#ifndef ENNEMI1_H
#define ENNEMI1_H

#include "ennemi.h"



class Ennemi1 : Ennemi {

public:
    Ennemi1(int positionX, int positionY);
    virtual ~Ennemi1() override;

    // Ennemi interface
public:
    void initialiserFichiersAnimations() override;

};

#endif // ENNEMI1_H
