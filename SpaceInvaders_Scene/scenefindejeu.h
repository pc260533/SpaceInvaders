#ifndef SCENEFINDEJEU_H
#define SCENEFINDEJEU_H

#include <SpaceInvaders_Metier/scene.h>



/**
 * @brief Scene est la classe abstraite représentant une scène de fin de jeu : gagné ou perdu.
 * Elle hérite de Scene.
 */
class SceneFinDeJeu : public Scene {

private:
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte rejouer.
     */
    ObjetSpaceInvadersTexte* rejouerTextItem;

public:
    /**
     * @brief SceneFinDeJeu : Constructeur sans paramètres.
     */
    SceneFinDeJeu();
    /**
     * @brief ~SceneFinDeJeu : Destructeur sans paramètres.
     */
    virtual ~SceneFinDeJeu();

    // Scene interface
public:
    /**
     * @brief initialiserObjetsJeu :  Initialiser les objetsSpaceInvaders de la scène de fin de jeu.
     */
    void initialiserObjetsJeu() override;
    /**
     * @brief initialiserArrierePlan : Initialiser l'arrière plan de la scène de fin de jeu.
     */
    void initialiserArrierePlan() override;

};

#endif // SCENEFINDEJEU_H
