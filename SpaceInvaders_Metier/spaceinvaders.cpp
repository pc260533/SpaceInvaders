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

int SpaceInvaders::getLongueur() const
{
    return longueur;
}

int SpaceInvaders::getLargeur() const
{
    return largeur;
}

SpaceInvaders::SpaceInvaders() {
    this->graphicsSceneJeu = new QGraphicsScene();
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
