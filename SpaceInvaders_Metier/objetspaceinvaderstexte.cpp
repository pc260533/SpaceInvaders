#include "objetspaceinvaderstexte.h"

ObjetSpaceInvadersTexte::ObjetSpaceInvadersTexte(int positionX, int positionY):
    QGraphicsTextItem(), ObjetSpaceInvaders(positionX, positionY) {
    this->setPos(positionX, positionY);

}

void ObjetSpaceInvadersTexte::setTexte(QString texte) {
    this->texte = texte;
    this->setPlainText(this->texte);
}

void ObjetSpaceInvadersTexte::setFontTexte(QFont font) {
    this->font = font;
    this->setFont(font);
}

void ObjetSpaceInvadersTexte::setCouleurTexte(QColor couleur) {
    this->couleur = couleur;
    this->setDefaultTextColor(couleur);
}
