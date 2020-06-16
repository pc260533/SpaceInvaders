#ifndef BALLE_H
#define BALLE_H

#include <SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h>



/**
 * @brief Balle est la classe abstraite représentant une balle.
 * Elle hérite de ObjetSpaceInvadersPixmapEvoluable.
 */
class Balle : public ObjetSpaceInvadersPixmapEvoluable {

public:
    /**
     * @brief Balle : Constructeur prenant en paramètres le chemin du fichier image de la balle, la position en X et en Y du au coin en haut à gauche de la balle.
     * @param cheminFichier : Le chemin du fichier image de la balle.
     * @param positionX : La posistion en X de la balle.
     * @param positionY : La posistion en Y de la balle.
     */
    Balle(QString cheminFichier, int positionX, int positionY);
    /**
     * @brief ~Balle : Destructeur sans paramètres.
     */
    virtual ~Balle();

};

#endif // BALLE_H
