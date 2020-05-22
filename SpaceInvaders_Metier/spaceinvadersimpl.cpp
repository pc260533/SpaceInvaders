#include "spaceinvadersimpl.h"

SpaceInvadersImpl::SpaceInvadersImpl() : SpaceInvaders() {
    this->joueur = nullptr;
    this->vagueEnnemis = nullptr;
    this->ennemiMystere = nullptr;
    this->mur1 = nullptr;
    this->mur2 = nullptr;
    this->mur3 = nullptr;
    this->mur4 = nullptr;
    this->score = 0;
    this->highscore = 0;
    this->round = 0;
    this->highestRound = 0;
    this->scoreTextItem = nullptr;
    this->highscoreTextItem = nullptr;
    this->roundTextItem = nullptr;
    this->highestRoundTextItem = nullptr;
    this->nombreViesJoueurTextItem = nullptr;
}

void SpaceInvadersImpl::miseAJourTexteNombreDeViesJoueur() {
    this->nombreViesJoueurTextItem->setTexte("Lives : " + QString::number(this->joueur->getNombreViesJoueur()));
}

void SpaceInvadersImpl::miseAJourTexteScoreHighscore() {
    if (this->score > this->highscore) {
        this->highscore = this->score;
    }
    this->scoreTextItem->setTexte("Score : " + QString::number(this->score));
    this->highscoreTextItem->setTexte("Highscore : " + QString::number(this->highscore));
}

void SpaceInvadersImpl::miseAJourTexteRoundHighestRound() {
    this->roundTextItem->setTexte("Round : " + QString::number(this->round));
    this->highestRoundTextItem->setTexte("Highest Round : " + QString::number(this->highestRound));
}


void SpaceInvadersImpl::actionAExecuterJeuPerdu() {

}

void SpaceInvadersImpl::actionAExecuterJeuGagne() {

}

bool SpaceInvadersImpl::jeuEstGagne() {

}

bool SpaceInvadersImpl::jeuEstPerdu() {

}

void SpaceInvadersImpl::initialiserObjetsJeu() {
    this->joueur = new Joueur(370, 550);
    QObject::connect(dynamic_cast<QObject*>(this->joueur), SIGNAL(nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmap*)));
    QObject::connect(dynamic_cast<QObject*>(this->joueur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
    QObject::connect(this->joueur, SIGNAL(nombreViesJoueurDiminue()), this, SLOT(onNombreViesJoueurDiminue()));
    this->ajouterObjetSpaceInvadersPixmap(this->joueur);

    this->vagueEnnemis = new VagueEnnemis(50, 50);
    for (Ennemi* ennemi : this->vagueEnnemis->getListeEnnemis()) {
        QObject::connect(dynamic_cast<QObject*>(ennemi), SIGNAL(nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmap*)));
        QObject::connect(dynamic_cast<QObject*>(ennemi), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
    }
    this->ajouterObjetSpaceInvadersGroupe(this->vagueEnnemis);

    this->ennemiMystere = new EnnemiMystere(-2000, 25);
    QObject::connect(dynamic_cast<QObject*>(this->ennemiMystere), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
    this->ajouterObjetSpaceInvadersPixmap(this->ennemiMystere);

    this->mur1 = new Mur(125, 450);
    for (PartieDeMur* partieDeMur : this->mur1->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
    }
    this->mur2 = new Mur(271, 450);
    for (PartieDeMur* partieDeMur : this->mur2->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
    }
    this->mur3 = new Mur(417, 450);
    for (PartieDeMur* partieDeMur : this->mur3->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
    }
    this->mur4 = new Mur(563, 450);
    for (PartieDeMur* partieDeMur : this->mur4->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmap*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap*)));
    }
    this->ajouterObjetSpaceInvadersGroupe(this->mur1);
    this->ajouterObjetSpaceInvadersGroupe(this->mur2);
    this->ajouterObjetSpaceInvadersGroupe(this->mur3);
    this->ajouterObjetSpaceInvadersGroupe(this->mur4);

    int id = QFontDatabase::addApplicationFont(":/ressources/font/fonts/fontSpaceInvaders.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontSpaceInvaders = QFont(family);
    fontSpaceInvaders.setPixelSize(15);

    this->nombreViesJoueurTextItem = new ObjetSpaceInvadersTexte(20, 5);
    this->nombreViesJoueurTextItem->setCouleurTexte(Qt::white);
    this->nombreViesJoueurTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->nombreViesJoueurTextItem);

    this->scoreTextItem = new ObjetSpaceInvadersTexte(400, 5);
    this->scoreTextItem->setCouleurTexte(Qt::white);
    this->scoreTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->scoreTextItem);

    this->highscoreTextItem = new ObjetSpaceInvadersTexte(630, 5);
    this->highscoreTextItem->setCouleurTexte(Qt::white);
    this->highscoreTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->highscoreTextItem);

    this->roundTextItem = new ObjetSpaceInvadersTexte(20, 583);
    this->roundTextItem->setCouleurTexte(Qt::white);
    this->roundTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->roundTextItem);

    this->highestRoundTextItem = new ObjetSpaceInvadersTexte(630, 583);
    this->highestRoundTextItem->setCouleurTexte(Qt::white);
    this->highestRoundTextItem->setFont(fontSpaceInvaders);
    this->ajouterObjetSpaceInvadersTexte(this->highestRoundTextItem);

    this->miseAJourTexteNombreDeViesJoueur();
    this->miseAJourTexteScoreHighscore();
    this->miseAJourTexteRoundHighestRound();

    this->setFocus();
}

void SpaceInvadersImpl::initialiserArrierePlan() {
    //this->setBackgroundBrush(QPixmap(":/ressources/images/images/backgroundSpaceInvaders.jpg"));
    this->setBackgroundBrush(Qt::black);
}

void SpaceInvadersImpl::initialiserEvenements() {

}

void SpaceInvadersImpl::onKeyPressEvent(QKeyEvent *event) {
    this->joueur->onKeyPressedEvent(event);
}

void SpaceInvadersImpl::onNombreViesJoueurDiminue() {
    this->miseAJourTexteNombreDeViesJoueur();
}

void SpaceInvadersImpl::supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmap *objetSpaceInvadersPixmap) {
    //ne pas supprimer deux fois le même objet
    //vérifier que l'objet est dan la scène
    QString objetType = objetSpaceInvadersPixmap->getTypeObjet();
    if ((objetType == "Ennemi1") || (objetType == "Ennemi2") || (objetType == "Ennemi3")) {
        Ennemi* ennemi = dynamic_cast<Ennemi*>(objetSpaceInvadersPixmap);
        this->vagueEnnemis->supprimerEnnemi(ennemi);
        this->score += ennemi->getScoreEnnemi();
        this->miseAJourTexteScoreHighscore();
    }
    else if (objetType == "EnnemiMystere") {
        EnnemiMystere* ennemiMystere = dynamic_cast<EnnemiMystere*>(objetSpaceInvadersPixmap);
        this->score += ennemiMystere->getScoreEnnemi();
        this->miseAJourTexteScoreHighscore();
    }
    else if (objetType == "PartieDeMur") {
        PartieDeMur* partieDeMur = dynamic_cast<PartieDeMur*>(objetSpaceInvadersPixmap);
        this->mur1->supprimerPartieDeMur(partieDeMur);
        this->mur2->supprimerPartieDeMur(partieDeMur);
        this->mur3->supprimerPartieDeMur(partieDeMur);
        this->mur4->supprimerPartieDeMur(partieDeMur);
    }
    //qDebug() << this->score;
    SpaceInvaders::supprimerObjetsSpaceInvadersPixmapDuJeu(objetSpaceInvadersPixmap);
}
