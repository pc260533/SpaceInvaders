#ifndef ENNEMI_H
#define ENNEMI_H

#include "balleennemi.h"
#include "iennemi.h"
#include "joueur.h"
#include <SpaceInvaders_Metier/iobjetspaceinvaderstireur.h>
#include <SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h>

#include <QObject>
#include <QString>
#include <QMediaPlayer>



/**
 * @brief Ennemi est la classe abstraite représentant un ennemi.
 * Elle hérite de ObjetSpaceInvadersPixmapEvoluable.
 * Elle implémente IObjetSpaceInvadersTireur et IEnnemi.
 * Elle hérite aussi de QObject pour les signaux et slots.
 */
class Ennemi : public QObject, public ObjetSpaceInvadersPixmapEvoluable, public IObjetSpaceInvadersTireur, public IEnnemi {
    Q_OBJECT

private:
    /**
     * @brief etatAnimationEnnemi : Le chemin de l'image de l'animation actuelle.
     */
    QString etatAnimationEnnemi;
    /**
     * @brief compteurChangementAnimation : La valeur du compteur à incrémenter qu'il faut atteindre avant de changer d'image d'animation.
     */
    int compteurChangementAnimation;
    /**
     * @brief vaEtreDetruit : Le booléen indiquant que l'ennemi a été détruit et affiche l'image d'animation d'explosion.
     */
    bool vaEtreDetruit;
    /**
     * @brief compteurAvantDestruction : La valeur du compteur à incrémenter qu'il faut atteindre avant de détruire l'ennemi.
     */
    int compteurAvantDestruction;

    /**
     * @brief playerTirEnnemi : Le mediaPlayer qui joue le son de tir ennemi.
     */
    QMediaPlayer* playerTirEnnemi;
    /**
     * @brief playerEnnemiTue : Le mediaPlayer qui joue le son d'ennemi détruit.
     */
    QMediaPlayer* playerEnnemiTue;

private:
    /**
     * @brief animerEnnemi : Changer l'image d'animation de l'ennemi.
     */
    void animerEnnemi();

public:
    /**
     * @brief Ennemi : Constructeur prenant en paramètres le chemin du fichier image de la balle, la position en X et en Y du au coin en haut à gauche de l'ennemi.
     * @param cheminFichier : Le chemin du fichier image de l'ennemi.
     * @param positionX : La posistion en X de l'ennemi.
     * @param positionY : La posistion en Y de l'ennemi.
     */
    Ennemi(QString cheminFichier, int positionX, int positionY);
    /**
     * @brief ~Ennemi : Destructeur sans paramètres.
     */
    virtual ~Ennemi();

    /**
     * @brief getCheminFichierAnimationEnnemi1 : Retourner le chemin du fichier de la première image de l'animation de l'ennemi.
     * @return Le chemin du fichier de la première image de l'animation de l'ennemi.
     */
    virtual QString getCheminFichierAnimationEnnemi1() = 0;
    /**
     * @brief getCheminFichierAnimationEnnemi2 : Retourner le chemin du fichier de la deuxième image de l'animation de l'ennemi.
     * @return Le chemin du fichier de la deuxième image de l'animation de l'ennemi.
     */
    virtual QString getCheminFichierAnimationEnnemi2() = 0;

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution de l'ennemi.
     */
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    /**
     * @brief effetCollision : Action à éxecuter en cas de collision avec un autre objetSpaceInvadersPixmapEvoluable.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable avec qui on collisionne.
     */
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmapEvoluable) override;

    // IObjetSpaceInvadersTireur interface
public:
    /**
     * @brief tirer : Action à réaliser au tir d'un ennemi.
     */
    void tirer() override;

    // IObjetSpaceInvadersEvoluable interface
signals:
    /**
     * @brief nouveauObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un nouvel objetSpaceInvadersPixmapEvoluable doit être créé.
     */
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;
    /**
     * @brief suppressionObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un objetSpaceInvadersPixmapEvoluable doit être supprimé.
     */
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;

};

#endif // ENNEMI_H
