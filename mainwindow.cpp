#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    this->spaceInvadersImpl = new SpaceInvadersImpl();
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setFrameStyle(0);
    this->spaceInvadersImpl->setGraphicsView(this->ui->graphicsView);
    this->spaceInvadersImpl->jouer();
    this->timer = new QTimer(this);
    QObject::connect(this->timer, SIGNAL (timeout()), this->spaceInvadersImpl, SLOT(advance()));
    this->timer->start(10);
}

MainWindow::~MainWindow() {
    delete ui;
}
