#ifndef OBJETSPACEINVADERSPIXMAP_H
#define OBJETSPACEINVADERSPIXMAP_H

#include "objetspaceinvaders.h"

#include <QGraphicsItem>



class ObjetSpaceInvadersPixmap : public QGraphicsPixmapItem, public ObjetSpaceInvaders {

private:
    QString cheminFichier;
    QPixmap pixmap;
    int hauteur;
    int largeur;

public:
    ObjetSpaceInvadersPixmap(QString cheminFichier, int positionX, int positionY);
    virtual ~ObjetSpaceInvadersPixmap();
    int getHauteur() const;
    int getLargeur() const;
    int getMilieuX() const;
    int getMilieuY() const;

    void deplacerXY(int deplacementX, int deplacementY);
    void setPositionXY(int positionX, int positionY);
    void changerImage(QString cheminFichier);
};

#endif // OBJETSPACEINVADERSPIXMAP_H
