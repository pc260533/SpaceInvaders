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
    int positionXInitiale;
    int positionYInitiale;
    bool estDeplacementGauche;
    bool estDeplacementDroite;
    bool estEnTir;

private:
    void intialiserLaPositionDuJoueur();
    void decrementerVieDuJoueur();

public:
    Joueur(int positionX, int positionY);
    int getNombreViesJoueur() const;
    void setNombreViesJoueur(int nombreViesJoueur);

    // IObjetSpaceInvadersEvoluable interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmapEvoluable) override;
    QString getTypeObjet() override;

    // IObjetSpaceInvadersBougeableClavier interface
public:
    void onKeyPressedEvent(QKeyEvent *event) override;
    void onKeyReleasedEvent(QKeyEvent *event) override;

    // IObjetSpaceInvadersTireur interface
public:
    void tirer() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;

    void nombreViesJoueurDiminue();

};

#endif // JOUEUR_H
