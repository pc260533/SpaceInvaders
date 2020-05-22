#ifndef JOUEUR_H
#define JOUEUR_H

#include "ballejoueur.h"
#include "iobjetspaceinvadersbougeableclavier.h"
#include "iobjetspaceinvaderstireur.h"

#include <QObject>
#include <QKeyEvent>


class Joueur : public QObject, public IObjetSpaceInvadersBougeableClavier, public IObjetSpaceInvadersTireur {
    Q_OBJECT

private:
    int nombreViesJoueur;
    bool enVieJoueur;
    int vitesseJoueur;

private:
    void intialiserLaPositionDuJoueur();

public:
    Joueur(int positionX, int positionY);

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) override;

    // ObjetSpaceInvadersBougeableClavier interface
public:
    void onKeyPressedEvent(QKeyEvent *event) override;

    // IObjetSpaceInvadersTireur interface
public:
    void tirer() override;

    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;
};

#endif // JOUEUR_H
