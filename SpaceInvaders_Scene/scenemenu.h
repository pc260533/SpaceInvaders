#ifndef SCENEMENU_H
#define SCENEMENU_H

#include <SpaceInvaders_Metier/scene.h>



/**
 * @brief Scene est la classe représentant une scène de menu.
 * Elle hérite de Scene.
 */
class SceneMenu : public Scene {

private:
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte ennemi1.
     */
    ObjetSpaceInvadersTexte* ennemi1TextItem;
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte ennemi2.
     */
    ObjetSpaceInvadersTexte* ennemi2TextItem;
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte ennemi3.
     */
    ObjetSpaceInvadersTexte* ennemi3TextItem;
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte ennemiMystere.
     */
    ObjetSpaceInvadersTexte* ennemiMystereTextItem;
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte jouer.
     */
    ObjetSpaceInvadersTexte* jouerTextItem;
    /**
     * @brief rejouerTextItem : L'objetSpaceInvadersTextItem représentant le texte quitter.
     */
    ObjetSpaceInvadersTexte* quitterTextItem;
    /**
     * @brief ennemi1PixmapItem : L'objetSpaceInvadersPixmap représentant l'image ennemi1.
     */
    ObjetSpaceInvadersPixmap* ennemi1PixmapItem;
    /**
     * @brief ennemi1PixmapItem : L'objetSpaceInvadersPixmap représentant l'image ennemi2.
     */
    ObjetSpaceInvadersPixmap* ennemi2PixmapItem;
    /**
     * @brief ennemi1PixmapItem : L'objetSpaceInvadersPixmap représentant l'image ennemi3.
     */
    ObjetSpaceInvadersPixmap* ennemi3PixmapItem;
    /**
     * @brief ennemi1PixmapItem : L'objetSpaceInvadersPixmap représentant l'image ennemiMystere.
     */
    ObjetSpaceInvadersPixmap* ennemiMysterePixmapItem;
    /**
     * @brief ennemi1PixmapItem : L'objetSpaceInvadersPixmap représentant l'image logo.
     */
    ObjetSpaceInvadersPixmap* logoPixmapItem;

public:
    /**
     * @brief SceneMenu : Constructeur sans paramètres.
     */
    SceneMenu();
    /**
     * @brief ~SceneMenu : Destructeur sans paramètres.
     */
    virtual ~SceneMenu();

    // Scene interface
public:
    /**
     * @brief initialiserObjetsJeu :  Initialiser les objetsSpaceInvaders de la scène de menu.
     */
    void initialiserObjetsJeu() override;
    /**
     * @brief initialiserObjetsJeu :  Initialiser l'arrière plan de la scène de menu.
     */
    void initialiserArrierePlan() override;
    /**
     * @brief getCheminMusiqueTheme : Retourner le chemin de la musique de thème de menu.
     * @return Le chemin de la musique de thème de menu.
     */
    QString getCheminMusiqueTheme() override;

};

#endif // SCENEMENU_H
