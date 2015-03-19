#ifndef __STATWINDOW__
# define __STATWINDOW__

#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QLabel>
#include <QPainter>
#include <QMainWindow>
#include <QRect>
#include <QKeyEvent>
#include <QFont>
#include <QAbstractItemView>
#include <QSound>
#include <QListWidget>
#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include "Pokemon.hh"

class StatWindow : public QMainWindow
{
Q_OBJECT;
public:
  StatWindow(Pokemon *pkmn = NULL);
  virtual ~StatWindow();

  StatWindow& operator=(const StatWindow &);
protected:
	void		fillStats();
	void		fillEvolution();
	void		fillMoves();
protected:
  Pokemon *_pkmn;
  QTableWidget	*_listStat;
  QTableWidget	*_listMoves;
  QGridLayout	*_layout;
  QVBoxLayout	*_listLayout;
  QWidget       *_content;
  QScrollArea	*_listEvolution;
};


#endif
