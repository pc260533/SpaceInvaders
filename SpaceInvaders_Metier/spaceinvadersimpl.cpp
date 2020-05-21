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
    //this->joueur = new Joueur(0, 266);

    QObject::connect(dynamic_cast<QObject*>(this->joueur), SIGNAL(nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvaders*)), this, SLOT(ajouterObjetsSpaceInvadersAuJeu(ObjetSpaceInvaders*)));

    this->ajouterObjetSpaceInvaders(this->joueur);
    this->getGraphicsSceneJeu()->setFocusItem(this->joueur);

}

void SpaceInvadersImpl::initialiserArrierePlan() {
    this->getGraphicsSceneJeu()->setBackgroundBrush(QPixmap(":/ressources/images/images/backgroundSpaceInvaders.jpg"));
}

void SpaceInvadersImpl::initialiserEvenements() {

}
