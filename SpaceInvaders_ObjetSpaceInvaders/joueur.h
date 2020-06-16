#ifndef JOUEUR_H
#define JOUEUR_H

#include "ballejoueur.h"
#include <SpaceInvaders_Metier/iobjetspaceinvadersbougeableclavier.h>
#include <SpaceInvaders_Metier/iobjetspaceinvaderstireur.h>

#include <QObject>
#include <QKeyEvent>
#include <QMediaPlayer>



/**
 * @brief Joueur est la classe représentant un joueur.
 * Elle hérite de ObjetSpaceInvadersPixmapEvoluable.
 * Elle implémente IObjetSpaceInvadersBougeableClavier et IObjetSpaceInvadersTireur.
 * Elle hérite aussi de QObject pour les signaux et slots.
 */
class Joueur : public QObject, public ObjetSpaceInvadersPixmapEvoluable, public IObjetSpaceInvadersBougeableClavier, public IObjetSpaceInvadersTireur {
    Q_OBJECT

private:
    /**
     * @brief nombreViesJoueur : Le nombre de vie du joueur.
     */
    int nombreViesJoueur;
    /**
     * @brief enVieJoueur : Le booléen indiquant sir le joueur est en vie.
     */
    bool enVieJoueur;
    /**
     * @brief vitesseJoueur : La vitesse du joueur.
     */
    int vitesseJoueur;
    /**
     * @brief positionXInitiale : La posiiton en X initiale du joueur.
     */
    int positionXInitiale;
    /**
     * @brief positionYInitiale : La position en Y initiale du joueur.
     */
    int positionYInitiale;
    /**
     * @brief estDeplacementGauche : Le booléen indiquant si le joueur est en train de se déplacer à gauche.
     */
    bool estDeplacementGauche;
    /**
     * @brief estDeplacementDroite : Le booléen indiquant si le joueur est en train de se déplacer à droite.
     */
    bool estDeplacementDroite;
    /**
     * @brief estEnTir : Le booléen indiquant si le joueur est en train de tirer.
     */
    bool estEnTir;

    /**
     * @brief playerTirJoueur : Le mediaPlayer qui joue le son de tir joueur.
     */
    QMediaPlayer* playerTirJoueur;
    /**
     * @brief playerJoueurTouche : Le mediaPlayer qui joue le son de joueur touché.
     */
    QMediaPlayer* playerJoueurTouche;

private:
    /**
     * @brief intialiserLaPositionDuJoueur : Initialiser la position du joueu aux positions en X et en Y initiales.
     */
    void intialiserLaPositionDuJoueur();
    /**
     * @brief decrementerVieDuJoueur : Décrémenter le nombre de vie du joueur de 1.
     */
    void decrementerVieDuJoueur();

public:
    /**
     * @brief Joueur : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche du joueur.
     * @param positionX : La position en X du joueur.
     * @param positionY : La position en Y du joueur.
     */
    Joueur(int positionX, int positionY);
    /**
     * @brief ~Joueur : Destructeur sans paramètres.
     */
    virtual ~Joueur();
    /**
     * @brief getNombreViesJoueur : Retourner le nombre de vie du joueur.
     * @return Le nombre de vie du joueur.
     */
    int getNombreViesJoueur() const;
    /**
     * @brief setNombreViesJoueur Modifier le nombre de vie du joueur.
     * @param nombreViesJoueur : Le nouveau nombre de vie du joueur.
     */
    void setNombreViesJoueur(int nombreViesJoueur);

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution du joueur.
     */
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    /**
     * @brief effetCollision : Action à éxecuter en cas de collision avec un autre objetSpaceInvadersPixmapEvoluable.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable avec qui on collisionne.
     */
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmapEvoluable) override;
    /**
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type du joueur pour faciliter la gestion des collisions.
     * @return Une chaine de caractère représentant le type du joueur pour faciliter la gestion des collisions.
     */
    QString getTypeObjet() override;

    // IObjetSpaceInvadersBougeableClavier interface
public:
    /**
     * @brief onKeyPressedEvent : Action à réaliser après la détection d'une touche du clavier pressée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier pressée.
     */
    void onKeyPressedEvent(QKeyEvent* event) override;
    /**
     * @brief onKeyPressedEvent : Action à réaliser après la détection d'une touche du clavier relachée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier relachée.
     */
    void onKeyReleasedEvent(QKeyEvent* event) override;

    // IObjetSpaceInvadersTireur interface
public:
    /**
     * @brief tirer : Action à réaliser au tir du joueur.
     */
    void tirer() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
signals:
    /**
     * @brief nouveauObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un nouvel objetSpaceInvadersPixmapEvoluable doit être créé.
     */
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;
    /**
     * @brief suppressionObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un objetSpaceInvadersPixmapEvoluable doit être supprimé.
     */
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;

    /**
     * @brief nombreViesJoueurDiminue : Signal envoyé lorque le nombre de vie du joueur diminue.
     */
    void nombreViesJoueurDiminue();

};

#endif // JOUEUR_H
