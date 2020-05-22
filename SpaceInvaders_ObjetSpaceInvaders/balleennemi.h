#ifndef BALLEENNEMI_H
#define BALLEENNEMI_H

#include "balle.h"

#include <QObject>



class BalleEnnemi : public QObject, public Balle {
    Q_OBJECT

public:
    BalleEnnemi(int positionX, int positionY);
    virtual ~BalleEnnemi();

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

#endif // BALLEENNEMI_H
