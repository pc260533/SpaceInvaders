#ifndef OBJETSPACEINVADERSGROUPE_H
#define OBJETSPACEINVADERSGROUPE_H

#include "iobjetspaceinvadersevoluable.h"
#include "objetspaceinvaders.h"

#include <QGraphicsItem>



class ObjetSpaceInvadersGroupe : public QGraphicsItemGroup, public ObjetSpaceInvaders, public IObjetSpaceInvadersEvoluable {

public:
    ObjetSpaceInvadersGroupe(int positionX, int positionY);
    virtual ~ObjetSpaceInvadersGroupe() override;

    // QGraphicsItem interface
public:
    void advance(int phase) override;

};

#endif // OBJETSPACEINVADERSGROUPE_H
