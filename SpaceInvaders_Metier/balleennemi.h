#ifndef BALLEENNEMI_H
#define BALLEENNEMI_H

#include "balle.h"

#include <QObject>



class BalleEnnemi : public QObject, public Balle {
    Q_OBJECT

public:
    BalleEnnemi(int positionX, int positionY);
    virtual ~BalleEnnemi();

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

#endif // BALLEENNEMI_H
