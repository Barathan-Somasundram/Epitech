#include "Pokemon.hh"
Pokemon::Pokemon(int id, PokeStats stats, PokeEvolutions evolutions, PokeMoves moves)
	:_id(id),  _moves(moves),_stats(stats), _evolutions(evolutions), _label(NULL)
{
}

Pokemon::Pokemon(int id)
  :_id(id), _label(NULL)
{
	;
}

Pokemon::~Pokemon()
{
	;
}

PokeStats const &Pokemon::getStats() const{
  return _stats;
}

PokeMoves const	&Pokemon::getMoves() const{
	return _moves;
}

QLabel *Pokemon::getLabel() const {
	return _label;
}

void Pokemon::setLabel(QLabel *label) {
	_label = label;
}

PokeEvolutions Pokemon::getEvolutions() const
{
  return (_evolutions);
}

int Pokemon::getId() const
{
  return (_id);
}
