#ifndef POKEMON_HH_
# define POKEMON_HH_

#include <map>
#include <vector>
#include <QLabel>
#include <string>

typedef std::vector<std::map<std::string, std::string>  > PokeMoves;
typedef std::vector<std::map<std::string, std::string>  > PokeEvolutions;
typedef std::map<std::string, std::string> PokeStats;
class Pokemon
{
public:
  Pokemon(int id, PokeStats stats, PokeEvolutions evolutions, PokeMoves moves);
  Pokemon(const Pokemon &) {}; // TODO: cpp file
  Pokemon(int id);
  ~Pokemon();

public:
  PokeStats const &getStats() const;
  QLabel *getLabel() const;
  void setLabel(QLabel *);
  PokeEvolutions getEvolutions() const;
  int getId() const;
	const PokeMoves	&getMoves() const;

private:
  int		_id;
  PokeMoves	_moves;
  PokeStats	_stats;
  PokeEvolutions _evolutions;
  QLabel	*_label;
};

#endif
