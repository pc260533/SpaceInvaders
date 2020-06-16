#ifndef ENNEMI2_H
#define ENNEMI2_H

#include "ennemi.h"



/**
 * @brief Ennemi2 est la classe abstraite représentant un ennemi2.
 * Elle hérite de Ennemi.
 */
class Ennemi2 : public Ennemi {

public:
    /**
     * @brief Ennemi1 : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche de l'ennemi2.
     * @param positionX : La position en X de l'ennemi2.
     * @param positionY : La position en Y de l'ennemi2.
     */
    Ennemi2(int positionX, int positionY);
    /**
     * @brief ~Ennemi2 : Destructeur sans paramètres.
     */
    virtual ~Ennemi2();

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    /**
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type de l'ennemi2 pour faciliter la gestion des collisions.
     * @return Une chaine de caractère représentant le type de l'ennemi2 pour faciliter la gestion des collisions.
     */
    QString getTypeObjet() override;

    // Ennemi interface
public:
    /**
     * @brief getCheminFichierAnimationEnnemi1 : Retourner le chemin du fichier de la première image de l'animation de l'ennemi2.
     * @return Le chemin du fichier de la première image de l'animation de l'ennemi2.
     */
    QString getCheminFichierAnimationEnnemi1() override;
    /**
     * @brief getCheminFichierAnimationEnnemi2 : Retourner le chemin du fichier de la deuxième image de l'animation de l'ennemi2.
     * @return Le chemin du fichier de la deuxième image de l'animation de l'ennemi2.
     */
    QString getCheminFichierAnimationEnnemi2() override;

    // IEnnemi interface
public:
    /**
     * @brief getScoreEnnemi : Retourner le score correspondant à la destruction de l'ennemi2.
     * @return Le score correspondant à la destruction de l'ennemi2.
     */
    int getScoreEnnemi() override;

};

#endif // ENNEMI2_H
