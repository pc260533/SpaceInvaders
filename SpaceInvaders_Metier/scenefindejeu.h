#ifndef SCENEFINDEJEU_H
#define SCENEFINDEJEU_H

#include "scene.h"

#include <QFontDatabase>
#include <QGraphicsScene>

class SceneFinDeJeu : public Scene {

private:
    ObjetSpaceInvadersTexte* rejouerTextItem;

public:
    SceneFinDeJeu();
    ~SceneFinDeJeu();

    // Scene interface
public:
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;

};

#endif // SCENEFINDEJEU_H
