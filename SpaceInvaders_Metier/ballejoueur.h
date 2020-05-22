#ifndef BALLEJOUEUR_H
#define BALLEJOUEUR_H

#include "balle.h"

#include <QObject>



class BalleJoueur : public QObject, public Balle {
    Q_OBJECT

public:
    BalleJoueur(int positionX, int positionY);
    virtual ~BalleJoueur();

    // IObjetSpaceInvadersEvoluable interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmapEvoluable) override;
    QString getTypeObjet() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;

};

#endif // BALLEJOUEUR_H
