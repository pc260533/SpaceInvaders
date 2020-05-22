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
    this->round = 1;
    this->highestRound = 1;
    this->scoreTextItem = nullptr;
    this->highscoreTextItem = nullptr;
    this->roundTextItem = nullptr;
    this->highestRoundTextItem = nullptr;
    this->nombreViesJoueurTextItem = nullptr;
    this->sceneRound = new SceneRound();
    this->sceneRound->initialiserScene();
}

SpaceInvadersImpl::~SpaceInvadersImpl() {
    delete this->joueur;
    delete this->vagueEnnemis;
    if (this->ennemiMystere) {
        delete this->ennemiMystere;
    }
    delete this->mur1;
    delete this->mur2;
    delete this->mur3;
    delete this->mur4;
    delete this->scoreTextItem;
    delete this->highscoreTextItem;
    delete this->roundTextItem;
    delete this->highestRoundTextItem;
    delete this->sceneRound;
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

void SpaceInvadersImpl::chargerNouveauRound() {
    this->round++;
    this->vagueEnnemis->reinitialiserChanceDeTirEnnemi();
    this->reinitialiserScene();
    this->initialiserScene();
}


void SpaceInvadersImpl::actionAExecuterJeuPerdu() {
    emit this->partiePerdu();
}

void SpaceInvadersImpl::actionAExecuterJeuGagne() {
    emit this->partieGagne();
}

bool SpaceInvadersImpl::jeuEstGagne() {
    return (this->round == 3);
}

bool SpaceInvadersImpl::jeuEstPerdu() {
    return (this->joueur->getNombreViesJoueur() >= 0);
}

void SpaceInvadersImpl::initialiserObjetsJeu() {
    this->joueur = new Joueur(370, 550);
    QObject::connect(dynamic_cast<QObject*>(this->joueur), SIGNAL(nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    QObject::connect(dynamic_cast<QObject*>(this->joueur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    QObject::connect(this->joueur, SIGNAL(nombreViesJoueurDiminue()), this, SLOT(onNombreViesJoueurDiminue()));
    this->ajouterObjetSpaceInvadersPixmap(this->joueur);

    this->vagueEnnemis = new VagueEnnemis(50, 50);
    for (Ennemi* ennemi : this->vagueEnnemis->getListeEnnemis()) {
        QObject::connect(dynamic_cast<QObject*>(ennemi), SIGNAL(nouveauObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(ajouterObjetsSpaceInvadersPixmapAuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
        QObject::connect(dynamic_cast<QObject*>(ennemi), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    }
    this->ajouterObjetSpaceInvadersGroupe(this->vagueEnnemis);

    this->ennemiMystere = new EnnemiMystere(-2000, 25);
    QObject::connect(dynamic_cast<QObject*>(this->ennemiMystere), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    this->ajouterObjetSpaceInvadersPixmap(this->ennemiMystere);

    this->mur1 = new Mur(125, 450);
    for (PartieDeMur* partieDeMur : this->mur1->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    }
    this->mur2 = new Mur(271, 450);
    for (PartieDeMur* partieDeMur : this->mur2->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    }
    this->mur3 = new Mur(417, 450);
    for (PartieDeMur* partieDeMur : this->mur3->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    }
    this->mur4 = new Mur(563, 450);
    for (PartieDeMur* partieDeMur : this->mur4->getListePartieDeMur()) {
        QObject::connect(dynamic_cast<QObject*>(partieDeMur), SIGNAL(suppressionObjetSpaceInvadersPixmapDansJeu(ObjetSpaceInvadersPixmapEvoluable*)), this, SLOT(supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable*)));
    }
    this->ajouterObjetSpaceInvadersGroupe(this->mur1);
    this->ajouterObjetSpaceInvadersGroupe(this->mur2);
    this->ajouterObjetSpaceInvadersGroupe(this->mur3);
    this->ajouterObjetSpaceInvadersGroupe(this->mur4);

    QFont fontSpaceInvaders = this->getFontSpaceInvaders();
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
    this->setBackgroundBrush(Qt::black);
}

void SpaceInvadersImpl::reinitialiserScene() {
    SpaceInvaders::reinitialiserScene();
    delete this->joueur;
    delete this->vagueEnnemis;
    if (this->ennemiMystere) {
        delete this->ennemiMystere;
    }
    delete this->mur1;
    delete this->mur2;
    delete this->mur3;
    delete this->mur4;
    delete this->scoreTextItem;
    delete this->highscoreTextItem;
    delete this->roundTextItem;
    delete this->highestRoundTextItem;
    this->joueur = nullptr;
    this->vagueEnnemis = nullptr;
    this->ennemiMystere = nullptr;
    this->mur1 = nullptr;
    this->mur2 = nullptr;
    this->mur4 = nullptr;
    this->scoreTextItem = nullptr;
    this->highscoreTextItem = nullptr;
    this->roundTextItem = nullptr;
    this->highestRoundTextItem = nullptr;
}

void SpaceInvadersImpl::onKeyPressEvent(QKeyEvent *event) {
    this->joueur->onKeyPressedEvent(event);
}

void SpaceInvadersImpl::onKeyReleaseEvent(QKeyEvent *event) {
    this->joueur->onKeyReleasedEvent(event);
}

void SpaceInvadersImpl::onNombreViesJoueurDiminue() {
    this->miseAJourTexteNombreDeViesJoueur();
}

void SpaceInvadersImpl::afficherNextRound() {
    this->getGraphicsView()->setScene(this);
}

void SpaceInvadersImpl::supprimerObjetsSpaceInvadersPixmapDuJeu(ObjetSpaceInvadersPixmapEvoluable *objetSpaceInvadersPixmap) {
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
        this->ennemiMystere = nullptr;
    }
    else if (objetType == "PartieDeMur") {
        PartieDeMur* partieDeMur = dynamic_cast<PartieDeMur*>(objetSpaceInvadersPixmap);
        this->mur1->supprimerPartieDeMur(partieDeMur);
        this->mur2->supprimerPartieDeMur(partieDeMur);
        this->mur3->supprimerPartieDeMur(partieDeMur);
        this->mur4->supprimerPartieDeMur(partieDeMur);
    }
    SpaceInvaders::supprimerObjetsSpaceInvadersPixmapDuJeu(objetSpaceInvadersPixmap);
}

void SpaceInvadersImpl::evoluer() {
    if (this->jeuEstGagne()) {
        this->actionAExecuterJeuGagne();
    }
    else if (this->jeuEstPerdu()) {
        this->actionAExecuterJeuPerdu();
    }
    if ((this->vagueEnnemis->getListeEnnemis().size() == 59) && (this->joueur->getNombreViesJoueur() > 0)) {
        qDebug() << "nouveau round";
        this->chargerNouveauRound();
        this->getGraphicsView()->setScene(this->sceneRound);
        QTimer::singleShot(2000, this, SLOT(afficherNextRound()));
    }
    SpaceInvaders::evoluer();
}
