#ifndef SPACEINVADERSIMPL_H
#define SPACEINVADERSIMPL_H

#include "ennemimystere.h"
#include "joueur.h"
#include "mur.h"
#include "objetspaceinvaderstexte.h"
#include "spaceinvaders.h"
#include "vagueennemis.h"

#include <QFontDatabase>



class SpaceInvadersImpl : public SpaceInvaders {
    Q_OBJECT

private:
    Joueur *joueur;
    VagueEnnemis *vagueEnnemis;
    EnnemiMystere *ennemiMystere;
    Mur* mur1;
    Mur* mur2;
    Mur* mur3;
    Mur* mur4;

    int score;
    int highscore;
    int round;
    int highestRound;

    ObjetSpaceInvadersTexte* scoreTextItem;
    ObjetSpaceInvadersTexte* highscoreTextItem;
    ObjetSpaceInvadersTexte* roundTextItem;
    ObjetSpaceInvadersTexte* highestRoundTextItem;
    ObjetSpaceInvadersTexte* nombreViesJoueurTextItem;

private:
    void miseAJourTexteNombreDeViesJoueur();
    void miseAJourTexteScoreHighscore();
    void miseAJourTexteRoundHighestRound();

public:
    SpaceInvadersImpl();

    // SpaceInvaders interface
public:
    void actionAExecuterJeuPerdu() override;
    void actionAExecuterJeuGagne() override;
    bool jeuEstGagne() override;
    bool jeuEstPerdu() override;
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;
    void initialiserEvenements() override;
    void onKeyPressEvent(QKeyEvent *event) override;
    void onKeyReleaseEvent(QKeyEvent *event) override;

private slots:
    void onNombreViesJoueurDiminue();

    // SpaceInvaders interface
protected slots:
    void supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) override;

};

#endif // SPACEINVADERSIMPL_H
