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
    QObject::connect(dynamic_cast<QObject*>(this->joueur), SIGNAL(nouveauObjetSpaceInvadersDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(ajouterObjetsSpaceInvadersAuJeu(ObjetSpaceInvadersPixmap*)));
    this->ajouterObjetSpaceInvaders(this->joueur);

    this->vagueEnnemis = new VagueEnnemis();
    this->addItem(this->vagueEnnemis);

    this->ennemiMystere = new EnnemiMystere(-2000, 25);
    this->ajouterObjetSpaceInvaders(this->ennemiMystere);

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
