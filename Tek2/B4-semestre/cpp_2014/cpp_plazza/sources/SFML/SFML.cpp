//
// SFML.cpp for  in /home/llyth/rendu/cpp_plazza/sources/SFML
//
// Made by llyth
// Login   <llyth@epitech.net>
//
// Started on  Sat Apr 25 15:45:14 2015 llyth
// Last update Sun Apr 26 17:47:02 2015 llyth
//

#include "SFML.hpp"

SFML::SFML(int cpk)
  : _cpk(cpk), _cpl(sqrt(cpk))
{
  t_pos				pos;
  t_kitchen			kitchen;
  t_cook			cook;

  this->_kitchensize = this->_cpl * COOK_SIZE;
  this->_window.create(sf::VideoMode(X_SIZE, Y_SIZE), "Plazza", sf::Style::Titlebar | sf::Style::Close);
  if (!_t_kitchen.loadFromFile(KITCHEN)
      || !_t_freecook.loadFromFile(FREECOOK)
      || !_t_busycook.loadFromFile(BUSYCOOK))
    throw (my_exception("Image failed to load"));
  this->_s_kitchen.setTexture(this->_t_kitchen);
  this->_s_kitchen.setPosition(sf::Vector2f(0, 0));
  this->_s_freecook.setTexture(this->_t_freecook);
  this->_s_busycook.setTexture(this->_t_busycook);
  for (int y = 0; y + this->_kitchensize < Y_SIZE; y += this->_kitchensize + 20)
    for (int x = 0; x + this->_kitchensize < X_SIZE; x += this->_kitchensize + 10)
      {
	for (int i = 0; i < this->_cpk; ++i)
	  {
	    cook.pos.x = x + (i % this->_cpl * COOK_SIZE);
	    cook.pos.y = y + (i / this->_cpl * COOK_SIZE);
	    kitchen.cooks.push_back(cook);
	  }
	kitchen.pos.x = x;
	kitchen.pos.y = y;
	kitchen.open = FALSE;
	kitchen.workingcook = 0;
	this->_kitchens.push_back(kitchen);
	kitchen.cooks.clear();
      }
}

SFML::~SFML(void)
{
}

bool				SFML::isOpen(void) const
{
  return (this->_window.isOpen());
}

void				SFML::closeWinEvent(void)
{
  while (this->_window.pollEvent(this->_event))
    if (this->_event.type == sf::Event::Closed
	|| (this->_event.type == sf::Event::KeyPressed && this->_event.key.code == sf::Keyboard::Escape))
      this->_window.close();
}

int				SFML::createKitchen(void)
{
  int				pos;
  t_tmp_kitchen			kitchen;

  pos = 0;
  for (std::vector<t_kitchen>::iterator itk = this->_kitchens.begin(); itk != this->_kitchens.end(); ++itk)
    {
      if ((*itk).open == FALSE)
	{
	  (*itk).open = TRUE;
	  return (pos);
	}
      ++pos;
    }
  pos = 0;
  for (std::vector<t_tmp_kitchen>::iterator itk = this->_tmp_kitchens.begin(); itk != this->_tmp_kitchens.end();
       ++itk)
    {
      if ((*itk).open == FALSE)
	{
	  (*itk).open = TRUE;
	  return (pos + this->_kitchens.size());
	}
      ++pos;
    }
  kitchen.open = TRUE;
  kitchen.workingcook = 0;
  kitchen.id = -1;
  this->_tmp_kitchens.push_back(kitchen);
  return (pos + this->_kitchens.size());
}

void				SFML::destroyKitchen(int kitchen)
{
  int				i;

  if (kitchen < this->_kitchens.size())
    {
      this->_kitchens[kitchen].open = FALSE;
      this->_kitchens[kitchen].workingcook = 0;
      for (std::vector<t_tmp_kitchen>::iterator itk = this->_tmp_kitchens.begin(); itk != this->_tmp_kitchens.end();
	   ++itk)
	{
	  if ((*itk).open == TRUE && (*itk).id == -1)
	    {
	      this->_kitchens[kitchen].open = TRUE;
	      this->_kitchens[kitchen].workingcook = (*itk).workingcook;
	      (*itk).id = kitchen;
	    }
	}
    }
  else
    {
      if (this->_tmp_kitchens[kitchen - this->_kitchens.size()].id != -1)
	{
	  this->_kitchens[this->_tmp_kitchens[kitchen - this->_kitchens.size()].id].open = FALSE;
	  this->_kitchens[this->_tmp_kitchens[kitchen - this->_kitchens.size()].id].workingcook = 0;
	}
      this->_tmp_kitchens[kitchen - this->_kitchens.size()].open = FALSE;
      this->_tmp_kitchens[kitchen - this->_kitchens.size()].workingcook = 0;
      this->_tmp_kitchens[kitchen - this->_kitchens.size()].id = -1;
    }
}

void				SFML::setWorkingCook(int kitchen, int nbr)
{
  if (kitchen < this->_kitchens.size())
    this->_kitchens[kitchen].workingcook = nbr;
  else
    {
      if (this->_tmp_kitchens[kitchen - this->_kitchens.size()].id != -1)
	this->_kitchens[this->_tmp_kitchens[kitchen - this->_kitchens.size()].id].workingcook = nbr;
      this->_tmp_kitchens[kitchen - this->_kitchens.size()].workingcook = nbr;
    }
}

void				SFML::displayArea(void)
{
  int				i;

  this->_window.clear(sf::Color::Black);
  this->_window.draw(this->_s_kitchen);
  for (std::vector<t_kitchen>::iterator itk = this->_kitchens.begin(); itk != this->_kitchens.end(); ++itk)
    {
      if ((*itk).open == TRUE)
	{
	  i = 0;
	  for (std::vector<t_cook>::iterator itc = (*itk).cooks.begin(); itc != (*itk).cooks.end(); ++itc)
	    {
	      if (i < (*itk).workingcook)
		{
		  this->_s_busycook.setPosition(sf::Vector2f((*itc).pos.x, (*itc).pos.y));
		  this->_window.draw(this->_s_busycook);
		}
	      else
		{
		  this->_s_freecook.setPosition(sf::Vector2f((*itc).pos.x, (*itc).pos.y));
		  this->_window.draw(this->_s_freecook);
		}
	      ++i;
	    }
	}
    }
  this->_window.display();
}
