#ifndef __POKEMONARRAY__
#define __POKEMONARRAY__

#include <vector>
#include "Pokemon.hh"

class PokemonArray : public std::vector<Pokemon *>
{
public:
  virtual	~PokemonArray();
  static PokemonArray & getInstance();

protected:
  PokemonArray();

private:
  static PokemonArray _instance;
};



#endif
