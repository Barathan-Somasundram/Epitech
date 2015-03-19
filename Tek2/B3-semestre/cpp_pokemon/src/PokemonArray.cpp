#include "PokemonArray.hh"

PokemonArray PokemonArray::_instance =  PokemonArray();

PokemonArray::PokemonArray()
{
}

PokemonArray::~PokemonArray()
{
}

PokemonArray &PokemonArray::getInstance(){  
  return _instance;
}
