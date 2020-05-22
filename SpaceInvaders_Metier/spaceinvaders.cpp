#include "spaceinvaders.h"

void SpaceInvaders::setGraphicsView(QGraphicsView *value) {
    this->graphicsView = value;
    this->graphicsView->setScene(this);
}

int SpaceInvaders::getHauteur() const {
    return hauteur;
}

int SpaceInvaders::getLargeur() const {
    return largeur;
}

SpaceInvaders::SpaceInvaders() : QGraphicsScene(0, 0, 800, 600) {
    this->largeur = 800;
    this->hauteur = 600;
}

SpaceInvaders::~SpaceInvaders() {

}

void SpaceInvaders::ajouterObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap) {
    this->addItem(objetSpaceInvadersPixmap);
}

void SpaceInvaders::supprimerObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap) {
    this->removeItem(objetSpaceInvadersPixmap);
}

void SpaceInvaders::ajouterObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe) {
    this->addItem(objetSpaceInvadersGroupe);
}

void SpaceInvaders::supprimerObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe) {
    this->removeItem(objetSpaceInvadersGroupe);
}

void SpaceInvaders::jouer() {
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
    this->initialiserEvenements();
}

void SpaceInvaders::ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {
    qDebug() << "objet attrapé et ajouté";
    this->ajouterObjetSpaceInvadersPixmap(objetSpaceInvadersPixmap);
    QObject::connect(dynamic_cast<QObject*>(objetSpaceInvadersPixmap), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
}

void SpaceInvaders::supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {
    qDebug() << "objet attrapé et supprimé";
    this->supprimerObjetSpaceInvadersPixmap(objetSpaceInvadersPixmap);
}

void SpaceInvaders::keyPressEvent(QKeyEvent *event) {
    this->onKeyPressEvent(event);
}
