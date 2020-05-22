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

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // BALLEENNEMI_H
