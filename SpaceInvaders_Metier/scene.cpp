#include "scene.h"

Scene::Scene() : QGraphicsScene(0, 0, 800, 600) {
    this->titre = "Space Invaders";
    this->largeur = 800;
    this->hauteur = 600;
}

Scene::~Scene() {

}

int Scene::getHauteur() const {
    return hauteur;
}

int Scene::getLargeur() const {
    return largeur;
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

void Scene::initialiserScene() {
    this->initialiserArrierePlan();
    this->initialiserObjetsJeu();
}

void Scene::reinitialiserScene(){
    this->clear();
}
