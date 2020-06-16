#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SpaceInvaders_Scene/scenegagne.h>
#include <SpaceInvaders_Scene/scenemenu.h>
#include <SpaceInvaders_Scene/sceneperdu.h>
#include <SpaceInvaders_Scene/scenespaceinvaders.h>

#include <QMainWindow>
#include <QTimer>

#include <QDebug>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief MainWindow est la classe représentant le fenêtre principale du space invaders.
 * Elle hérite de QMainWindow.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    /**
     * @brief ui : La variable permettant d'accéder aux composants de la fenêtre.
     */
    Ui::MainWindow *ui;
    /**
     * @brief timer : Le timer du space invaders qui fiat évolué le jeu tous les timeout.
     */
    QTimer* timer;
    /**
     * @brief sceneSpaceInvaders : Le scène de jeu du space invaders.
     */
    SceneSpaceInvaders *sceneSpaceInvaders;
    /**
     * @brief sceneMenu : La scène de menu.
     */
    SceneMenu* sceneMenu;
    /**
     * @brief sceneGagne : La scène gagné.
     */
    SceneGagne* sceneGagne;
    /**
     * @brief scenePerdu : La scène perdu.
     */
    ScenePerdu* scenePerdu;

private:
    /**
     * @brief lancerSpaceInvaders : Lancer une partie de space invaders.
     */
    void lancerSpaceInvaders();
    /**
     * @brief stopperSpaceInvaders : Stoppper une partie de space invaders.
     */
    void stopperSpaceInvaders();

public:
    /**
     * @brief MainWindow : Constructeur prenant en paramètre le QWidget parent.
     * @param parent : Le QWidget parent.
     */
    MainWindow(QWidget* parent = nullptr);
    /**
     * @brief ~MainWindow : Destructeur sans paramètres
     */
    ~MainWindow();

    // QWidget interface
protected:
    /**
     * @brief keyPressEvent : Slot correspondant au signal de récéption d'une touche du clavier pressée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier pressée.
     */
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    /**
     * @brief onPartieGagne : Slot correspondant au signal partieGagne de la sceneSpaceInvaders.
     */
    void onPartieGagne();
    /**
     * @brief onPartiePerdu : Slot correspondant au signal partiePerdu de la sceneSpaceInvaders.
     */
    void onPartiePerdu();
    /**
     * @brief onQuitter : Slot correspondant au signal quitter de la sceneSpaceInvaders.
     */
    void onQuitter();

};
#endif // MAINWINDOW_H
