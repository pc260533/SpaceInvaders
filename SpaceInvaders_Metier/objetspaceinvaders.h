#ifndef OBJETSPACEINVADERS_H
#define OBJETSPACEINVADERS_H



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

    virtual void evoluerDansLeTemsp() = 0;
    virtual void effetCollision(ObjetSpaceInvaders* objetSpaceInvaders) = 0;

};

#endif // OBJETSPACEINVADERS_H
