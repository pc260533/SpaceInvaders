#ifndef BALLE_H
#define BALLE_H

#include <SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h>



class Balle : public ObjetSpaceInvadersPixmapEvoluable {

public:
    Balle(QString cheminFichier, int positionX, int positionY);
    virtual ~Balle();

};

#endif // BALLE_H