#ifndef PARTIEDEMUR_H
#define PARTIEDEMUR_H

#include <SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h>



class PartieDeMur : public QObject, public ObjetSpaceInvadersPixmapEvoluable {
    Q_OBJECT

public:
    PartieDeMur(int positionX, int positionY);
    virtual ~PartieDeMur() override;

    // IObjetSpaceInvadersEvoluable interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) override;
    QString getTypeObjet() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;

};

#endif // PARTIEDEMUR_H
