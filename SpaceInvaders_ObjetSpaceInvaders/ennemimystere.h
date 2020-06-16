#ifndef ENNEMIMYSTERE_H
#define ENNEMIMYSTERE_H

#include "iennemi.h"
#include <SpaceInvaders_Metier/objetspaceinvaderspixmapevoluable.h>

#include <QObject>
#include <QMediaPlayer>



/**
 * @brief EnnemiMystere est la classe représentant un ennemi mystère.
 * Elle hérite de ObjetSpaceInvadersPixmapEvoluable.
 * Elle implémente IEnnemi.
 * Elle hérite aussi de QObject pour les signaux et slots.
 */
class EnnemiMystere : public QObject, public ObjetSpaceInvadersPixmapEvoluable, public IEnnemi {
    Q_OBJECT

private:
    /**
     * @brief vitesseEnnemiMystere : La vitesse de l'ennemi mystère.
     */
    int vitesseEnnemiMystere;
    /**
     * @brief directionEnnemiMystere : La direction de l'ennemi mystère.
     */
    int directionEnnemiMystere;

    /**
     * @brief playerEnnemiMystereEntre : Le mediaPlayer qui joue le son d'entrée dans la scène visible de l'ennemi mystère.
     */
    QMediaPlayer* playerEnnemiMystereEntre;
    /**
     * @brief playerEnnemiMystereTue : Le mediaPlayer qui joue le son d'ennemi mystère détruit.
     */
    QMediaPlayer* playerEnnemiMystereTue;

public:
    /**
     * @brief EnnemiMystere : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche de l'ennemi mystère.
     * @param positionX : La position en X de l'ennemi mystère.
     * @param positionY : La position en Y de l'ennemi mystère.
     */
    EnnemiMystere(int positionX, int positionY);
    /**
     * @brief ~EnnemiMystere : Destructeur sans paramètres.
     */
    virtual ~EnnemiMystere();

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution de l'ennemi mystère.
     */
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    /**
     * @brief effetCollision : Action à éxecuter en cas de collision avec un autre objetSpaceInvadersPixmapEvoluable.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable avec qui on collisionne.
     */
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmapEvoluable) override;
    /**
     * @brief getTypeObjet :  Retourner une chaine de caractère représentant le type de l'ennemi mystère pour faciliter la gestion des collisions.
     * @return Une chaine de caractère représentant le type de l'ennemi mystère pour faciliter la gestion des collisions.
     */
    QString getTypeObjet() override;

    // IEnnemi interface
public:
    /**
     * @brief getScoreEnnemi : Retourner le score correspondant à la destruction de l'ennemi mystère.
     * @return Le score correspondant à la destruction de l'ennemi mystère.
     */
    int getScoreEnnemi() override;

    // ObjetSpaceInvadersPixmap interface
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

#endif // ENNEMIMYSTERE_H
