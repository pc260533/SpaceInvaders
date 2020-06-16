#ifndef BALLEJOUEUR_H
#define BALLEJOUEUR_H

#include "balle.h"

#include <QObject>



/**
 * @brief Balle est la classe représentant une balle joueur.
 * Elle hérite de Balle.
 * Elle hérite aussi de QObject pour les signaux et slots.
 */
class BalleJoueur : public QObject, public Balle {
    Q_OBJECT

public:
    /**
     * @brief BalleJoueur : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche de la balle joueur.
     * @param positionX : La position en X de la balle joueur.
     * @param positionY : La position en Y de la balle joueur.
     */
    BalleJoueur(int positionX, int positionY);
    /**
     * @brief ~BalleJoueur : Destructeur sans paramètres.
     */
    virtual ~BalleJoueur();

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution de la balle joueur.
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
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type de la balle joueur pour faciliter la gestion des collisions.
     * @return Une chaine de caractère représentant le type de la balle joueur pour faciliter la gestion des collisions.
     */
    QString getTypeObjet() override;

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

};

#endif // BALLEJOUEUR_H
