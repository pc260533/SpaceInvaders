#ifndef OBJETSPACEINVADERSTEXTE_H
#define OBJETSPACEINVADERSTEXTE_H

#include "objetspaceinvaders.h"

#include <QGraphicsItem>
#include <QFont>



class ObjetSpaceInvadersTexte : public QGraphicsTextItem, public ObjetSpaceInvaders {

private:
    QString texte;
    QFont font;
    QColor couleur;

public:
    ObjetSpaceInvadersTexte(int positionX, int positionY);
    void setTexte(QString texte);
    void setFontTexte(QFont font);
    void setCouleurTexte(QColor couleur);

    // ObjetSpaceInvaders interface
public:
    void evoluerDansLeTemsp() override;

};

#endif // OBJETSPACEINVADERSTEXTE_H
