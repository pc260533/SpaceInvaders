#ifndef ENNEMI3_H
#define ENNEMI3_H

#include "ennemi.h"



class Ennemi3 : Ennemi {

public:
    Ennemi3(int positionX, int positionY);
    virtual ~Ennemi3() override;

    // Ennemi interface
public:
    void initialiserFichiersAnimations() override;

};

#endif // ENNEMI3_H
