#ifndef OBJETSPACEINVADERS_H
#define OBJETSPACEINVADERS_H

#include <QGraphicsItem>



class ObjetSpaceInvaders {

private:
    int positionX;
    int positionY;
    int hauteurEcran;
    int largeurEcran;

public:
    ObjetSpaceInvaders(int positionX, int positionY);
    virtual ~ObjetSpaceInvaders();
    int getPositionX() const;
    void setPositionX(int value);
    int getPositionY() const;
    void setPositionY(int value);
    int getHauteurEcran() const;
    int getLargeurEcran() const;

};

#endif // OBJETSPACEINVADERS_H
