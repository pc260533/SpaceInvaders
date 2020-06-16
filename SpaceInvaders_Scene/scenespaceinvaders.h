#ifndef SCENESPACEINVADERS_H
#define SCENESPACEINVADERS_H

#include <SpaceInvaders_ObjetSpaceInvaders/ennemimystere.h>
#include <SpaceInvaders_ObjetSpaceInvaders/joueur.h>
#include <SpaceInvaders_ObjetSpaceInvaders/mur.h>
#include <SpaceInvaders_ObjetSpaceInvaders/vagueennemis.h>
#include <SpaceInvaders_Metier/objetspaceinvaderstexte.h>
#include "sceneround.h"
#include "scenejeu.h"

#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>


/**
 * @brief SceneSpaceInvaders est la classe représentant une scène de jeu du space invaders.
 * Elle hérite de SceneJeu.
 */
class SceneSpaceInvaders : public SceneJeu {
    Q_OBJECT

private:
    /**
     * @brief joueur : Le joueur.
     */
    Joueur *joueur;
    /**
     * @brief vagueEnnemis : La vague d'ennemis.
     */
    VagueEnnemis *vagueEnnemis;
    /**
     * @brief ennemiMystere : L'ennemi mystère.
     */
    EnnemiMystere *ennemiMystere;
    /**
     * @brief mur1 : Le mur 1.
     */
    Mur* mur1;
    /**
     * @brief mur2 : Le mur 2.
     */
    Mur* mur2;
    /**
     * @brief mur3 : Le mur 3.
     */
    Mur* mur3;
    /**
     * @brief mur4 : Le mur 4.
     */
    Mur* mur4;

    /**
     * @brief score : Le score actuel du space invaders.
     */
    int score;
    /**
     * @brief highscore : Le plus haut score du space invaders.
     */
    int highscore;
    /**
     * @brief round : Le numéro de round actuel.
     */
    int round;
    /**
     * @brief highestRound : Le numéro du plus haut round.
     */
    int highestRound;

    /**
     * @brief scoreTextItem : L'objetSpaceInvadersTextItem représentant le texte du score actuel.
     */
    ObjetSpaceInvadersTexte* scoreTextItem;
    /**
     * @brief highscoreTextItem : L'objetSpaceInvadersTextItem représentant le texte du plus haut score.
     */
    ObjetSpaceInvadersTexte* highscoreTextItem;
    /**
     * @brief roundTextItem : L'objetSpaceInvadersTextItem représentant le texte du round actuel.
     */
    ObjetSpaceInvadersTexte* roundTextItem;
    /**
     * @brief highestRoundTextItem : L'objetSpaceInvadersTextItem représentant le texte du plus haut round.
     */
    ObjetSpaceInvadersTexte* highestRoundTextItem;
    /**
     * @brief nombreViesJoueurTextItem : L'objetSpaceInvadersTextItem représentant le texte du nombre de vie du joueur.
     */
    ObjetSpaceInvadersTexte* nombreViesJoueurTextItem;

    /**
     * @brief sceneRound : La scene de changement de round.
     */
    SceneRound* sceneRound;

    /**
     * @brief nombreDeRoundAJouer : Le nombre de round à jouer avant de gagner.
     */
    int nombreDeRoundAJouer;
    /**
     * @brief changementDeRound : Le booléen indiquant que la scene de changement de round est affiché et que la scène de jeu du space invaders ne doit plus évoluée.
     */
    bool changementDeRound;

    /**
     * @brief jsonCheminFichierSauvegardeHighscoreHighestRound : Le chemin du fichier Json contenant l eplus score et le numéro du plus haut round.
     */
    QString jsonCheminFichierSauvegardeHighscoreHighestRound;

private:
    /**
     * @brief miseAJourTexteNombreDeViesJoueur : Mettre à jour le texte du nombre de vies de joueur.
     */
    void miseAJourTexteNombreDeViesJoueur();
    /**
     * @brief miseAJourTexteScoreHighscore : Mettre à jour les textes du score actuel et du plus haut score.
     */
    void miseAJourTexteScoreHighscore();
    /**
     * @brief miseAJourTexteRoundHighestRound : Mettre à jour les textes du round actuel et du plus haut round.
     */
    void miseAJourTexteRoundHighestRound();
    /**
     * @brief chargerNouveauRound : Charger le nouveau round.
     */
    void chargerNouveauRound();
    /**
     * @brief sauvegarderHighscoreHighestRound : Sauvegarder le plus haut score et le plus haut round dans le fichier Json.
     */
    void sauvegarderHighscoreHighestRound();
    /**
     * @brief chargerHighscoreHighestRound : Charger le plus haut score et le plus haut round du fichier Json.
     */
    void chargerHighscoreHighestRound();

public:
    /**
     * @brief SceneSpaceInvaders : Constructeur sans paramètres.
     */
    SceneSpaceInvaders();
    /**
     * @brief ~SceneSpaceInvaders : Destructeur sans paramètres.
     */
    virtual ~SceneSpaceInvaders();

    // Scene interface
public:
    /**
     * @brief initialiserObjetsJeu :  Initialiser les objetsSpaceInvaders de la scène du space invaders.
     */
    void initialiserObjetsJeu() override;
    /**
     * @brief initialiserArrierePlan : Initialiser l'arrière plan de la scène du space invaders.
     */
    void initialiserArrierePlan() override;
    /**
     * @brief getCheminMusiqueTheme : Retourner le chemin de la musique de thème du space invaders.
     * @return Le chemin de la musique de thème.
     */
    QString getCheminMusiqueTheme() override;
    /**
     * @brief reinitialiserScene :  Réinitialiser la scène sans la détruire, supprimer tous les objets de la scène.
     */
    void reinitialiserScene() override;

    // SceneJeu interface
public:
    /**
     * @brief actionAExecuterJeuPerdu : Action à exécuter quand le jeu est perdu.
     */
    void actionAExecuterJeuPerdu() override;
    /**
     * @brief actionAExecuterJeuGagne : Action à exécuter quand le jeu est gagné.
     */
    void actionAExecuterJeuGagne() override;
    /**
     * @brief jeuEstGagne : Retourner un booléen indiquant si le jeu est gagné.
     * @return Le booléen indiquant si le jeu est gagné.
     */
    bool jeuEstGagne() override;
    /**
     * @brief jeuEstPerdu : Retourner un booléen indiquant si le jeu est perdu.
     * @return Le booléen indiquant si le jeu est perdu.
     */
    bool jeuEstPerdu() override;
    /**
     * @brief onKeyPressEvent : Action à réaliser après la détection d'une touche du clavier pressée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier pressée.
     */
    void onKeyPressEvent(QKeyEvent* event) override;
    /**
     * @brief onKeyReleaseEvent : Action à réaliser après la détection d'une touche du clavier relachée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier relachée.
     */
    void onKeyReleaseEvent(QKeyEvent* event) override;

private slots:
    /**
     * @brief onNombreViesJoueurDiminue : Slot correspondant au signal nombreViesJoueurDiminue du joueur.
     */
    void onNombreViesJoueurDiminue();

    /**
     * @brief afficherNextRound : Slot correspondant au changement de round après deux secondes d'afficgade de la scene de changement de round..
     */
    void afficherNextRound();

    // SceneJeu interface
protected slots:
    /**
     * @brief supprimerObjetsSpaceInvadersPixmapDuJeu : Slot correpsondant au signal suppressionObjetSpaceInvadersPixmapDansJeu.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable à supprimer.
     */
    void supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap) override;

    // SpaceInvaders interface
public slots:
    /**
     * @brief evoluer : Slot correspondant au signal timeout du QTimer de la MainWindows.
     */
    void evoluer() override;

signals:
    /**
     * @brief quitter :  Signal envoyé lorque l'utilisateur veut quitter le jeu.
     */
    void quitter();
    /**
     * @brief partieGagne :  Signal envoyé lorqu'un la partie est gagnée.
     */
    void partieGagne();
    /**
     * @brief partiePerdu :  Signal envoyé lorqu'un la partie est perdu.
     */
    void partiePerdu();

};

#endif // SCENESPACEINVADERS_H
