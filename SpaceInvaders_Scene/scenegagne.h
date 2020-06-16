#ifndef SCENEGAGNE_H
#define SCENEGAGNE_H

#include "scenefindejeu.h"



/**
 * @brief Scene est la classe représentant une scène de fin de jeu gagné.
 * Elle hérite de SceneFinDeJeu.
 */
class SceneGagne : public SceneFinDeJeu {

private:
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte gagné.
     */
    ObjetSpaceInvadersTexte* gagneTextItem;

public:
    /**
     * @brief SceneGagne : Constructeur sans paramètres
     */
    SceneGagne();
    /**
     * @brief ~SceneGagne : Destructeur sans paramètres.
     */
    virtual ~SceneGagne();

    // Scene interface
public:
    /**
     * @brief initialiserObjetsJeu :  Initialiser les objetsSpaceInvaders de la scène gagné.
     */
    void initialiserObjetsJeu() override;
    /**
     * @brief initialiserArrierePlan : Initialiser l'arrière plan de la scène gagné.
     */
    void initialiserArrierePlan() override;
    /**
     * @brief getCheminMusiqueTheme : Retourner le chemin de la musique de thème gagné.
     * @return Le chemin de la musique de thème gagné.
     */
    QString getCheminMusiqueTheme() override;
};

#endif // SCENEGAGNE_H
