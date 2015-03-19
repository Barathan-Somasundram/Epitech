//
// fenetreprincipal.cpp for  in /home/somasu_b/Downloads/ISO/l/playpart
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Feb 27 17:00:23 2015 SOMASUNDRAM Barathan
// Last update Sat Feb 28 01:54:13 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "fenetreprincipal.hpp"

#define FACE1 "../img/face-1.jpg"
#define FACE2 "../img/face-2.jpg"
#define FACE3 "../img/face-3.jpg"
#define FACE4 "../img/face-4.jpg"
#define FACE5 "../img/face-5.jpg"
#define FACE6 "../img/face-6.jpg"
 
FenetrePrincipale::FenetrePrincipale(QWidget *parent): QMainWindow(parent)
{
  _layout = new QGridLayout();
  _player1Dice = new QScrollArea();
  _player2Dice = new QScrollArea();
  _player1Score = new QTableWidget();
  _player2Score = new QTableWidget();
  _play1 = new QPushButton("Player1 Play !", this);
  _play2 = new QPushButton("Player2 A toi de jouer !", this);
  _content = new QWidget();
  _close = new QPushButton("Quitter", this);

  setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint 
		 | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
  setWindowTitle("Yams");
  setWindowIcon(QIcon("Des/5.png"));

  QObject::connect(_close, SIGNAL(clicked()), this, SLOT(close()));
  QObject::connect(_play1, SIGNAL(clicked()), this, SLOT(play1()));
  QObject::connect(_play2, SIGNAL(clicked()), this, SLOT(play2()));

  _layout->addWidget(_player1Dice, 0, 0);
  _layout->addWidget(_player2Dice, 1, 0);
  _layout->addWidget(_player1Score, 0, 1);
  _layout->addWidget(_player2Score, 1, 1);
  _layout->addWidget(_play1, 0, 2, 1, 1,  Qt::AlignCenter);
  _layout->addWidget(_play2, 1, 2, 1, 1,  Qt::AlignCenter);
  _layout->addWidget(_close, 2, 0, 1, 3,  Qt::AlignCenter);

  _content->setLayout(_layout);
  setCentralWidget(_content);

  setFixedSize(sizeHint());
}

FenetrePrincipale::~FenetrePrincipale()
{
  delete _layout;
  delete _player1Dice;
  delete _player2Dice;
  delete _player1Score;
  delete _player2Score;
  delete _content;
  delete _close;
}

void	FenetrePrincipale::fillScore(Player player, QTableWidget* playerScore)
{
  const char	tab[6][9] = 
    {
      "Brelan: ", 
      "Carre: ", 
      "Full: ", 
      "Suite: ", 
      "Yams: ", 
      "Chance: "
    };
  playerScore->setColumnCount(1);
  playerScore->setRowCount(6);
  playerScore->setShowGrid(false);
  playerScore->horizontalHeader()->setVisible(false);
  playerScore->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
  playerScore->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  playerScore->verticalHeader()->setVisible(false);
  playerScore->setEditTriggers(QAbstractItemView::NoEditTriggers);
  for (int i = 0;i < 6; ++i)
    {
      std::string stat(tab[i]);
      std::stringstream nb;
      if (i == 0)
	nb << player.getBrelan();
      else if (i == 1)
	nb << player.getCarre();
      else if (i == 2)
	nb << player.getFull();
      else if (i == 3)
	nb << player.getSuite();
      else if (i == 4)
	nb << player.getYams();
      else if (i == 5)
	nb << player.getChance();
      stat += nb.str();
      QTableWidgetItem *thumbnail = new QTableWidgetItem(stat.c_str());
      QFont	fnt;
      fnt.setPointSize(12);
      fnt.setFamily("Arial");
      thumbnail->setFont(fnt);
      playerScore->setItem(0, i, thumbnail);
    }
  playerScore->resizeRowToContents(0);
}

void	FenetrePrincipale::fillDiceImg(Player player, QScrollArea* playerDice)
{
  QGridLayout*	layout = new QGridLayout;
  std::string	name = FACE1;
  int		i = 1;
  int		j = 0;
  
  while (i < 6)
    {
      j = player.getDice(i-1);
      if (j == 1)
	name = FACE1;
      else if (j == 2)
	name = FACE2;
      else if (j == 3)
	name = FACE3;
      else if (j == 4)
	name = FACE4;
      else if (j == 5)
	name = FACE5;
      else if (j == 6)
	name = FACE6;
      
      QPixmap pic(name.c_str());
      QPixmap scaled = pic.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation);
      QLabel *label = new QLabel();

      label->setPixmap(scaled);
      if (i <= 3)
	layout->addWidget(label, 0, i, 1, 1, Qt::AlignCenter);
      else
	layout->addWidget(label, 1, i - 3, 1, 1, Qt::AlignCenter);
      ++i;
    }
  playerDice->setLayout(layout);
}

void FenetrePrincipale::changerMenuPrincipal()
{

}
 
void FenetrePrincipale::changerPageAPropos()
{

}

void FenetrePrincipale::play1()
{
  std::cout << "PLAY1" << std::endl;
  _player1.setDice(1);
  _player1.analyse();
  fillDiceImg(_player1, _player1Dice);
  fillScore(_player1, _player1Score);
}

void FenetrePrincipale::play2()
{
  std::cout << "PLAY2" << std::endl;
  _player2.setDice(2);
  _player2.analyse();
  fillDiceImg(_player2, _player2Dice);
  fillScore(_player2, _player2Score);
}
