#ifndef SCENEGAGNE_H
#define SCENEGAGNE_H

#include "scenefindejeu.h"

#include <QGraphicsScene>



class SceneGagne : public SceneFinDeJeu {

private:
    ObjetSpaceInvadersTexte* gagneTextItem;

public:
    SceneGagne();
    ~SceneGagne();

    // Scene interface
public:
    void initialiserObjetsJeu() override;
    void initialiserArrierePlan() override;
    QString getCheminMusiqueTheme() override;
};

#endif // SCENEGAGNE_H
