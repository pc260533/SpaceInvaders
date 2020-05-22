#ifndef OBJETJEU_H
#define OBJETJEU_H

#include "objetspaceinvaders.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QSize>

#include <QDebug>



class ObjetSpaceInvadersPixmap : public QGraphicsPixmapItem, public ObjetSpaceInvaders {

private:
    QString cheminFichier;
    QPixmap pixmap;
    int hauteur;
    int largeur;

public:
    ObjetSpaceInvadersPixmap(QString cheminFichier, int positionX, int positionY);
    virtual ~ObjetSpaceInvadersPixmap() override;
    int getHauteur() const;
    int getLargeur() const;
    int getMilieuX() const;
    int getMilieuY() const;

    void deplacerXY(int deplacementX, int deplacementY);
    void changerImage(QString cheminFichier);

    // QGraphicsItem interface
public:
    void advance(int phase) override;

signals:
    virtual void nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap*) = 0;
    virtual void suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap*) = 0;

};

#endif // OBJETJEU_H
