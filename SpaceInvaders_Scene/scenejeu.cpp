#include "scenejeu.h"

SceneJeu::SceneJeu() : Scene() {
    this->listeObjetsSpaceInvadersASupprimer = QList<ObjetSpaceInvadersPixmapEvoluable*>();
}

SceneJeu::~SceneJeu() {

}

QGraphicsView* SceneJeu::getGraphicsView() const {
    return this->graphicsView;
}

void SceneJeu::setGraphicsView(QGraphicsView* graphicsView) {
    this->graphicsView = graphicsView;
    this->graphicsView->setScene(this);
}

void SceneJeu::ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap) {
    this->ajouterObjetSpaceInvadersPixmap(objetSpaceInvadersPixmap);
    QObject::connect(dynamic_cast<QObject*>(objetSpaceInvadersPixmap), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
}

void SceneJeu::supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap) {
    if (!this->items().contains(objetSpaceInvadersPixmap)) {
        this->supprimerObjetSpaceInvadersPixmap(objetSpaceInvadersPixmap);
    }
    if (!this->listeObjetsSpaceInvadersASupprimer.contains(objetSpaceInvadersPixmap)) {
        this->listeObjetsSpaceInvadersASupprimer.push_back(objetSpaceInvadersPixmap);
    }
}

void SceneJeu::evoluer() {
    this->advance();
    for (ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmapEvoluable : this->listeObjetsSpaceInvadersASupprimer) {
        if (objetSpaceInvadersPixmapEvoluable != nullptr) {
            delete objetSpaceInvadersPixmapEvoluable;
            objetSpaceInvadersPixmapEvoluable = nullptr;
        }
    }
    this->listeObjetsSpaceInvadersASupprimer.clear();
}

void SceneJeu::keyPressEvent(QKeyEvent* event) {
    this->onKeyPressEvent(event);
}

void SceneJeu::keyReleaseEvent(QKeyEvent* event) {
    this->onKeyReleaseEvent(event);
}
