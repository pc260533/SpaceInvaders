#include "spaceinvaders.h"

SpaceInvaders::SpaceInvaders() : Scene() {
    this->listeObjetsSpaceInvadersASupprimer = QList<ObjetSpaceInvadersPixmapEvoluable*>();
}

SpaceInvaders::~SpaceInvaders() {

}

QGraphicsView* SpaceInvaders::getGraphicsView() const {
    return this->graphicsView;
}

void SpaceInvaders::setGraphicsView(QGraphicsView* graphicsView) {
    this->graphicsView = graphicsView;
    this->graphicsView->setScene(this);
}

void SpaceInvaders::jouer() {
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
    this->initialiserEvenements();
}

void SpaceInvaders::ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) {
    //qDebug() << "objet attrapé et ajouté";
    this->ajouterObjetSpaceInvadersPixmap(objetSpaceInvadersPixmap);
    QObject::connect(dynamic_cast<QObject*>(objetSpaceInvadersPixmap), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
}

void SpaceInvaders::supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) {
    //qDebug() << "objet attrapé et supprimé";
    this->supprimerObjetSpaceInvadersPixmap(objetSpaceInvadersPixmap);
    this->listeObjetsSpaceInvadersASupprimer.push_back(objetSpaceInvadersPixmap);
}

void SpaceInvaders::evoluer() {
    this->advance();
    for (ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmapEvoluable : this->listeObjetsSpaceInvadersASupprimer) {
        if (objetSpaceInvadersPixmapEvoluable) {
            delete objetSpaceInvadersPixmapEvoluable;
        }
        this->listeObjetsSpaceInvadersASupprimer.clear();
    }
}

void SpaceInvaders::keyPressEvent(QKeyEvent *event) {
    this->onKeyPressEvent(event);
}

void SpaceInvaders::keyReleaseEvent(QKeyEvent *event) {
    this->onKeyReleaseEvent(event);
}
