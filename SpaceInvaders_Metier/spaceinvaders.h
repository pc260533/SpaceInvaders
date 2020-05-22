#ifndef JEU_H
#define JEU_H


#include "objetspaceinvaderspixmap.h"
#include "objetspaceinvadersgroupe.h"
#include "objetspaceinvaderstexte.h"

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
    QList<ObjetSpaceInvadersPixmap*> listeObjetsSpaceInvaders;

    QGraphicsView* graphicsView;

public:
    SpaceInvaders();
    virtual ~SpaceInvaders() override;

    int getHauteur() const;
    int getLargeur() const;
    void setGraphicsView(QGraphicsView *value);

    void ajouterObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);
    void supprimerObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);
    void ajouterObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe);
    void supprimerObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe);
    void ajouterObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte* objetSpaceInvadersTexte);
    void supprimerObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte* objetSpaceInvadersTexte);
    void jouer();

    virtual void actionAExecuterJeuPerdu() = 0;
    virtual void actionAExecuterJeuGagne() = 0;
    virtual bool jeuEstGagne() = 0;
    virtual bool jeuEstPerdu() = 0;
    virtual void initialiserObjetsJeu() = 0;
    virtual void initialiserArrierePlan() = 0;
    virtual void initialiserEvenements() = 0;
    virtual void onKeyPressEvent(QKeyEvent *event) = 0;

protected slots:
    void ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);
    virtual void supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap);


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // JEU_H
