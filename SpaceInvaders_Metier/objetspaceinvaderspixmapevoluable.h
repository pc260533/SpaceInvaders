#ifndef OBJETJEU_H
#define OBJETJEU_H

#include "iobjetspaceinvadersevoluable.h"
#include "objetspaceinvaderspixmap.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QSize>

#include <QDebug>



class ObjetSpaceInvadersPixmapEvoluable : public ObjetSpaceInvadersPixmap, public IObjetSpaceInvadersEvoluable {

public:
    ObjetSpaceInvadersPixmapEvoluable(QString cheminFichier, int positionX, int positionY);
    virtual ~ObjetSpaceInvadersPixmapEvoluable();

    virtual QString getTypeObjet() = 0;

    virtual void effetCollision(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap) = 0;

    // QGraphicsItem interface
public:
    void advance(int phase) override;

signals:
    virtual void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) = 0;
    virtual void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*) = 0;

};

#endif // OBJETJEU_H
