#ifndef OBJETSPACEINVADERSTEXTE_H
#define OBJETSPACEINVADERSTEXTE_H

#include "objetspaceinvaders.h"

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QFont>



/**
 * @brief ObjetSpaceInvadersPixmapEvoluable est la classe représentant un objet textuel du jeu.
 * Elle hérite de QGraphicsTextItem et ObjetSpaceInvaders.
 */
class ObjetSpaceInvadersTexte : public QGraphicsTextItem, public ObjetSpaceInvaders {

private:
    /**
     * @brief texte : Le texte de l'objetSpaceInvadersTexte.
     */
    QString texte;
    /**
     * @brief font : La police de caractère de l'objetSpaceInvadersTexte.
     */
    QFont font;
    /**
     * @brief couleur : La couleur de l'objetSpaceInvadersTexte.
     */
    QColor couleur;

public:
    /**
     * @brief ObjetSpaceInvadersTexte : Constructeur prenant en paramètres la position en X et en Y du au coin en haut à gauche du texte.
     * @param positionX : La position en X.
     * @param positionY : La position en Y.
     */
    ObjetSpaceInvadersTexte(int positionX, int positionY);
    /**
     * @brief ~ObjetSpaceInvadersTexte : Destructeur sans paramètres.
     */
    virtual ~ObjetSpaceInvadersTexte();
    /**
     * @brief setTexte : Modifier le texte de l'objetSpaceInvadersTexte.
     * @param texte : Le texte de l'objetSpaceInvadersTexte.
     */
    void setTexte(QString texte);
    /**
     * @brief setFontTexte : Modifier la police de caractère de l'objetSpaceInvadersTexte.
     * @param font : La police de caractère de l'objetSpaceInvadersTexte.
     */
    void setFontTexte(QFont font);
    /**
     * @brief setCouleurTexte Modfiier la couleur de l'objetSpaceInvadersTexte.
     * @param couleur : La couleur de l'objetSpaceInvadersTexte.
     */
    void setCouleurTexte(QColor couleur);

};

#endif // OBJETSPACEINVADERSTEXTE_H
