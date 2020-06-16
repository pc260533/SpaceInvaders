#ifndef MUR_H
#define MUR_H

#include <SpaceInvaders_Metier/objetspaceinvadersgroupe.h>
#include "partiedemur.h"

#include <QList>



/**
 * @brief Mur est la classe représentant un mur contenant des parties de mur.
 * Elle hérite de ObjetSpaceInvadersGroupe.
 */
class Mur : public ObjetSpaceInvadersGroupe {

private:
    /**
     * @brief listePartieDeMur : La liste des parties de mur.
     */
    QList<PartieDeMur*> listePartieDeMur;

private:
    /**
     * @brief creerMur : Créer toutes les parties de mur du mur.
     */
    void creerMur();

public:
    /**
     * @brief Mur : Constructeur prenant en paramètres la position en X et en Y de la première partie de mur en haut à gauche du mur.
     * @param positionX : La position en X de la première partie de mur.
     * @param positionY : La position en Y de la première partie de mur.
     */
    Mur(int positionX, int positionY);
    /**
     * @brief ~Mur : Destructeur sans paramètres.
     */
    virtual ~Mur();
    /**
     * @brief getListePartieDeMur : Retourner la liste des parties de mur.
     * @return La liste des parties de mur.
     */
    QList<PartieDeMur*> getListePartieDeMur() const;
    /**
     * @brief ajouterPartieDeMur : Ajouter une partie de mur à la liste des parties de mur.
     * @param partieDeMur : La partie de mur à ajouter.
     */
    void ajouterPartieDeMur(PartieDeMur* partieDeMur);
    /**
     * @brief supprimerPartieDeMur : Supprimer une partie de mur à la liste des parties de mur.
     * @param partieDeMur : La partie de mur à supprimer.
     */
    void supprimerPartieDeMur(PartieDeMur* partieDeMur);

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution du mur.
     */
    void evoluerDansLeTemsp() override;

};

#endif // MUR_H
