#ifndef FENETREPRINCIPALE_HPP
#define FENETREPRINCIPALE_HPP
 
#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QMenuBar>
#include "menuprincipal.hpp"
#include "pageapropos.hpp"
#include "Player.hpp"
 
class			FenetrePrincipale : public QMainWindow
{   Q_OBJECT
 
private:
  MenuPrincipal*	sonMenuPrincipal;
  PageAPropos*		saPageAPropos;

  QWidget*		_content;
  QGridLayout*		_layout;
  QPushButton*		_close;

  Player		_player1;
  QScrollArea*		_player1Dice;
  QTableWidget*		_player1Score;
  QPushButton*		_play1;

  Player		_player2;
  QScrollArea*		_player2Dice;
  QTableWidget*		_player2Score;
  QPushButton*		_play2;
 
  void			winWindow(void);
public:
  FenetrePrincipale(QWidget *parent = 0);
  ~FenetrePrincipale();
     
signals:
     
public slots:
  void	changerMenuPrincipal();
  void	changerPageAPropos();
  void	play1();
  void	play2();

public:
  void	fillDiceImg(Player, QScrollArea*);
  void	fillScore(Player, QTableWidget*);
     
};
 
#endif // FENETREPRINCIPALE_HPP
