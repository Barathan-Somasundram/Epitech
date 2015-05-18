
#include "resto.hpp"

Ressources::Ressources()
{
  // time_t	act = time(NULL);

  for (int i = 0; i <= 8; i++)
    {
      _ressources.push_back(5);
      // _time[i] = act;
    }
}

Ressources::~Ressources()
{

}

void		Ressources::addRessources()
{
  time_t	act = time(NULL);

  for (int i = 0; i <= 8; i++)
    {
      if (difftime(act, _time[i]) >= 2)
	{
	  _ressources[i]++;
	  _time[i] = act;
	}
    }
}

std::vector<int>	Ressources::getRes()
{
  return (_ressources);
}

void			Ressources::delRessources(int id)
{
  // std::cout << "ID IS =>>>>> " << id << std::endl;
  --_ressources[id];
}
