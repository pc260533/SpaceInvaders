#ifndef OBJETSPACEINVADERSBOUGEABLECLAVIER_H
#define OBJETSPACEINVADERSBOUGEABLECLAVIER_H

#include <QKeyEvent>



/**
 * @brief IObjetSpaceInvadersBougeableClavier est l'interface représentant les fonctionnalités d'un ObjetSpaceInvaders capturant les événements clavier.
 */
class IObjetSpaceInvadersBougeableClavier {

public:
    /**
     * @brief IObjetSpaceInvadersBougeableClavier : Constructeur sans paramètres.
     */
    IObjetSpaceInvadersBougeableClavier();
    /**
     * @brief ~IObjetSpaceInvadersBougeableClavier : Destructeur sans paramètres.
     */
    virtual ~IObjetSpaceInvadersBougeableClavier();

    /**
     * @brief onKeyPressedEvent : Action à réaliser après la détection d'une touche du clavier pressée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier pressée.
     */
    virtual void onKeyPressedEvent(QKeyEvent* event) = 0;
    /**
     * @brief onKeyPressedEvent : Action à réaliser après la détection d'une touche du clavier relachée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier relachée.
     */
    virtual void onKeyReleasedEvent(QKeyEvent* event) = 0;

};

#endif // OBJETSPACEINVADERSBOUGEABLECLAVIER_H
