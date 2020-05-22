#ifndef OBJETSPACEINVADERSBOUGEABLECLAVIER_H
#define OBJETSPACEINVADERSBOUGEABLECLAVIER_H

#include "objetspaceinvaderspixmapevoluable.h"



class IObjetSpaceInvadersBougeableClavier : public ObjetSpaceInvadersPixmapEvoluable {

public:
    IObjetSpaceInvadersBougeableClavier(QString cheminFichier, int positionX, int positionY);
    virtual ~IObjetSpaceInvadersBougeableClavier() override;
    virtual void onKeyPressedEvent(QKeyEvent* event) = 0;
    virtual void onKeyReleasedEvent(QKeyEvent* event) = 0;

};

#endif // OBJETSPACEINVADERSBOUGEABLECLAVIER_H
