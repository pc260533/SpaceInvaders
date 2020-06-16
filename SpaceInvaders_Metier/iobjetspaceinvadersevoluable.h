#ifndef IOBJETSPACEINVADERSEVOLUABLE_H
#define IOBJETSPACEINVADERSEVOLUABLE_H



/**
 * @brief IObjetSpaceInvadersEvoluable est l'interface représentant les fonctionnalités d'un ObjetSpaceInvaders qui évolue dans le temps.
 */
class IObjetSpaceInvadersEvoluable  {

public:
    /**
     * @brief IObjetSpaceInvadersEvoluable : Constructeur sans paramètres.
     */
    IObjetSpaceInvadersEvoluable();
    /**
     * @brief ~IObjetSpaceInvadersEvoluable : Destructeur sans paramètres.
     */
    virtual ~IObjetSpaceInvadersEvoluable();

    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution de l'objetSpaceInvaders.
     */
    virtual void evoluerDansLeTemsp() = 0;

};

#endif // IOBJETSPACEINVADERSEVOLUABLE_H
