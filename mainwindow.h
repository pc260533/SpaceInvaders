#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <SpaceInvaders_Metier/scenegagne.h>
#include <SpaceInvaders_Metier/scenemenu.h>
#include <SpaceInvaders_Metier/sceneperdu.h>
#include <SpaceInvaders_Metier/scenespaceinvaders.h>



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
    QTimer* timer;
    SceneSpaceInvaders *sceneSpaceInvaders;
    SceneMenu* sceneMenu;
    SceneGagne* sceneGagne;
    ScenePerdu* scenePerdu;

private slots:
    void onPartieGagne();
    void onPartiePerdu();

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // MAINWINDOW_H
