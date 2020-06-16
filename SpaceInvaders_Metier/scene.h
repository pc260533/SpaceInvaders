#ifndef SCENE_H
#define SCENE_H

#include "objetspaceinvadersgroupe.h"
#include "objetspaceinvaderspixmapevoluable.h"
#include "objetspaceinvaderstexte.h"

#include <QFontDatabase>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QString>
#include <QObject>

#include <QDebug>



/**
 * @brief Scene est la classe représentant une scène du jeu.
 * Elle hérite de QGraphicsScene.
 */
class Scene : public QGraphicsScene {

private:
    /**
     * @brief titre : Le titre de la scène.
     */
    QString titre;
    /**
     * @brief hauteur : La hauteur de la scene.
     */
    int hauteur;
    /**
     * @brief largeur : La largeur de la scene.
     */
    int largeur;

    /**
     * @brief player : Le mediaPlayer qui joue la musique de thème de la scène.
     */
    QMediaPlayer* player;

public:
    /**
     * @brief Scene : Constructeur Scene sans paramètres.
     */
    Scene();
    /**
     * @brief ~Scene : Destructeur Scene sans paramètres.
     */
    virtual ~Scene();

    /**
     * @brief getHauteur : Retourner la hauteur de la scène.
     * @return La hauteur de la scène.
     */
    int getHauteur() const;
    /**
     * @brief getLargeur : Retourner la largeur de la scène.
     * @return La largeur de la scène.
     */
    int getLargeur() const;

    /**
     * @brief getFontSpaceInvaders : Retourner la police de caractères utilisées pour les scènes.
     * @return La police de caractères utilisées pour les scènes.
     */
    QFont getFontSpaceInvaders();

    /**
     * @brief ajouterObjetSpaceInvadersPixmap : Ajouter un objetSpaceInvadersPixmap à la scène.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmap à ajouter.
     */
    void ajouterObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);
    /**
     * @brief supprimerObjetSpaceInvadersPixmap : Supprimer un objetSpaceInvadersPixmap de la scène.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmap à supprimer.
     */
    void supprimerObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);
    /**
     * @brief ajouterObjetSpaceInvadersGroupe : Ajouter un ajouterObjetSpaceInvadersGroupe à la scène.
     * @param objetSpaceInvadersGroupe : L'objetSpaceInvadersGroupe à ajouter.
     */
    void ajouterObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe);
    /**
     * @brief supprimerObjetSpaceInvadersGroupe : Supprimer un objetSpaceInvadersGroupe de la scène.
     * @param objetSpaceInvadersGroupe : L'objetSpaceInvadersGroupe à supprimer.
     */
    void supprimerObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe);
    /**
     * @brief ajouterObjetSpaceInvadersTexte : Ajouter un objetSpaceInvadersTexte à la scène.
     * @param objetSpaceInvadersTexte : L'objetSpaceInvadersTexte à ajouter.
     */
    void ajouterObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte* objetSpaceInvadersTexte);
    /**
     * @brief supprimerObjetSpaceInvadersTexte : Supprimer un objetSpaceInvadersTexte de la scène.
     * @param objetSpaceInvadersTexte : L'objetSpaceInvadersTexte à supprimer.
     */
    void supprimerObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte* objetSpaceInvadersTexte);

    /**
     * @brief supprimerTousLesItems : Supprimer tous les QGraphicsItems de la QGraphicsScene.
     */
    void supprimerTousLesItems();

    /**
     * @brief lancerMusiqueTheme : Lancer la musique de thème.
     */
    void lancerMusiqueTheme();
    /**
     * @brief stopperMusiqueTheme : Stoppper la musique de thème.
     */
    void stopperMusiqueTheme();
    /**
     * @brief getCheminMusiqueTheme : Retourner le chemin de la musique de thème.
     * @return Le chemin de la musique de thème.
     */
    virtual QString getCheminMusiqueTheme() = 0;

    /**
     * @brief initialiserObjetsJeu :  Initialiser les objetsSpaceInvaders de la scène.
     */
    virtual void initialiserObjetsJeu() = 0;
    /**
     * @brief initialiserArrierePlan : Initialiser l'arrière plan de la scène.
     */
    virtual void initialiserArrierePlan() = 0;
    /**
     * @brief initialiserScene : Initialiser la scène.
     */
    virtual void initialiserScene();
    /**
     * @brief reinitialiserScene :  Réinitialiser la scène sans la détruire, supprimer tous les objets de la scène.
     */
    virtual void reinitialiserScene();

};

#endif // SCENE_H
