#ifndef OBJETSPACEINVADERSPIXMAP_H
#define OBJETSPACEINVADERSPIXMAP_H

#include "objetspaceinvaders.h"

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QPixmap>
#include <QSize>



/**
 * @brief ObjetSpaceInvadersPixmap est la classe représentant un objet du jeu par une image.
 * Elle hérite de QGraphicsPixmapItem et ObjetSpaceInvaders.
 */
class ObjetSpaceInvadersPixmap : public QGraphicsPixmapItem, public ObjetSpaceInvaders {

private:
    /**
     * @brief cheminFichier : Le chemin du fichier de l'image représentant l'objetSpaceInvadersPixmap
     */
    QString cheminFichier;
    /**
     * @brief pixmap : Le pixmap représentant l'objetSpaceInvadersPixmap
     */
    QPixmap pixmap;
    /**
     * @brief hauteur : La hauteur de l'objetSpaceInvadersPixmap
     */
    int hauteur;
    /**
     * @brief largeur : La largeur de l'objetSpaceInvadersPixmap
     */
    int largeur;

public:
    /**
     * @brief ObjetSpaceInvadersPixmap : Constructeur prenant en paramètres le chemin du fichier image, la position en X et en Y du au coin en haut à gauche de l'image.
     * @param cheminFichier : Le chemin du fichier image.
     * @param positionX : La posistion en X.
     * @param positionY : La posistion en Y.
     */
    ObjetSpaceInvadersPixmap(QString cheminFichier, int positionX, int positionY);
    /**
     * @brief ~ObjetSpaceInvadersPixmap : Destructeur sans paramètres
     */
    virtual ~ObjetSpaceInvadersPixmap();
    /**
     * @brief getHauteur :  Retourner la hauteur de l'objetSpaceInvadersPixmap
     * @return La hauteur de l'image.
     */
    int getHauteur() const;
    /**
     * @brief getLargeur : Retourner la largeur de l'objetSpaceInvadersPixmap.
     * @return La largeur de l'image.
     */
    int getLargeur() const;
    /**
     * @brief getMilieuX : Retourner le milieu en X de l'objetSpaceInvadersPixmap.
     * @return Le milieu en X de l'image.
     */
    int getMilieuX() const;
    /**
     * @brief getMilieuY : Retourner le milieu en Y de l'objetSpaceInvadersPixmap.
     * @return Le milieu en Y de l'image.
     */
    int getMilieuY() const;

    /**
     * @brief deplacerXY : Deplacer l'objetSpaceInvadersPixmap de deplacementX en X et de deplacementY en Y.
     * @param deplacementX : Le déplacement en X
     * @param deplacementY : Le déplacement en Y.
     */
    void deplacerXY(int deplacementX, int deplacementY);
    /**
     * @brief setPositionXY Modifier la position en X et en Y de l'objetSpaceInvadersPixmap.
     * @param positionX : La nouvelle position en X de l'objetSpaceInvadersPixmap.
     * @param positionY : La nouvelle position en Y de l'objetSpaceInvadersPixmap.
     */
    void setPositionXY(int positionX, int positionY);
    /**
     * @brief changerImage : Changer l'image afficher par l'objetSpaceInvadersPixmap.
     * @param cheminFichier Le nouveau chemin du fichier de l'image.
     */
    void changerImage(QString cheminFichier);

};

#endif // OBJETSPACEINVADERSPIXMAP_H
