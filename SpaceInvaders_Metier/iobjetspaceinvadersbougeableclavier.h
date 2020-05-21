#ifndef OBJETSPACEINVADERSBOUGEABLECLAVIER_H
#define OBJETSPACEINVADERSBOUGEABLECLAVIER_H

#include "objetspaceinvaders.h"



class IObjetSpaceInvadersBougeableClavier : public ObjetSpaceInvaders {

public:
    IObjetSpaceInvadersBougeableClavier(QString cheminFichier, int positionX, int positionY);
    virtual ~IObjetSpaceInvadersBougeableClavier() override;
    virtual void onKeyPressedEvent(QKeyEvent* event) = 0;

};

#endif // OBJETSPACEINVADERSBOUGEABLECLAVIER_H
