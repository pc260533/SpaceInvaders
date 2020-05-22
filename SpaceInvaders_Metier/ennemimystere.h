#ifndef ENNEMIMYSTERE_H
#define ENNEMIMYSTERE_H

#include "iennemi.h"
#include "objetspaceinvaderspixmap.h"



class EnnemiMystere : public QObject, public ObjetSpaceInvadersPixmap, public IEnnemi {
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
    void effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) override;
    QString getTypeObjet() override;

    // IEnnemi interface
public:
    int getScoreEnnemi() override;

    // ObjetSpaceInvadersPixmap interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // ENNEMIMYSTERE_H
