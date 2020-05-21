#include "spaceinvaders.h"

void SpaceInvaders::setGraphicsView(QGraphicsView *value) {
    this->graphicsView = value;
    this->graphicsView->setScene(this->graphicsSceneJeu);
}


QGraphicsScene *SpaceInvaders::getGraphicsSceneJeu() const {
    return graphicsSceneJeu;
}

void SpaceInvaders::setGraphicsSceneJeu(QGraphicsScene *value) {
    graphicsSceneJeu = value;
}

int SpaceInvaders::getHauteur() const {
    return hauteur;
}

int SpaceInvaders::getLargeur() const {
    return largeur;
}

SpaceInvaders::SpaceInvaders(): QObject(nullptr) {
    this->largeur = 800;
    this->hauteur = 600;
    this->graphicsSceneJeu = new QGraphicsScene(0, 0, this->largeur, this->hauteur);
}

SpaceInvaders::~SpaceInvaders() {

}

void SpaceInvaders::ajouterObjetSpaceInvaders(ObjetSpaceInvaders* objetSpaceInvaders) {
    this->graphicsSceneJeu->addItem(objetSpaceInvaders);
}

void SpaceInvaders::supprimerObjetSpaceInvaders(ObjetSpaceInvaders* objetSpaceInvaders) {
    this->graphicsSceneJeu->removeItem(objetSpaceInvaders);
}

void SpaceInvaders::jouer() {
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
    this->initialiserEvenements();
}

void SpaceInvaders::ajouterObjetsSpaceInvadersAuJeu(ObjetSpaceInvaders *objetSpaceInvaders) {
    qDebug() << "objet attrapé et ajouté";
    this->ajouterObjetSpaceInvaders(objetSpaceInvaders);
}
