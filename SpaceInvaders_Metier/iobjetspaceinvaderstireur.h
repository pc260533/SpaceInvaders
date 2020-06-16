#ifndef IOBJETSPACEINVADERSTIREUR_H
#define IOBJETSPACEINVADERSTIREUR_H



/**
 * @brief IObjetSpaceInvadersTireur est l'interface représentant les fonctionnalités d'un ObjetSpaceInvaders qui tire.
 */
class IObjetSpaceInvadersTireur {

public:
    /**
     * @brief IObjetSpaceInvadersTireur : Construeur sans paramètres.
     */
    IObjetSpaceInvadersTireur();
    /**
     * @brief ~IObjetSpaceInvadersTireur : Destructeur sans paramètres.
     */
    virtual ~IObjetSpaceInvadersTireur();

    /**
     * @brief tirer : Action à réaliser au tir.
     */
    virtual void tirer() = 0;

};

#endif // IOBJETSPACEINVADERSTIREUR_H
