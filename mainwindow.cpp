#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setFrameStyle(0);

    this->sceneSpaceInvaders = nullptr;

    this->sceneMenu = new SceneMenu();
    this->sceneGagne = new SceneGagne();
    this->scenePerdu = new ScenePerdu();
    this->sceneMenu->initialiserScene();
    this->sceneGagne->initialiserScene();
    this->scenePerdu->initialiserScene();

    this->timer = new QTimer(this);

    this->ui->graphicsView->setScene(this->sceneMenu);
    this->sceneMenu->lancerMusiqueTheme();
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

void MainWindow::lancerSpaceInvaders() {
    this->sceneSpaceInvaders = new SceneSpaceInvaders();
    this->sceneSpaceInvaders->setGraphicsView(this->ui->graphicsView);
    this->sceneSpaceInvaders->initialiserScene();
    this->sceneSpaceInvaders->lancerMusiqueTheme();

    QObject::connect(this->sceneSpaceInvaders, SIGNAL (partieGagne()), this, SLOT(onPartieGagne()));
    QObject::connect(this->sceneSpaceInvaders, SIGNAL (partiePerdu()), this, SLOT(onPartiePerdu()));
    QObject::connect(this->sceneSpaceInvaders, SIGNAL (quitter()), this, SLOT(onQuitter()));

    QObject::connect(this->timer, SIGNAL (timeout()), this->sceneSpaceInvaders, SLOT(evoluer()));
    this->timer->start(10);
}

void MainWindow::stopperSpaceInvaders() {
    if (this->sceneSpaceInvaders) {
        this->timer->stop();
        this->sceneSpaceInvaders->stopperMusiqueTheme();
        delete this->sceneSpaceInvaders;
        this->sceneSpaceInvaders = nullptr;
    }
}

void MainWindow::onPartieGagne() {
    this->stopperSpaceInvaders();
    this->sceneGagne->lancerMusiqueTheme();
    this->ui->graphicsView->setScene(this->sceneGagne);
}

void MainWindow::onPartiePerdu() {
    this->stopperSpaceInvaders();
    this->scenePerdu->lancerMusiqueTheme();
    this->ui->graphicsView->setScene(this->scenePerdu);
}

void MainWindow::onQuitter() {
    this->stopperSpaceInvaders();
    this->close();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    //qDebug() << event;
    if (event->key() == Qt::Key_A) {
        if (!this->sceneSpaceInvaders) {
            this->sceneMenu->stopperMusiqueTheme();
            this->sceneGagne->stopperMusiqueTheme();
            this->scenePerdu->stopperMusiqueTheme();
            this->lancerSpaceInvaders();
        }
    }
    else if (event->key() == Qt::Key_Escape) {
        this->close();
    }
}
