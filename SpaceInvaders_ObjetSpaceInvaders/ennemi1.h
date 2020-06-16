#ifndef ENNEMI1_H
#define ENNEMI1_H

#include "ennemi.h"



/**
 * @brief Ennemi1 est la classe abstraite représentant un ennemi1.
 * Elle hérite de Ennemi.
 */
class Ennemi1 : public Ennemi {

public:
    /**
     * @brief Ennemi1 : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche de l'ennemi1.
     * @param positionX : La position en X de l'ennemi1.
     * @param positionY : La position en Y de l'ennemi1.
     */
    Ennemi1(int positionX, int positionY);
    /**
     * @brief ~Ennemi1 : Destructeur sans paramètres.
     */
    virtual ~Ennemi1();

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    /**
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type de l'ennemi1 pour faciliter la gestion des collisions.
     * @return Une chaine de caractère représentant le type de l'ennemi1 pour faciliter la gestion des collisions.
     */
    QString getTypeObjet() override;

    // Ennemi interface
public:
    /**
     * @brief getCheminFichierAnimationEnnemi1 : Retourner le chemin du fichier de la première image de l'animation de l'ennemi1.
     * @return Le chemin du fichier de la première image de l'animation de l'ennemi1.
     */
    QString getCheminFichierAnimationEnnemi1() override;
    /**
     * @brief getCheminFichierAnimationEnnemi2 : Retourner le chemin du fichier de la deuxième image de l'animation de l'ennemi1.
     * @return Le chemin du fichier de la deuxième image de l'animation de l'ennemi1.
     */
    QString getCheminFichierAnimationEnnemi2() override;

    // IEnnemi interface
public:
    /**
     * @brief getScoreEnnemi : Retourner le score correspondant à la destruction de l'ennemi1.
     * @return Le score correspondant à la destruction de l'ennemi1.
     */
    int getScoreEnnemi() override;

};

#endif // ENNEMI1_H
