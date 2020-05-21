#ifndef ENNEMI_H
#define ENNEMI_H

#include "iobjetspaceinvaderstireur.h"
#include "objetspaceinvaders.h"

#include <QString>



class Ennemi : QObject, ObjetSpaceInvaders, IObjetSpaceInvadersTireur {
    Q_OBJECT

private:
    int chanceDeTirEnnemi;
    QString etatAnimationEnnemi;
    QString cheminFichierAnimationEnnemi1;
    QString cheminFichierAnimationEnnemi2;
    int vitesseEnnemi;

private:
    void initialiserAnimation();

public:
    Ennemi(QString cheminFichier, int positionX, int positionY);
    virtual ~Ennemi();
    void setCheminFichierAnimationEnnemi1(QString cheminFichierAnimationEnnemi1);
    void setCheminFichierAnimationEnnemi2(QString cheminFichierAnimationEnnemi2);

    virtual void initialiserFichiersAnimations() = 0;

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;
    void effetCollision(ObjetSpaceInvaders *objetSpaceInvaders) override;

    // IObjetSpaceInvadersTireur interface
public:
    void tirer() override;

};

#endif // ENNEMI_H
