#ifndef OBJETJEU_H
#define OBJETJEU_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QSize>

#include <QDebug>



class ObjetSpaceInvaders : public QGraphicsItem {

private:
    QString cheminFichier;
    int positionX;
    int positionY;

    QPixmap pixmap;
    int hauteur;
    int largeur;
    int hauteurEcran;
    int largeurEcran;

public:
    ObjetSpaceInvaders(QString cheminFichier, int positionX, int positionY);
    virtual ~ObjetSpaceInvaders() override;
    int getPositionX() const;
    void setPositionX(int value);
    int getPositionY() const;
    void setPositionY(int value);
    int getHauteurEcran() const;
    int getLargeurEcran() const;
    int getHauteur() const;
    int getLargeur() const;
    int getMilieuX() const;
    int getMilieuY() const;

    void deplacerXY(int deplacementX, int deplacementY);

    virtual void evoluerDansLeTemsp() = 0;
    virtual void effetCollision(ObjetSpaceInvaders* objetSpaceInvaders) = 0;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;

signals:
    virtual void nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvaders*) = 0;
    virtual void suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvaders*) = 0;

};

#endif // OBJETJEU_H
