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
}

MainWindow::~MainWindow() {
    delete ui;
}
