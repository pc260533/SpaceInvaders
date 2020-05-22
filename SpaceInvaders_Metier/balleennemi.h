#ifndef BALLEENNEMI_H
#define BALLEENNEMI_H

#include "balle.h"

#include <QObject>



class BalleEnnemi : public QObject, public Balle {
    Q_OBJECT

public:
    BalleEnnemi(int positionX, int positionY);

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;
    void effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvaders) override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap*) override;
    void suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) override;

};


#endif // BALLEENNEMI_H
