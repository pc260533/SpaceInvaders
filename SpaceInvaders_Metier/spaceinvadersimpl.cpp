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
    //this->getGraphicsSceneJeu()->setFocusItem(this->joueur);
    this->setFocus();
}

void SpaceInvadersImpl::initialiserArrierePlan() {
    //this->getGraphicsSceneJeu()->setBackgroundBrush(QPixmap(":/ressources/images/images/backgroundSpaceInvaders.jpg"));
    //this->setBackgroundBrush(QPixmap(":/ressources/images/images/backgroundSpaceInvaders.jpg"));
    this->setBackgroundBrush(Qt::black);
    //QPen pen = QPen(Qt::red);
    //QLineF top(this->sceneRect().topLeft(), this->sceneRect().topRight());
    //this->addLine(top, pen);
}

void SpaceInvadersImpl::initialiserEvenements() {

}

void SpaceInvadersImpl::onKeyPressEvent(QKeyEvent *event) {
    this->joueur->onKeyPressedEvent(event);
}
