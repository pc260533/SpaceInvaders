#ifndef JEU_H
#define JEU_H


#include "objetspaceinvaders.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QString>
#include <QObject>

#include <QDebug>



class SpaceInvaders : public QGraphicsScene {
    Q_OBJECT

private:
    QString titre;
    int hauteur;
    int largeur;
    QList<ObjetSpaceInvaders*> listeObjetsSpaceInvaders;

    //QGraphicsScene* graphicsSceneJeu;
    QGraphicsView* graphicsView;

public:
    SpaceInvaders();
    virtual ~SpaceInvaders() override;

    int getHauteur() const;
    int getLargeur() const;
    void setGraphicsView(QGraphicsView *value);
    //QGraphicsScene *getGraphicsSceneJeu() const;
    //void setGraphicsSceneJeu(QGraphicsScene *value);

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
    virtual void onKeyPressEvent(QKeyEvent *event) = 0;

private slots:
    void ajouterObjetsSpaceInvadersAuJeu(ObjetSpaceInvaders* objetSpaceInvaders);
    void supprimerObjetsSpaceInvadersDuJeu(ObjetSpaceInvaders* objetSpaceInvaders);


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // JEU_H
