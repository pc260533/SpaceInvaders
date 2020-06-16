#ifndef OBJETSPACEINVADERSGROUPE_H
#define OBJETSPACEINVADERSGROUPE_H

#include "iobjetspaceinvadersevoluable.h"
#include "objetspaceinvaders.h"

#include <QGraphicsItem>
#include <QGraphicsItemGroup>



/**
 * @brief ObjetSpaceInvadersGroupe est la classe abstraite représentant un objet du jeu composé d'objets.
 * Elle hérite de QGraphicsItemGroup, ObjetSpaceInvaders.
 * Elle implémente IObjetSpaceInvadersEvoluable.
 */
class ObjetSpaceInvadersGroupe : public QGraphicsItemGroup, public ObjetSpaceInvaders, public IObjetSpaceInvadersEvoluable {

public:
    /**
     * @brief ObjetSpaceInvadersGroupe : Constructeur prenant en paramètres la position en X et en Y du premier objet en haut à gauche du groupe.
     * @param positionX : La position en X.
     * @param positionY : La position en Y.
     */
    ObjetSpaceInvadersGroupe(int positionX, int positionY);
    /**
     * @brief ~ObjetSpaceInvadersGroupe : Destructeur sans paramètres.
     */
    virtual ~ObjetSpaceInvadersGroupe();

    // QGraphicsItemGroup interface
public:
    /**
     * @brief advance : Action à réaliser à chaque avancée, évolution de l'objetSpaceInvadersGroupe.
     * @param phase : La phase d'évolution.
     */
    void advance(int phase) override;

};

#endif // OBJETSPACEINVADERSGROUPE_H
