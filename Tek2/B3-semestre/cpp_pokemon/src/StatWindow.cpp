#include <sstream>
#include <iostream>
#include "PokemonArray.hh"
#include "StatWindow.hh"

StatWindow::StatWindow(Pokemon *pkmn)
	:_pkmn(pkmn),_listStat(new(QTableWidget))
	,_listMoves(new QTableWidget()),_layout(new QGridLayout())
	,_listLayout(new QVBoxLayout()), _content(new QWidget()),
	 _listEvolution(new QScrollArea())
{
	this->setWindowFlags(Qt::Popup);
	_content->setLayout(_listLayout);
	_layout->addWidget(_listStat, 2,0, 3, 2);
	_layout->addWidget(_listMoves, 2,2, 3, 2);
	_layout->addWidget(_listEvolution,0,0,2, 4);
	QWidget *central = new QWidget();
	central->setLayout(_layout);
	setCentralWidget(central);
	resize(960, 660);
	fillStats();
	fillEvolution();
	fillMoves();
}

StatWindow::~StatWindow() {
	delete _listStat;
	delete _listMoves;
	delete _layout;
	delete _listLayout;
}

void	StatWindow::fillStats()
{
	const char			tab[][18]={ "description","name", "type", "ability",
								   "HP", "ATK", "DEF", "SPD", "SAT", "SDF",
								   "male", "female", "egg-group", "egg-Type",
								   "species", "height", "weight"};
	_listStat->setColumnCount(1);
	PokeStats stats = _pkmn->getStats();
	_listStat->setRowCount(stats.size() - 1);
	_listStat->setShowGrid(false);
	_listStat->horizontalHeader()->setVisible(false);
	_listStat->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
	_listStat->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_listStat->verticalHeader()->setVisible(false);
	_listStat->setEditTriggers(QAbstractItemView::NoEditTriggers);
	for (int i = 0;i < 17; ++i)
	{
		std::string stat(tab[i]);
		stat += " :   " +stats[tab[i]];
		QTableWidgetItem *thumbnail = new QTableWidgetItem(stat.c_str());
		QFont	fnt;
		fnt.setPointSize(12);
		fnt.setFamily("Arial");
		thumbnail->setFont(fnt);
		_listStat->setItem(0, i, thumbnail);
	}
	_listStat->resizeRowToContents(0);
}

void	StatWindow::fillEvolution()
{
  Pokemon* poke = PokemonArray::getInstance()[_pkmn->getId() - 1];
  PokeEvolutions evol = poke->getEvolutions();
  PokeStats ev = evol[0];
  unsigned int i = 0;  
  QGridLayout* layout = new QGridLayout;

  while (i != evol.size())
    {
      std::string name = "./pokemonimg/";
      name  = name + evol[i]["id"] + ".png";
      QPixmap pic(name.c_str());
      QPixmap scaled = pic.scaled(250, 250, Qt::IgnoreAspectRatio, Qt::FastTransformation); // TODO: magic values
      QLabel *label = new QLabel();
      QLabel *labelt = new QLabel();
      QFont fnt;

      fnt.setPointSize(15);
      fnt.setFamily("Arial");
      fnt.setBold(true);

      label->setPixmap(scaled);
      name = "Level " + evol[i]["level"];
      labelt->setText(name.c_str());
      labelt->setFont(fnt);
      layout->addWidget(label, 0, i);
      layout->addWidget(labelt, 1, i);
      i++;
    }
  _listEvolution->setLayout(layout);
}
void	StatWindow::fillMoves()
{
	PokeMoves	moves = _pkmn->getMoves();
	_listMoves->setColumnCount(1);
	_listMoves->setRowCount(moves.size() - 1);
	_listMoves->setShowGrid(false);
	_listMoves->horizontalHeader()->setVisible(false);
	_listMoves->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
	_listMoves->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_listMoves->verticalHeader()->setVisible(false);
	_listMoves->setEditTriggers(QAbstractItemView::NoEditTriggers);
	for (unsigned int i = 0; i < moves.size(); ++i)
	{
		std::stringstream		move;

		move << "Type :";
		move << moves[i]["type"] << " Name :" <<  moves[i]["name"] <<  " \nLevel :" <<  moves[i]["level"];
		QTableWidgetItem *thumbnail = new QTableWidgetItem(move.str().c_str());
		QFont	fnt;
		fnt.setPointSize(15);
		fnt.setFamily("Arial");
		thumbnail->setFont(fnt);
		_listMoves->setItem(0, i, thumbnail);
	}
}

#include <iostream>

StatWindow& StatWindow::operator=(StatWindow const &other) {
  // Check for self-assignment!
  if (this == &other || _pkmn == other._pkmn)
    return *this;
  _pkmn = other._pkmn;
  update();
  
  return *this;
}
