#ifndef PARTIEDEMUR_H
#define PARTIEDEMUR_H

#include <SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h>

#include <QObject>


/**
 * @brief PartieDeMur est la classe représentant une partie de mur.
 * Elle hérite de ObjetSpaceInvadersPixmapEvoluable.
 * Elle hérite aussi de QObject pour les signaux et slots.
 */
class PartieDeMur : public QObject, public ObjetSpaceInvadersPixmapEvoluable {
    Q_OBJECT

public:
    /**
     * @brief PartieDeMur : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche de la partie de mur.
     * @param positionX : La position en X de la partie de mur.
     * @param positionY : La position en Y de la partie de mur.
     */
    PartieDeMur(int positionX, int positionY);
    /**
     * @brief ~PartieDeMur : Destructeur sans paramètres.
     */
    virtual ~PartieDeMur();

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution de la partieDeMur.
     */
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    /**
     * @brief effetCollision : Action à éxecuter en cas de collision avec un autre objetSpaceInvadersPixmapEvoluable.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable avec qui on collisionne.
     */
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap) override;
    /**
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type de la partie de mur pour faciliter la gestion des collisions.
     * @return Une chaine de caractère représentant le type de la partie de mur pour faciliter la gestion des collisions.
     */
    QString getTypeObjet() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
signals:
    /**
     * @brief nouveauObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un nouvel objetSpaceInvadersPixmapEvoluable doit être créé.
     */
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;
    /**
     * @brief suppressionObjetSpaceInvadersPixmapDansJeu : Signal envoyé lorqu'un objetSpaceInvadersPixmapEvoluable doit être supprimé.
     */
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) override;

};

#endif // PARTIEDEMUR_H
