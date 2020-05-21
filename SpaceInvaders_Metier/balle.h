#ifndef BALLE_H
#define BALLE_H

#include "objetspaceinvaders.h"



class Balle : public ObjetSpaceInvaders {

public:
    Balle(QString cheminFichier, int positionX, int positionY);
    virtual ~Balle();

};

#endif // BALLE_H
