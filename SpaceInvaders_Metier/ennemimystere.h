#ifndef ENNEMIMYSTERE_H
#define ENNEMIMYSTERE_H

#include "iennemi.h"
#include "objetspaceinvaderspixmapevoluable.h"



class EnnemiMystere : public QObject, public ObjetSpaceInvadersPixmapEvoluable, public IEnnemi {
    Q_OBJECT

private:
    int vitesseEnnemiMystere;
    int directionEnnemiMystere;

public:
    EnnemiMystere(int positionX, int positionY);
    virtual ~EnnemiMystere() override;

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) override;
    QString getTypeObjet() override;

    // IEnnemi interface
public:
    int getScoreEnnemi() override;

    // ObjetSpaceInvadersPixmap interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;

};

#endif // ENNEMIMYSTERE_H
