#ifndef VAGUEENNEMIS_H
#define VAGUEENNEMIS_H

#include "ennemi.h"
#include "ennemi1.h"
#include "ennemi2.h"
#include "ennemi3.h"
#include <SpaceInvaders_Metier/objetspaceinvadersgroupe.h>

#include <QList>
#include <QRandomGenerator>



/**
 * @brief VagueEnnemis est la classe représentant une vague d'ennemis contenant des ennemis.
 * Elle hérite de ObjetSpaceInvadersGroupe.
 */
class VagueEnnemis : public ObjetSpaceInvadersGroupe {

private:
    /**
     * @brief listeEnnemis : La liste d'ennemis.
     */
    QList<Ennemi*> listeEnnemis;
    /**
     * @brief vitesseX : La vitesse en X de la vague ennemis.
     */
    int vitesseX;
    /**
     * @brief vitesseY : La vitesse en Y de la vague ennemis.
     */
    int vitesseY;
    /**
     * @brief direction : La direction de la vague ennemis.
     */
    int direction;
    /**
     * @brief compteurDeplacement : La valeur du compteur à incrémenter qu'il faut atteindre avant de déplacer la vague ennemis.
     */
    int compteurDeplacement;
    /**
     * @brief compteurDeplacementMaximal : La valeur maximale du compteur à incrémenter qu'il faut atteindre avant de déplacer la vague ennemis.
     */
    int compteurDeplacementMaximal;
    /**
     * @brief chanceDeTirEnnemi : La valeur maximale à comparer à un nombre tiré aléatoirement pour qu'un ennemi de la vague ennemis tir.
     */
    int chanceDeTirEnnemi;

private:
    /**
     * @brief creerVague : Créer tous les ennmis de la vague ennemis.
     */
    void creerVague();
    /**
     * @brief descendreVagueEnnemis : Descendre tous les ennemis de la vague ennmis vers le bas.
     */
    void descendreVagueEnnemis();
    /**
     * @brief testChangementDeDirectionVagueEnnemis : Retourner un booléen indiquant si l'ennemi de la vague ennemis doit changer de direction en X.
     * @param ennemi : L'eenmi à tester.
     * @return Le booléen indiquant si l'ennemi de la vague ennemis doit changer de direction en X.
     */
    bool testChangementDeDirectionVagueEnnemis(Ennemi* ennemi);
    /**
     * @brief deplacerVagueEnnemis : Déplacer tous les ennemis de la vague ennemis en X et en Y.
     */
    void deplacerVagueEnnemis();
    /**
     * @brief miseAJourChanceDeTirEnnemi : Mettre à jour la valeur maximale à comparer à un nombre tiré aléatoirement pour qu'un ennemi de la vague ennemis tir.
     */
    void miseAJourChanceDeTirEnnemi();
    /**
     * @brief miseAJourCompteurDeplacementMaximal : Mettre à jour la valeur maximale du compteur à incrémenter qu'il faut atteindre avant de déplacer la vague ennemis.
     */
    void miseAJourCompteurDeplacementMaximal();

public:
    /**
     * @brief VagueEnnemis : Constructeur prenant en paramètres la position en X et en Y du premier ennemi en haut à gauche de la vague ennemis.
     * @param positionX : La position en X du premier ennemi.
     * @param positionY : La position en Y du premier ennemi.
     */
    VagueEnnemis(int positionX, int positionY);
    /**
     * @brief ~VagueEnnemis : Destructeur sans paramètres.
     */
    virtual ~VagueEnnemis();
    /**
     * @brief getListeEnnemis : Retourner la liste des ennemis.
     * @return La liste des ennemis.
     */
    QList<Ennemi*> getListeEnnemis() const;
    /**
     * @brief ajouterEnnemi : Ajouter un ennemi à la liste des ennemis
     * @param ennemi : L'ennemi à ajouter.
     */
    void ajouterEnnemi(Ennemi* ennemi);
    /**
     * @brief supprimerEnnemi : Supprimer un ennemi à la liste des ennemis
     * @param ennemi : L'ennemi à supprimer.
     */
    void supprimerEnnemi(Ennemi* ennemi);
    /**
     * @brief contientAucunEnnemis : Retourner un booléen indiquant si la vague ennemis ne contient aucun ennemis.
     * @return Le booléen indiquant si la vague ennemis ne contient aucun ennemis.
     */
    bool contientAucunEnnemis();

    // IObjetSpaceInvadersEvoluable interface
public:
    /**
     * @brief evoluerDansLeTemsp : Action à réaliser à chaque évolution de la vague ennemis.
     */
    void evoluerDansLeTemsp() override;

};

#endif // VAGUEENNEMIS_H
