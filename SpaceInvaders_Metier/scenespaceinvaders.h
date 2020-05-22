#ifndef SPACEINVADERSIMPL_H
#define SPACEINVADERSIMPL_H

#include "ennemimystere.h"
#include "joueur.h"
#include "mur.h"
#include "objetspaceinvaderstexte.h"
#include "sceneround.h"
#include "scenejeu.h"
#include "vagueennemis.h"

#include <QTimer>



class SceneSpaceInvaders : public SceneJeu {
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

    SceneRound* sceneRound;

    int nombreDeRoundAJouer;
    bool changementDeRound;

private:
    void miseAJourTexteNombreDeViesJoueur();
    void miseAJourTexteScoreHighscore();
    void miseAJourTexteRoundHighestRound();
    void chargerNouveauRound();

public:
    SceneSpaceInvaders();
    virtual ~SceneSpaceInvaders();

    // Scene interface
public:
    QString getCheminMusiqueTheme() override;

    // SpaceInvaders interface
public:
    void actionAExecuterJeuPerdu() override;
    void actionAExecuterJeuGagne() override;
    bool jeuEstGagne() override;
    bool jeuEstPerdu() override;
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;
    void reinitialiserScene() override;
    void onKeyPressEvent(QKeyEvent *event) override;
    void onKeyReleaseEvent(QKeyEvent *event) override;

private slots:
    void onNombreViesJoueurDiminue();

    void afficherNextRound();

    // SpaceInvaders interface
protected slots:
    void supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) override;

    // SpaceInvaders interface
public slots:
    void evoluer() override;

signals:
    void quitter();
    void partieGagne();
    void partiePerdu();

};

#endif // SPACEINVADERSIMPL_H
