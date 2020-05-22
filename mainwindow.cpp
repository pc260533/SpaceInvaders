#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setFrameStyle(0);

    this->sceneMenu = new SceneMenu();
    this->sceneGagne = new SceneGagne();
    this->scenePerdu = new ScenePerdu();
    this->sceneMenu->initialiserScene();
    this->sceneGagne->initialiserScene();
    this->scenePerdu->initialiserScene();

    this->sceneSpaceInvaders = new SceneSpaceInvaders();
    this->sceneSpaceInvaders->setGraphicsView(this->ui->graphicsView);
    this->sceneSpaceInvaders->initialiserScene();

    QObject::connect(this->sceneSpaceInvaders, SIGNAL (partieGagne()), this, SLOT(onPartieGagne()));
    QObject::connect(this->sceneSpaceInvaders, SIGNAL (partiePerdu()), this, SLOT(onPartiePerdu()));


    this->timer = new QTimer(this);
    QObject::connect(this->timer, SIGNAL (timeout()), this->sceneSpaceInvaders, SLOT(evoluer()));
    this->timer->start(10);
}

MainWindow::~MainWindow() {
    delete this->sceneMenu;
    delete this->sceneGagne;
    delete this->scenePerdu;
    if (this->sceneSpaceInvaders) {
        delete this->sceneSpaceInvaders;
    }
    delete this->timer;
    delete this->ui;
}

void MainWindow::onPartieGagne() {
    qDebug() << "gagne";
    this->timer->stop();
    delete this->sceneSpaceInvaders;
    this->sceneSpaceInvaders = nullptr;
    this->ui->graphicsView->setScene(this->sceneGagne);
}

void MainWindow::onPartiePerdu() {
    this->timer->stop();
    delete this->sceneSpaceInvaders;
    this->sceneSpaceInvaders = nullptr;
    this->ui->graphicsView->setScene(this->scenePerdu);
}


void MainWindow::keyPressEvent(QKeyEvent *event) {
    // au pire il faut jsute unset le focus
    //d'ailleur c'est le cas par défaut donc c'est bon
    // oui il y a rien a envoyer a la scene de jeu ez
    // et donc pas de keyRelease ahhhh
    qDebug() << event;
    if (event->key() == Qt::Key_A) {
        if (!this->sceneSpaceInvaders) {

        }
    }
    else if (event->key() == Qt::Key_Escape) {
        this->close();
    }
}
