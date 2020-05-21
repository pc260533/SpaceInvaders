#ifndef JEU_H
#define JEU_H

#include "objetspaceinvaders.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QString>



class SpaceInvaders {

private:
    QString titre;
    int longueur;
    int largeur;
    QList<ObjetSpaceInvaders*> listeObjetsSpaceInvaders;

    QGraphicsScene* graphicsSceneJeu;
    QGraphicsView* graphicsView;

public:
    SpaceInvaders();
    virtual ~SpaceInvaders();

    int getLongueur() const;
    int getLargeur() const;
    void setGraphicsView(QGraphicsView *value);
    QGraphicsScene *getGraphicsSceneJeu() const;
    void setGraphicsSceneJeu(QGraphicsScene *value);

    void ajouterObjetSpaceInvaders(ObjetSpaceInvaders* objetSpaceInvaders);
    void supprimerObjetSpaceInvaders(ObjetSpaceInvaders* objetSpaceInvaders);
    void jouer();

    virtual void actionAExecuterJeuPerdu() = 0;
    virtual void actionAExecuterJeuGagne() = 0;
    virtual bool jeuEstGagne() = 0;
    virtual bool jeuEstPerdu() = 0;
    virtual void initialiserObjetsJeu() = 0;
    virtual void initialiserArrierePlan() = 0;
    virtual void initialiserEvenements() = 0;

};

#endif // JEU_H
