#ifndef JOUEUR_H
#define JOUEUR_H

#include "objetspaceinvadersbougeableclavier.h"

#include <QObject>
#include <QKeyEvent>


class Joueur : public QObject, public ObjetSpaceInvadersBougeableClavier {
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
    void effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) override;

    // ObjetSpaceInvadersBougeableClavier interface
public:
    void onKeyPressedEvent(QKeyEvent *event) override;


    // ObjetSpaceInvaders interface
signals:
    void nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvaders*) override;

};

#endif // JOUEUR_H
