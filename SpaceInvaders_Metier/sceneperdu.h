#ifndef SCENEPERDU_H
#define SCENEPERDU_H

#include "scenefindejeu.h"

#include <QFontDatabase>
#include <QGraphicsScene>

class ScenePerdu : public SceneFinDeJeu {

private:
    ObjetSpaceInvadersTexte* rejouerTextItem;
    ObjetSpaceInvadersTexte* perduTextItem;

public:
    ScenePerdu();
    ~ScenePerdu();

    // Scene interface
public:
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;

};

#endif // SCENEPERDU_H
