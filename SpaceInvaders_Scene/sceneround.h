#ifndef SCENEROUND_H
#define SCENEROUND_H

#include <SpaceInvaders_Metier/scene.h>



/**
 * @brief Scene est la classe représentant une scène de changement de round.
 * Elle hérite de Scene.
 */
class SceneRound : public Scene {

private:
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte nouveau round.
     */
    ObjetSpaceInvadersTexte* nextRoundTextItem;

public:
    /**
     * @brief SceneRound : Constructeur sans paramètres.
     */
    SceneRound();
    /**
     * @brief ~SceneRound : Destructeur sans paramètres.
     */
    virtual ~SceneRound();

    // Scene interface
public:
    /**
     * @brief initialiserObjetsJeu :  Initialiser les objetsSpaceInvaders de la scène round.
     */
    void initialiserObjetsJeu() override;
    /**
     * @brief initialiserArrierePlan : Initialiser l'arrière plan de la scène de round.
     */
    void initialiserArrierePlan() override;
    /**
     * @brief getCheminMusiqueTheme : Retourner le chemin de la musique de thème de changement de round.
     * @return Le chemin de la musique de thème de changement de round.
     */
    QString getCheminMusiqueTheme() override;

};

#endif // SCENEROUND_H
