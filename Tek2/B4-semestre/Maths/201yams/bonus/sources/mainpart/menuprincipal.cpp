#include "menuprincipal.hpp"
 
MenuPrincipal::MenuPrincipal(QWidget *parent): QWidget(parent)
{
  QGridLayout* leLayoutMenuPrincipal =new QGridLayout(this);
  sonBoutonNouvellePartie =new QPushButton("Nouvelle Partie",this);
  sonBoutonNouvellePartie->setFixedWidth(sonBoutonNouvellePartie->width()+80);
  QObject::connect(sonBoutonNouvellePartie,SIGNAL(clicked()),parent,SLOT(game()));
  sonBoutonRegles =new QPushButton("Regles",this);
  sonBoutonRegles->setFixedWidth(sonBoutonRegles->width()+80);
  QObject::connect(sonBoutonRegles,SIGNAL(clicked()),parent,SLOT(regle()));
  sonBoutonAPropos =new QPushButton("A Propos",this);
  sonBoutonAPropos->setFixedWidth(sonBoutonAPropos->width()+80);
  QObject::connect(sonBoutonAPropos,SIGNAL(clicked()),parent,SLOT(changerPageAPropos()));
  sonBoutonQuitter =new QPushButton("Quitter",this);
  sonBoutonQuitter->setFixedWidth(sonBoutonQuitter->width()+80);
  QObject::connect(sonBoutonQuitter,SIGNAL(clicked()),parent,SLOT(close()));
  QLabel* leDeOrnementalGauche =new QLabel(this);
  leDeOrnementalGauche->setPixmap(QPixmap("Des/5.png"));
  QLabel* leDeOrnementalDroit =new QLabel(this);
  leDeOrnementalDroit->setPixmap(QPixmap("Des/5.png"));
  leLayoutMenuPrincipal->addWidget(leDeOrnementalGauche,1,1,1,1,Qt::AlignCenter);
  leLayoutMenuPrincipal->addWidget(new QLabel("<font size=\"30\"><b><u>YAMS</u></b></font>"),1,2,1,1,Qt::AlignCenter);
  leLayoutMenuPrincipal->addWidget(leDeOrnementalDroit,1,3,1,1,Qt::AlignCenter);
  leLayoutMenuPrincipal->addWidget(sonBoutonNouvellePartie,2,1,1,3,Qt::AlignCenter);
  leLayoutMenuPrincipal->addWidget(sonBoutonRegles,3,1,1,3,Qt::AlignCenter);
  leLayoutMenuPrincipal->addWidget(sonBoutonAPropos,4,1,1,3,Qt::AlignCenter);
  leLayoutMenuPrincipal->addWidget(sonBoutonQuitter,5,1,1,3,Qt::AlignCenter);
}
