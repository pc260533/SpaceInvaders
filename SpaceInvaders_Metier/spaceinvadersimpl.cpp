#include "spaceinvadersimpl.h"

SpaceInvadersImpl::SpaceInvadersImpl() : SpaceInvaders() {

}

void SpaceInvadersImpl::actionAExecuterJeuPerdu() {

}

void SpaceInvadersImpl::actionAExecuterJeuGagne() {

}

bool SpaceInvadersImpl::jeuEstGagne() {

}

bool SpaceInvadersImpl::jeuEstPerdu() {

}

void SpaceInvadersImpl::initialiserObjetsJeu() {
    this->joueur = new Joueur(370, 550);
    QObject::connect(dynamic_cast<QObject*>(this->joueur), SIGNAL(nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmap*)));
    this->ajouterObjetSpaceInvadersPixmap(this->joueur);

    /*this->vagueEnnemis = new VagueEnnemis(50, 50);
    for (Ennemi* ennemi : this->vagueEnnemis->getListeEnnemis()) {
        QObject::connect(dynamic_cast<QObject*>(ennemi), SIGNAL(nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmap*)));
    }
    this->ajouterObjetSpaceInvadersGroupe(this->vagueEnnemis);*/

    /*this->ennemiMystere = new EnnemiMystere(-2000, 25);
    this->ajouterObjetSpaceInvadersPixmap(this->ennemiMystere);

    this->mur1 = new Mur(125, 450);
    this->mur2 = new Mur(271, 450);
    this->mur3 = new Mur(417, 450);
    this->mur4 = new Mur(563, 450);
    this->ajouterObjetSpaceInvadersGroupe(this->mur1);
    this->ajouterObjetSpaceInvadersGroupe(this->mur2);
    this->ajouterObjetSpaceInvadersGroupe(this->mur3);
    this->ajouterObjetSpaceInvadersGroupe(this->mur4);*/

    this->setFocus();
}

void SpaceInvadersImpl::initialiserArrierePlan() {
    //this->setBackgroundBrush(QPixmap(":/ressources/images/images/backgroundSpaceInvaders.jpg"));
    this->setBackgroundBrush(Qt::black);
}

void SpaceInvadersImpl::initialiserEvenements() {

}

void SpaceInvadersImpl::onKeyPressEvent(QKeyEvent *event) {
    this->joueur->onKeyPressedEvent(event);
}
