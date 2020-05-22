#ifndef PARTIEDEMUR_H
#define PARTIEDEMUR_H

#include "objetspaceinvaderspixmap.h"



class PartieDeMur : public QObject, public ObjetSpaceInvadersPixmap {
    Q_OBJECT

public:
    PartieDeMur(int positionX, int positionY);
    virtual ~PartieDeMur() override;

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) override;
    QString getTypeObjet() override;

signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // PARTIEDEMUR_H
