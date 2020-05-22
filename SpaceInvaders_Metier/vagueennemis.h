#ifndef VAGUEENNEMIS_H
#define VAGUEENNEMIS_H

#include "ennemi.h"
#include "ennemi1.h"
#include "ennemi2.h"
#include "ennemi3.h"

#include <QList>



class VagueEnnemis : public QGraphicsItemGroup {

private:
    QList<Ennemi*> listeEnnemis;
    int positionDebutX;
    int positionDebutY;
    int vitesseX;
    int vitesseY;
    int direction;

private:
    void descendreVagueEnnemis();
    bool testChangementDeDirectionVagueEnnemis(Ennemi* ennemi);
    void deplacerVagueEnnemis();

public:
    VagueEnnemis();
    virtual ~VagueEnnemis() override;
    void creerVague();
    void ajouterEnnemi(Ennemi* ennemi);
    void supprimerEnnemi(Ennemi* ennemi);
    bool contientAucunEnnemis();
    void detruireVagueEnnemi();

    // QGraphicsItem interface
public:
    void advance(int phase) override;

};

#endif // VAGUEENNEMIS_H
