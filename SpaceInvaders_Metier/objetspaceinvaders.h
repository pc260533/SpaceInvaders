#ifndef OBJETJEU_H
#define OBJETJEU_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QSize>



class SpaceInvaders;
class ObjetSpaceInvaders : public QGraphicsItem {

private:
    SpaceInvaders* spaceInvaders;
    QString cheminFichier;
    int positionX;
    int positionY;

    QPixmap pixmap;
    int hauteur;
    int largeur;
    int hauteurEcran;
    int largeurEcran;

public:
    ObjetSpaceInvaders(SpaceInvaders* spaceInvaders, QString cheminFichier, int positionX, int positionY);
    virtual ~ObjetSpaceInvaders();
    SpaceInvaders *getSpaceInvaders() const;
    int getPositionX() const;
    void setPositionX(int value);
    int getPositionY() const;
    void setPositionY(int value);

    void deplacerXY(int deplacementX, int deplacementY);

    virtual void evoluerDansLeTemsp() = 0;
    virtual void effetCollision(ObjetSpaceInvaders* objetSpaceInvaders) = 0;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;

};

#endif // OBJETJEU_H
