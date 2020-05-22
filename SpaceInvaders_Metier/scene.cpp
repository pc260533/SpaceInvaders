#include "scene.h"

Scene::Scene() : QGraphicsScene(0, 0, 800, 600) {
    this->titre = "Space Invaders";
    this->largeur = 800;
    this->hauteur = 600;
    this->getFontSpaceInvaders();
}

Scene::~Scene() {

}

int Scene::getHauteur() const {
    return hauteur;
}

int Scene::getLargeur() const {
    return largeur;
}

QFont Scene::getFontSpaceInvaders(){
    if (QFontDatabase::applicationFontFamilies(0).empty()) {
        QFontDatabase::addApplicationFont(":/ressources/font/fonts/fontSpaceInvaders.ttf");
    }
    QString family = QFontDatabase::applicationFontFamilies(0).at(0);
    return QFont(family);
}

void Scene::ajouterObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap) {
    this->addItem(objetSpaceInvadersPixmap);
}

void Scene::supprimerObjetSpaceInvadersPixmap(ObjetSpaceInvadersPixmap* objetSpaceInvadersPixmap) {
    this->removeItem(objetSpaceInvadersPixmap);
}

void Scene::ajouterObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe) {
    this->addItem(objetSpaceInvadersGroupe);
}

void Scene::supprimerObjetSpaceInvadersGroupe(ObjetSpaceInvadersGroupe* objetSpaceInvadersGroupe) {
    this->removeItem(objetSpaceInvadersGroupe);
}

void Scene::ajouterObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte *objetSpaceInvadersTexte) {
    this->addItem(objetSpaceInvadersTexte);
}

void Scene::supprimerObjetSpaceInvadersTexte(ObjetSpaceInvadersTexte *objetSpaceInvadersTexte) {
    this->removeItem(objetSpaceInvadersTexte);
}

void Scene::supprimerTousLesItems() {
    for (QGraphicsItem* item : this->items()) {
        this->removeItem(item);
        delete item;
    }
}

void Scene::initialiserScene() {
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
}

void Scene::reinitialiserScene(){
    this->clear();
}
