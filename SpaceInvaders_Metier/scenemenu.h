#ifndef SCENEMENU_H
#define SCENEMENU_H

#include "scene.h"

#include <QGraphicsScene>



class SceneMenu : public Scene {

private:
    ObjetSpaceInvadersTexte* ennemi1TextItem;
    ObjetSpaceInvadersTexte* ennemi2TextItem;
    ObjetSpaceInvadersTexte* ennemi3TextItem;
    ObjetSpaceInvadersTexte* ennemiMystereTextItem;
    ObjetSpaceInvadersTexte* jouerTextItem;
    ObjetSpaceInvadersTexte* quitterTextItem;
    ObjetSpaceInvadersPixmap* ennemi1PixmapItem;
    ObjetSpaceInvadersPixmap* ennemi2PixmapItem;
    ObjetSpaceInvadersPixmap* ennemi3PixmapItem;
    ObjetSpaceInvadersPixmap* ennemiMysterePixmapItem;
    ObjetSpaceInvadersPixmap* logoPixmapItem;

public:
    SceneMenu();
    ~SceneMenu();

    // Scene interface
public:
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;

};

#endif // SCENEMENU_H
