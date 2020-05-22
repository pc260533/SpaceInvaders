#ifndef BALLEJOUEUR_H
#define BALLEJOUEUR_H

#include "balle.h"

#include <QObject>



class BalleJoueur : public QObject, public Balle {
    Q_OBJECT

public:
    BalleJoueur(int positionX, int positionY);

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;
    void effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap*) override;
    void suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // BALLEJOUEUR_H
