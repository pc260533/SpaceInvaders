#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <SpaceInvaders_Scene/scenegagne.h>
#include <SpaceInvaders_Scene/scenemenu.h>
#include <SpaceInvaders_Scene/sceneperdu.h>
#include <SpaceInvaders_Scene/scenespaceinvaders.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    SceneSpaceInvaders *sceneSpaceInvaders;
    SceneMenu* sceneMenu;
    SceneGagne* sceneGagne;
    ScenePerdu* scenePerdu;

private:
    void lancerSpaceInvaders();
    void stopperSpaceInvaders();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onPartieGagne();
    void onPartiePerdu();
    void onQuitter();

};
#endif // MAINWINDOW_H
