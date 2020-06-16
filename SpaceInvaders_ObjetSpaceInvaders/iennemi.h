#ifndef IENNEMI_H
#define IENNEMI_H



/**
 * @brief IEnnemi est l'interface représentant les fonctionnalités d'un ennemi.
 */
class IEnnemi {

public:
    /**
     * @brief IEnnemi : Constructeur sans paramètres.
     */
    IEnnemi();
    /**
     * @brief ~IEnnemi : Destructeur sans paramètres.
     */
    virtual ~IEnnemi();

    /**
     * @brief getScoreEnnemi : Retourner le score correspondant à la destruction de l'ennemi.
     * @return Le score correspondant à la destruction de l'ennemi.
     */
    virtual int getScoreEnnemi() = 0;

};

#endif // IENNEMI_H
