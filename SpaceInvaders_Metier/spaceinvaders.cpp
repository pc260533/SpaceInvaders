#include "spaceinvaders.h"

void SpaceInvaders::setGraphicsView(QGraphicsView *value) {
    this->graphicsView = value;
    //this->graphicsView->setScene(this->graphicsSceneJeu);
    this->graphicsView->setScene(this);
}


/*QGraphicsScene *SpaceInvaders::getGraphicsSceneJeu() const {
    return graphicsSceneJeu;
}

void SpaceInvaders::setGraphicsSceneJeu(QGraphicsScene *value) {
    graphicsSceneJeu = value;
}*/

int SpaceInvaders::getHauteur() const {
    return hauteur;
}

int SpaceInvaders::getLargeur() const {
    return largeur;
}

SpaceInvaders::SpaceInvaders() : QGraphicsScene(0, 0, 800, 600) {
    this->largeur = 800;
    this->hauteur = 600;
    //this->graphicsSceneJeu = new QGraphicsScene(0, 0, this->largeur, this->hauteur);
}

SpaceInvaders::~SpaceInvaders() {

}

void SpaceInvaders::ajouterObjetSpaceInvaders(ObjetSpaceInvaders* objetSpaceInvaders) {
    //this->graphicsSceneJeu->addItem(objetSpaceInvaders);
    this->addItem(objetSpaceInvaders);
}

void SpaceInvaders::supprimerObjetSpaceInvaders(ObjetSpaceInvaders* objetSpaceInvaders) {
    //this->graphicsSceneJeu->removeItem(objetSpaceInvaders);
    this->removeItem(objetSpaceInvaders);
}

void SpaceInvaders::jouer() {
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
    this->initialiserEvenements();
}

void SpaceInvaders::ajouterObjetsSpaceInvadersAuJeu(ObjetSpaceInvaders *objetSpaceInvaders) {
    qDebug() << "objet attrapé et ajouté";
    this->ajouterObjetSpaceInvaders(objetSpaceInvaders);
    //connect le signal de suppression ici en fait
    QObject::connect(dynamic_cast<QObject*>(objetSpaceInvaders), SIGNAL(suppressionObjetSpaceInvadersDansJeu(ObjetSpaceInvaders*)), this, SLOT(supprimerObjetsSpaceInvadersDuJeu(ObjetSpaceInvaders*)));
}

void SpaceInvaders::supprimerObjetsSpaceInvadersDuJeu(ObjetSpaceInvaders *objetSpaceInvaders) {
    qDebug() << "objet attrapé et supprimé";
    this->supprimerObjetSpaceInvaders(objetSpaceInvaders);
}


void SpaceInvaders::keyPressEvent(QKeyEvent *event) {
    this->onKeyPressEvent(event);
}
