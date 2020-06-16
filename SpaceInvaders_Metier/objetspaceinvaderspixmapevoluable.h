#ifndef OBJETSPACEINVADERSPIXMAPJOUABLE_H
#define OBJETSPACEINVADERSPIXMAPJOUABLE_H

#include "iobjetspaceinvadersevoluable.h"
#include "objetspaceinvaderspixmap.h"



/**
 * @brief ObjetSpaceInvadersPixmapEvoluable est la classe représentant un ObjetSpaceInvadersPixmap qui évolue dans le temps.
 * Elle hérite de ObjetSpaceInvadersPixmap.
 * Elle implémente IObjetSpaceInvadersEvoluable.
 */
class ObjetSpaceInvadersPixmapEvoluable : public ObjetSpaceInvadersPixmap, public IObjetSpaceInvadersEvoluable {

public:
    /**
     * @brief ObjetSpaceInvadersPixmapEvoluable : Constructeur prenant en paramètres le chemin du fichier image, la position en X et en Y du au coin en haut à gauche de l'image.
     * @param cheminFichier : Le chemin du fichier image.
     * @param positionX : La posistion en X.
     * @param positionY : La posistion en Y.
     */
    ObjetSpaceInvadersPixmapEvoluable(QString cheminFichier, int positionX, int positionY);
    /**
     * @brief ~ObjetSpaceInvadersPixmapEvoluable : Destructeur sans paramètres.
     */
    virtual ~ObjetSpaceInvadersPixmapEvoluable();

    /**
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type de l'objetSpaceInvadersPixmapEvoluable pour faciliter la gestion des collisions.
     * @return
     */
    virtual QString getTypeObjet() = 0;

    /**
     * @brief effetCollision : Action à éxecuter en cas de collision avec un autre objetSpaceInvadersPixmapEvoluable.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable avec qui on collisionne.
     */
    virtual void effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap) = 0;

    // QGraphicsPixmapItem interface
public:
    /**
     * @brief advance : Action à réaliser à chaque avancée, évolution de l'objetSpaceInvadersPixmapEvoluable.
     * @param phase : La phase d'évolution.
     */
    void advance(int phase) override;

signals:
    /**
     * @brief nouveauObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un nouvel objetSpaceInvadersPixmapEvoluable doit être créé.
     */
    virtual void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) = 0;
    /**
     * @brief suppressionObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un objetSpaceInvadersPixmapEvoluable doit être supprimé.
     */
    virtual void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) = 0;

};

#endif // OBJETSPACEINVADERSPIXMAPJOUABLE_H
