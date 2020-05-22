#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setFrameStyle(0);


    this->spaceInvadersImpl = new SpaceInvadersImpl();
    this->spaceInvadersImpl->setGraphicsView(this->ui->graphicsView);
    this->spaceInvadersImpl->jouer();


    this->timer = new QTimer(this);
    QObject::connect(this->timer, SIGNAL (timeout()), this->spaceInvadersImpl, SLOT(evoluer()));
    this->timer->start(10);
}

MainWindow::~MainWindow() {
    delete this->spaceInvadersImpl;
    delete this->timer;
    delete this->ui;
}
