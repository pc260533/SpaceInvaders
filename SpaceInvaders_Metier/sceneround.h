#ifndef SCENEROUND_H
#define SCENEROUND_H

#include "scene.h"

#include <QGraphicsScene>



class SceneRound : public Scene {

private:
    ObjetSpaceInvadersTexte* nextRoundTextItem;

public:
    SceneRound();
    ~SceneRound();

    // Scene interface
public:
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;

};

#endif // SCENEROUND_H
