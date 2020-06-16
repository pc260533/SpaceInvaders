#ifndef SCENEPERDU_H
#define SCENEPERDU_H

#include "scenefindejeu.h"



/**
 * @brief Scene est la classe représentant une scène de fin de jeu perdu.
 * Elle hérite de SceneFinDeJeu.
 */
class ScenePerdu : public SceneFinDeJeu {

private:
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte perdu.
     */
    ObjetSpaceInvadersTexte* perduTextItem;

public:
    /**
     * @brief ScenePerdu : Constructeur sans paramètres.
     */
    ScenePerdu();
    /**
     * @brief ~ScenePerdu : Destructeur sans paramètres.
     */
    virtual ~ScenePerdu();

    // Scene interface
public:
    /**
     * @brief initialiserObjetsJeu :  Initialiser les objetsSpaceInvaders de la scène perdu.
     */
    void initialiserObjetsJeu() override;
    /**
     * @brief initialiserArrierePlan : Initialiser l'arrière plan de la scène perdu.
     */
    void initialiserArrierePlan() override;
    /**
     * @brief getCheminMusiqueTheme : Retourner le chemin de la musique de thème perdu.
     * @return Le chemin de la musique de thème perdu.
     */
    QString getCheminMusiqueTheme() override;

};

#endif // SCENEPERDU_H
