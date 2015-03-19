//
// Federation.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 10:52:33 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 14 09:50:46 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Federation.hh"
#include "Destination.hh"

/*
** FEDERATION STARFLEET SHIP
*/

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_home = EARTH;
  this->_location = this->_home;

  std::cout << "The ship USS " << this->_name << " has been finished. It is "
	    << this->_length << " m in length and " << this->_width << " m in width."
	    << std::endl;
  std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{

}

void		Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
  this->core = core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void		Federation::Starfleet::Ship::checkCore()
{
  WarpSystem::QuantumReactor	*tmp;

  if (!this->core)
    return;
  tmp = this->core->checkReactor();
  std::cout << "USS " << this->_name << ": The core is "
	    << (tmp->isStable() == true ? "stable" : "unstable")
	    << " at the time." << std::endl;
}

void		Federation::Starfleet::Ship::promote(Captain *cap)
{
  this->cap = cap;
  std::cout << this->cap->getName() << ": I'm glad to be the captain of the USS "
	    << this->_name << "." << std::endl;
}

bool			Federation::Starfleet::Ship::move(int warp, Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > this->_maxWarp || d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Federation::Starfleet::Ship::move(int warp)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > this->_maxWarp || this->_home == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}

bool			Federation::Starfleet::Ship::move(Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Federation::Starfleet::Ship::move()
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}

/*
** FEDERATION SHIP
*/

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_home = VULCAN;
  this->_location = this->_home;
  std::cout << "The independant ship " << this->_name << " just finished its construction."
	    << " It is " <<this->_length << " m in length and " << this->_width
	    << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{

}

void		Federation::Ship::setupCore(WarpSystem::Core *core)
{
  this->core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void		Federation::Ship::checkCore()
{
  WarpSystem::QuantumReactor	*tmp;

  if (!this->core)
    return;
  tmp = this->core->checkReactor();
  std::cout << this->_name << ": The core is "
	    << (tmp->isStable() == true ? "stable" : "unstable")
	    << " at the time." << std::endl;
}

bool			Federation::Ship::move(int warp, Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > 1 || d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Federation::Ship::move(int warp)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > 1 || this->_home == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}

bool			Federation::Ship::move(Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Federation::Ship::move()
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}

/*
** FEDERATION STARFLEET CAPTAIN
*/

Federation::Starfleet::Captain::Captain(std::string name)
{
  this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{

}

std::string		Federation::Starfleet::Captain::getName()
{
  return (this->_name);
}

int			Federation::Starfleet::Captain::getAge()
{
  return (this->_age);
};

void			Federation::Starfleet::Captain::setAge(int age)
{
  this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  this->_name = name;
  std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{

}
