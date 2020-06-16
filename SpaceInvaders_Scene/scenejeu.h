#ifndef SCENEJEU_H
#define SCENEJEU_H

#include <SpaceInvaders_Metier/scene.h>

#include <QList>
#include <QGraphicsView>



/**
 * @brief SceneJeu est la classe abstraite représentant une scène de jeu.
 * Elle hérite de Scene.
 */
class SceneJeu : public Scene {
    Q_OBJECT

private:
    /**
     * @brief graphicsView : La graphicsView de jeu lié à la scène de jeu héritant de QGraphicsScene.
     */
    QGraphicsView* graphicsView;
    /**
     * @brief listeObjetsSpaceInvadersASupprimer : La liste des ObjetSpaceInvadersPixmapEvoluable à libérer de la mémoire à chaque fin d'évolution.
     */
    QList<ObjetSpaceInvadersPixmapEvoluable*> listeObjetsSpaceInvadersASupprimer;

public:
    /**
     * @brief SceneJeu : Constructeur sans paramètres.
     */
    SceneJeu();
    /**
     * @brief ~SceneJeu : Destructeur sans paramètres.
     */
    virtual ~SceneJeu();

    /**
     * @brief getGraphicsView : Retourner la graphicsView de jeu lié à la scène de jeu.
     * @return : La graphicsView de jeu lié à la scène de jeu.
     */
    QGraphicsView* getGraphicsView() const;
    /**
     * @brief setGraphicsView : Modifier la graphicsView de jeu lié à la scène de jeu
     * @param graphicsView : la nouvelle graphicsView de jeu lié à la scène de jeu
     */
    void setGraphicsView(QGraphicsView* graphicsView);

    /**
     * @brief actionAExecuterJeuPerdu : Action à exécuter quand le jeu est perdu.
     */
    virtual void actionAExecuterJeuPerdu() = 0;
    /**
     * @brief actionAExecuterJeuGagne : Action à exécuter quand le jeu est gagné.
     */
    virtual void actionAExecuterJeuGagne() = 0;
    /**
     * @brief jeuEstGagne : Retourner un booléen indiquant si le jeu est gagné.
     * @return Le booléen indiquant si le jeu est gagné.
     */
    virtual bool jeuEstGagne() = 0;
    /**
     * @brief jeuEstPerdu : Retourner un booléen indiquant si le jeu est perdu.
     * @return Le booléen indiquant si le jeu est perdu.
     */
    virtual bool jeuEstPerdu() = 0;
    /**
     * @brief onKeyPressEvent : Action à réaliser après la détection d'une touche du clavier pressée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier pressée.
     */
    virtual void onKeyPressEvent(QKeyEvent* event) = 0;
    /**
     * @brief onKeyReleaseEvent : Action à réaliser après la détection d'une touche du clavier relachée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier relachée.
     */
    virtual void onKeyReleaseEvent(QKeyEvent* event) = 0;

protected slots:
    /**
     * @brief ajouterObjetsSpaceInvadersPixmapAuJeu : Slot correpsondant au signal nouveauObjetSpaceInvadersPixmapDansJeu.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable à ajouter.
     */
    void ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap);
    /**
     * @brief supprimerObjetsSpaceInvadersPixmapDuJeu : Slot correpsondant au signal suppressionObjetSpaceInvadersPixmapDansJeu.
     * @param objetSpaceInvadersPixmap : L'objetSpaceInvadersPixmapEvoluable à supprimer.
     */
    virtual void supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable* objetSpaceInvadersPixmap);

public slots:
    /**
     * @brief evoluer : Slot correspondant au signal timeout du QTimer de la MainWindows.
     */
    virtual void evoluer();

    // QGraphicsScene interface
protected:
    /**
     * @brief keyPressEvent : Slot correspondant au signal de récéption d'une touche du clavier pressée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier pressée.
     */
    void keyPressEvent(QKeyEvent* event) override;
    /**
     * @brief keyReleaseEvent : Slot correspondant au signal de récéption d'une touche du clavier relachée.
     * @param event : L'événement correpsondant à la détection d'une touche du clavier relachée.
     */
    void keyReleaseEvent(QKeyEvent* event) override;

};

#endif // SCENEJEU_H
