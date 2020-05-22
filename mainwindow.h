#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <SpaceInvaders_Metier/scenegagne.h>
#include <SpaceInvaders_Metier/scenemenu.h>
#include <SpaceInvaders_Metier/sceneperdu.h>
#include <SpaceInvaders_Metier/spaceinvadersimpl.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SpaceInvadersImpl *spaceInvadersImpl;
    QTimer* timer;
    SceneMenu* sceneMenu;
    SceneGagne* sceneGagne;
    ScenePerdu* scenePerdu;

};
#endif // MAINWINDOW_H
