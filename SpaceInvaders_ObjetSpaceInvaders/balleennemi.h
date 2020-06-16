#ifndef BALLEENNEMI_H
#define BALLEENNEMI_H

#include "balle.h"

#include <QObject>



/**
 * @brief Balle est la classe représentant une balle ennemi.
 * Elle hérite de Balle.
 * Elle hérite aussi de QObject pour les signaux et slots.
 */
class BalleEnnemi : public QObject, public Balle {
    Q_OBJECT

public:
    /**
     * @brief BalleEnnemi : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche de la balle ennemi.
     * @param positionX : La position en X de la balle ennemi.
     * @param positionY : La position en Y de la balle ennemi.
     */
    BalleEnnemi(int positionX, int positionY);
    /**
     * @brief ~BalleEnnemi : Destructeur sans paramètres.
     */
    virtual ~BalleEnnemi();

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution de la balle ennemi.
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
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type de la balle ennemi pour faciliter la gestion des collisions.
     * @return Une chaine de caractère représentant le type de la balle ennemi pour faciliter la gestion des collisions.
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

#endif // BALLEENNEMI_H
