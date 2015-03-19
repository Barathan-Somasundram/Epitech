#ifndef __POKEDEX__
# define __POKEDEX__


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
#include <sstream>
#include "Pokemon.hh"
#include "PokemonArray.hh"
#include "StatWindow.hh"

class Pokedex : public QMainWindow
{
Q_OBJECT;
public:
  Pokedex();
  virtual ~Pokedex();

protected slots:
  void cellSelected(int, int, int, int);
  void openWindow(int x, int y);

protected:
  void fillNames() const;
  std::string imgName(int i) const;
  const char *pkmnName(int i) const;
  virtual void paintEvent(QPaintEvent *event);
  QLabel *addPicToList(std::string const &name) const;
  virtual void keyPressEvent(QKeyEvent *event);
  void goToEvol(int);
  void setupTable() const;
  void setupList() const;

protected:
  QScrollArea	*_list;
  QTableWidget	*_table;
  QHBoxLayout	*_layout;
  QVBoxLayout	*_listLayout;
  QWidget       *_content;
  QSound	*_player;
};

#endif /* __POKEDEX__ */
