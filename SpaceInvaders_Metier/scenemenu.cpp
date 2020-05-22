#include "scenemenu.h"

SceneMenu::SceneMenu(): Scene() {
    this->ennemi1TextItem= nullptr;
    this->ennemi2TextItem = nullptr;
    this->ennemi3TextItem = nullptr;
    this->ennemiMystereTextItem = nullptr;
    this->jouerTextItem = nullptr;
    this->quitterTextItem = nullptr;
    this->ennemi1PixmapItem = nullptr;
    this->ennemi2PixmapItem = nullptr;
    this->ennemi3PixmapItem = nullptr;
    this->ennemiMysterePixmapItem = nullptr;
    this->logoPixmapItem = nullptr;
}

SceneMenu::~SceneMenu() {
    this->supprimerObjetSpaceInvadersTexte(this->ennemi1TextItem);
    this->supprimerObjetSpaceInvadersTexte(this->ennemi2TextItem);
    this->supprimerObjetSpaceInvadersTexte(this->ennemi3TextItem);
    this->supprimerObjetSpaceInvadersTexte(this->ennemiMystereTextItem);
    this->supprimerObjetSpaceInvadersTexte(this->jouerTextItem);
    this->supprimerObjetSpaceInvadersTexte(this->quitterTextItem);
    this->supprimerObjetSpaceInvadersPixmap(this->ennemi1PixmapItem);
    this->supprimerObjetSpaceInvadersPixmap(this->ennemi2PixmapItem);
    this->supprimerObjetSpaceInvadersPixmap(this->ennemi3PixmapItem);
    this->supprimerObjetSpaceInvadersPixmap(this->ennemiMysterePixmapItem);
    this->supprimerObjetSpaceInvadersPixmap(this->logoPixmapItem);
    delete this->ennemi1TextItem;
    delete this->ennemi2TextItem;
    delete this->ennemi3TextItem;
    delete this->ennemiMystereTextItem;
    delete this->jouerTextItem;
    delete this->quitterTextItem;
    delete this->ennemi1PixmapItem;
    delete this->ennemi2PixmapItem;
    delete this->ennemi3PixmapItem;
    delete this->ennemiMysterePixmapItem;
    delete this->logoPixmapItem;
}

void SceneMenu::initialiserObjetsJeu() {
    QFont fontSpaceInvaders = this->getFontSpaceInvaders();
    fontSpaceInvaders.setPixelSize(35);
    this->jouerTextItem = new ObjetSpaceInvadersTexte(240, 265);
    this->jouerTextItem->setTexte("Press A to play");
    this->jouerTextItem->setCouleurTexte(Qt::white);
    this->jouerTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->jouerTextItem);

    this->quitterTextItem = new ObjetSpaceInvadersTexte(175, 315);
    this->quitterTextItem->setTexte("Press ESCAPE to quit");
    this->quitterTextItem->setCouleurTexte(Qt::white);
    this->quitterTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->quitterTextItem);

    fontSpaceInvaders.setPixelSize(20);

    this->ennemi1TextItem = new ObjetSpaceInvadersTexte(335, 395);
    this->ennemi1TextItem->setTexte("  =       10 points");
    this->ennemi1TextItem->setCouleurTexte(Qt::white);
    this->ennemi1TextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->ennemi1TextItem);

    this->ennemi2TextItem = new ObjetSpaceInvadersTexte(335, 450);
    this->ennemi2TextItem->setTexte("  =      20 points");
    this->ennemi2TextItem->setCouleurTexte(Qt::white);
    this->ennemi2TextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->ennemi2TextItem);

    this->ennemi3TextItem = new ObjetSpaceInvadersTexte(335, 500);
    this->ennemi3TextItem->setTexte("  =      30 points");
    this->ennemi3TextItem->setCouleurTexte(Qt::white);
    this->ennemi3TextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->ennemi3TextItem);

    this->ennemiMystereTextItem = new ObjetSpaceInvadersTexte(335, 545);
    this->ennemiMystereTextItem->setTexte("  =   ??? points");
    this->ennemiMystereTextItem->setCouleurTexte(Qt::white);
    this->ennemiMystereTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->ennemiMystereTextItem);

    this->ennemi1PixmapItem = new ObjetSpaceInvadersPixmap(":/ressources/images/images/ennemi1_0.png", 285, 390);
    this->ajouterObjetSpaceInvadersPixmap(this->ennemi1PixmapItem);

    this->ennemi2PixmapItem = new ObjetSpaceInvadersPixmap(":/ressources/images/images/ennemi2_0.png", 285, 440);
    this->ajouterObjetSpaceInvadersPixmap(this->ennemi2PixmapItem);

    this->ennemi3PixmapItem = new ObjetSpaceInvadersPixmap(":/ressources/images/images/ennemi3_0.png", 285, 490);
    this->ajouterObjetSpaceInvadersPixmap(this->ennemi3PixmapItem);

    this->ennemiMysterePixmapItem = new ObjetSpaceInvadersPixmap(":/ressources/images/images/ennemiMystere.png", 280, 540);
    this->ajouterObjetSpaceInvadersPixmap(this->ennemiMysterePixmapItem);

    this->logoPixmapItem = new ObjetSpaceInvadersPixmap(":/ressources/images/images/logoSpaceInvaders.png", 200, 60);
    this->ajouterObjetSpaceInvadersPixmap(this->logoPixmapItem);
}

void SceneMenu::initialiserArrierePlan() {
    this->setBackgroundBrush(QPixmap(":/ressources/images/images/backgroundSpaceInvaders.jpg"));
}

QString SceneMenu::getCheminMusiqueTheme() {
    return "qrc:/ressources/musiques/musiques/menuTheme.wav";
}
