#include "pageapropos.hpp"
 
PageAPropos::PageAPropos(QWidget *parent): QWidget(parent)
{
  QVBoxLayout* leLayoutAPropos =new QVBoxLayout(this);
  sonIllustration =new QLabel(this);
  sonIllustration->setPixmap(QPixmap("Des/5.png"));
  sonTexte =new QLabel("Bienvenue dans le celebre jeu du Yams !<br>Ce jeu a ete developpe par Guillaume Potier et Barathan Somasundram",this);
  sonBoutonRetour =new QPushButton("Quitter",this);
  QObject::connect(sonBoutonRetour,SIGNAL(clicked()),parent,SLOT(// close()
								 changerMenuPrincipal()));
  leLayoutAPropos->addWidget(sonIllustration,0,Qt::AlignCenter);
  leLayoutAPropos->addWidget(sonTexte,0,Qt::AlignCenter);
  leLayoutAPropos->addWidget(sonBoutonRetour,0,Qt::AlignCenter);
}
