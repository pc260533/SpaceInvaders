#ifndef SCENE_H
#define SCENE_H

#include "objetspaceinvadersgroupe.h"
#include "objetspaceinvaderspixmapevoluable.h"
#include "objetspaceinvaderstexte.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QString>
#include <QObject>



class Scene : public QGraphicsScene {

private:
    QString titre;
    int hauteur;
    int largeur;

public:
    Scene();
    virtual ~Scene();

    int getHauteur() const;
    int getLargeur() const;

    void ajouterObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);
    void supprimerObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);
    void ajouterObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe);
    void supprimerObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe);
    void ajouterObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte* objetSpaceInvadersTexte);
    void supprimerObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte* objetSpaceInvadersTexte);

    virtual void initialiserObjetsJeu() = 0;
    virtual void initialiserArrierePlan() = 0;

};

#endif // SCENE_H
