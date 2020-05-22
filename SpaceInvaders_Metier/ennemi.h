#ifndef ENNEMI_H
#define ENNEMI_H

#include "balleennemi.h"
#include "iennemi.h"
#include "iobjetspaceinvaderstireur.h"
#include "joueur.h"
#include "objetspaceinvaderspixmap.h"

#include <QObject>
#include <QString>
#include <QRandomGenerator>



class Ennemi : public QObject, public ObjetSpaceInvadersPixmap, public IObjetSpaceInvadersTireur, public IEnnemi {
    Q_OBJECT

private:
    static int chanceDeTirEnnemi;
    QString etatAnimationEnnemi;
    int vitesseEnnemi;
    int compteurChangementAnimation;

private:
    void animerEnnemi();
    void miseAJourChanceDeTirEnnemi();

public:
    Ennemi(QString cheminFichier, int positionX, int positionY);
    virtual ~Ennemi() override;

    virtual QString getCheminFichierAnimationEnnemi1() = 0;
    virtual QString getCheminFichierAnimationEnnemi2() = 0;

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmap interface
public:
    void effetCollision(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) override;

    // IObjetSpaceInvadersTireur interface
public:
    void tirer() override;

    // ObjetSpaceInvadersPixmap interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap *) override;

};

#endif // ENNEMI_H
