#ifndef ENNEMI_H
#define ENNEMI_H

#include "balleennemi.h"
#include "iennemi.h"
#include "iobjetspaceinvaderstireur.h"
#include "joueur.h"
#include "objetspaceinvaderspixmapevoluable.h"

#include <QObject>
#include <QString>
#include <QRandomGenerator>



class Ennemi : public QObject, public ObjetSpaceInvadersPixmapEvoluable, public IObjetSpaceInvadersTireur, public IEnnemi {
    Q_OBJECT

private:
    static int chanceDeTirEnnemi;
    QString etatAnimationEnnemi;
    int vitesseEnnemi;
    int compteurChangementAnimation;
    bool vaEtreDetruit;
    int compteurAvantDestruction;

private:
    void animerEnnemi();
    void miseAJourChanceDeTirEnnemi();

public:
    Ennemi(QString cheminFichier, int positionX, int positionY);
    virtual ~Ennemi() override;

    virtual QString getCheminFichierAnimationEnnemi1() = 0;
    virtual QString getCheminFichierAnimationEnnemi2() = 0;

    // IObjetSpaceInvadersEvoluable interface
public:
    void evoluerDansLeTemsp() override;

    // ObjetSpaceInvadersPixmapEvoluable interface
public:
    void effetCollision(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmapEvoluable) override;

    // IObjetSpaceInvadersTireur interface
public:
    void tirer() override;

    // IObjetSpaceInvadersEvoluable interface
signals:
    void nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;
    void suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable *) override;

};

#endif // ENNEMI_H
