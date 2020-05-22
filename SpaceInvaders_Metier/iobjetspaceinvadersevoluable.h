#ifndef IOBJETSPACEINVADERSEVOLUABLE_H
#define IOBJETSPACEINVADERSEVOLUABLE_H

#include "objetspaceinvaders.h"



class IObjetSpaceInvadersEvoluable  {

public:
    IObjetSpaceInvadersEvoluable();
    virtual ~IObjetSpaceInvadersEvoluable();

    virtual void evoluerDansLeTemsp() = 0;
};

#endif // IOBJETSPACEINVADERSEVOLUABLE_H