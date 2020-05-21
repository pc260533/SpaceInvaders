#ifndef OBJETSPACEINVADERSBOUGEABLECLAVIER_H
#define OBJETSPACEINVADERSBOUGEABLECLAVIER_H

#include "objetspaceinvaders.h"



class ObjetSpaceInvadersBougeableClavier : public ObjetSpaceInvaders {

public:
    ObjetSpaceInvadersBougeableClavier(QString cheminFichier, int positionX, int positionY);
    virtual ~ObjetSpaceInvadersBougeableClavier() override;
    virtual void onKeyPressedEvent(QKeyEvent* event) = 0;


    // QGraphicsItem interface
protected:
    void keyPressEvent(QKeyEvent *event) override;


};

#endif // OBJETSPACEINVADERSBOUGEABLECLAVIER_H
