#ifndef JEU_H
#define JEU_H

#include "objetspaceinvaderspixmapevoluable.h"
#include "objetspaceinvadersgroupe.h"
#include "objetspaceinvaderstexte.h"
#include "scene.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QString>
#include <QObject>

#include <QDebug>



class SpaceInvaders : public Scene {
    Q_OBJECT

private:
    QGraphicsView* graphicsView;
    QList<ObjetSpaceInvadersPixmapEvoluable*> listeObjetsSpaceInvadersASupprimer;

public:
    SpaceInvaders();
    virtual ~SpaceInvaders() override;

    QGraphicsView *getGraphicsView() const;
    void setGraphicsView(QGraphicsView* graphicsView);

    void jouer();

    virtual void actionAExecuterJeuPerdu() = 0;
    virtual void actionAExecuterJeuGagne() = 0;
    virtual bool jeuEstGagne() = 0;
    virtual bool jeuEstPerdu() = 0;
    virtual void onKeyPressEvent(QKeyEvent *event) = 0;
    virtual void onKeyReleaseEvent(QKeyEvent *event) = 0;

protected slots:
    void ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap);
    virtual void supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap);

public slots:
    virtual void evoluer();

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // JEU_H
