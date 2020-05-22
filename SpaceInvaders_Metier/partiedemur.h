#ifndef PARTIEDEMUR_H
#define PARTIEDEMUR_H

#include "objetspaceinvaderspixmapevoluable.h"



class PartieDeMur : public QObject, public ObjetSpaceInvadersPixmapEvoluable {
    Q_OBJECT

public:
    PartieDeMur(int positionX, int positionY);
    virtual ~PartieDeMur() override;

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) override;
    QString getTypeObjet() override;

signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;

};

#endif // PARTIEDEMUR_H
