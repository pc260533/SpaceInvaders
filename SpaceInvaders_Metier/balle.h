#ifndef BALLE_H
#define BALLE_H

#include "objetspaceinvaderspixmap.h"



class Balle : public ObjetSpaceInvadersPixmap {

public:
    Balle(QString cheminFichier, int positionX, int positionY);
    virtual ~Balle();

};

#endif // BALLE_H
