#ifndef OBJETSPACEINVADERS_H
#define OBJETSPACEINVADERS_H

#include <QDebug>



/**
 * @brief ObjetSpaceInvaders est la classe abstraite représentant un objet du jeu.
 */
class ObjetSpaceInvaders {

private:
    /**
     * @brief positionX : La position en X de l'objet.
     */
    int positionX;
    /**
     * @brief positionY : la position en Y de l'objet.
     */
    int positionY;
    /**
     * @brief hauteurEcran : La hauteur de l'écran de jeu.
     */
    int hauteurEcran;
    /**
     * @brief largeurEcran : La largeur de l'écran de jeu.
     */
    int largeurEcran;

public:
    /**
     * @brief ObjetSpaceInvaders : Constructeur prenant en paramètres la position en X et en Y de l'objet.
     * @param positionX : La position en X de l'objet.
     * @param positionY : La position en Y de l'objet.
     */
    ObjetSpaceInvaders(int positionX, int positionY);
    /**
     * @brief ~ObjetSpaceInvaders : Destructeur sans paramètres.
     */
    virtual ~ObjetSpaceInvaders();
    /**
     * @brief getPositionX : Retourner la position en X.
     * @return La position en X.
     */
    int getPositionX() const;
    /**
     * @brief setPositionX : Modifier la position en X.
     * @param positionX : La nouvelle position en X.
     */
    void setPositionX(int positionX);
    /**
     * @brief getPositionY : Retourner la position en Y.
     * @return La position en Y.
     */
    int getPositionY() const;
    /**
     * @brief setPositionY : Modifier la position en Y.
     * @param positionY La nouvelle position en Y.
     */
    void setPositionY(int positionY);
    /**
     * @brief getHauteurEcran : Retourner la hauteur de l'écran.
     * @return La hauteur de l'écran.
     */
    int getHauteurEcran() const;
    /**
     * @brief getLargeurEcran : Retourner la largeur de l'écran.
     * @return La largeur de l'écran.
     */
    int getLargeurEcran() const;

};

#endif // OBJETSPACEINVADERS_H
