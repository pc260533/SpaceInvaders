#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    this->setGraphicsView(this->ui->graphicsView);
    this->jouer();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::actionAExecuterJeuPerdu() {

}

void MainWindow::actionAExecuterJeuGagne() {

}

bool MainWindow::jeuEstGagne() {

}

bool MainWindow::jeuEstPerdu() {

}

void MainWindow::initialiserObjetsJeu() {
    //this->joueur = new Joueur(this, ":/ressources/images/images/joueur.png", 0, 266);
    this->joueur = new Joueur(this, ":/ressources/images/images/joueur.png", 370, 550);
    this->ajouterObjetSpaceInvaders(this->joueur);
    this->joueur->setFocus();

}

void MainWindow::initialiserArrierePlan() {
    this->getGraphicsSceneJeu()->setBackgroundBrush(QPixmap(":/ressources/images/images/backgroundSpaceInvaders.jpg"));
}

void MainWindow::initialiserEvenements() {

}
