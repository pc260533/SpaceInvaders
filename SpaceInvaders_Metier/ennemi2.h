#ifndef ENNEMI2_H
#define ENNEMI2_H

#include "ennemi.h"



class Ennemi2 : Ennemi {

public:
    Ennemi2(int positionX, int positionY);
    virtual ~Ennemi2() override;

    // Ennemi interface
public:
    void initialiserFichiersAnimations() override;

};

#endif // ENNEMI2_H
