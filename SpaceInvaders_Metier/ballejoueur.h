#ifndef BALLEJOUEUR_H
#define BALLEJOUEUR_H

#include "balle.h"

#include <QObject>



class BalleJoueur : public QObject, public Balle {
    Q_OBJECT

public:
    BalleJoueur(int positionX, int positionY);
    virtual ~BalleJoueur();

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) override;
    QString getTypeObjet() override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;

};

#endif // BALLEJOUEUR_H
