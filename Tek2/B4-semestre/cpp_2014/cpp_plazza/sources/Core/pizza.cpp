#include "pizza.hpp"

const static Pizza::t_word	tab[5] =
  {
    {"Regina", " S", Pizza::Regina, Pizza::S},
    {"Margarita", " M", Pizza::Margarita, Pizza::M},
    {"Americaine", " L", Pizza::Americaine, Pizza::L},
    {"Fantasia", " XL", Pizza::Fantasia, Pizza::XL}
  };

const static std::string	tab2[4] =
  {
    "111110000",
    "111000000",
    "111001000",
    "110000111",
  };

Pizza::Pizza(std::string line, int multiplier)
  : _line(line), _mult(multiplier)
{
  parse();
  if (_type == Regina)
    _cookTime = 1 * _mult;
  if (_type == Margarita)
    _cookTime = 2 * _mult;
  if (_type == Americaine)
    _cookTime = 2 * _mult;
  if (_type == Fantasia)
    _cookTime = 4 * _mult;
  setIngredientCook();
}

Pizza::~Pizza()
{

}

void		Pizza::parse(void)
{
  size_t	pos;
  int		ok;

  ok = 0;
  for (int i = 0; i < 4 && ok == 0; i++)
    {
      pos = _line.find(tab[i].pizza.c_str());
      if (pos != std::string::npos)
	{
	  ok = 1;
	  _type = tab[i].type;
	}
    }
  ok = 0;
  for (int i = 0; i < 4 && ok == 0; i++)
    {
      pos = _line.find(tab[i].size);
      if (pos != std::string::npos)
	{
	  ok = 1;
	  _size = tab[i].siz;
	}
    }
  return ;
}

void			Pizza::setIngredientCook(void)
{
  int			i;
  int			j = -1;
  int			count = 0;
  i = (_type == Margarita ? 1 :
       (_type == Regina ? 0 :
	(_type == Americaine ? 2 :
	 (_type == Fantasia ? 3 : 4))));
  while (++j < 9)
    {
      _needed.push_back(static_cast<int>(tab2[i].c_str()[j] - '0'));
      if (static_cast<int>(tab2[i].c_str()[j]) == 1)
	count++;
    }
  _cook = count;
}

Pizza::TypePizza	Pizza::getType(void) const
{
  return (_type);
}

Pizza::TaillePizza	Pizza::getSize(void) const
{
  return (_size);
}

int			Pizza::getCook(void) const
{
  return (_cook);
}

std::vector<int>	Pizza::getNeeded(void) const
{
  return (_needed);
}

int		Pizza::getCookTime(void) const
{
  return (_cookTime);
}

void		Pizza::delRessources(int id, int nb)
{
  _needed[id] = nb;
  return ;
}
