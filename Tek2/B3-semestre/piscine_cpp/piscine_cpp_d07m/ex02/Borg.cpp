//
// Borg.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 19:00:14 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 21:24:41 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Destination.hh"
#include "Borg.hh"


Borg::Ship::Ship()
{
  this->_side = 300;
  this->_maxWarp = 9;
  this->_home = UNICOMPLEX;
  this->_location = this->_home;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{

}

void			Borg::Ship::setupCore(WarpSystem::Core *core)
{
  this->core = core;
}

void			Borg::Ship::checkCore()
{
  WarpSystem::QuantumReactor	*tmp;

  if (!this->core)
    return;
  tmp = this->core->checkReactor();
  std::cout << (tmp->isStable() == true ? "Everything is in order." : "Critical failure imminent.")
	    << std::endl;
}


bool			Borg::Ship::move(int warp, Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > this->_maxWarp || d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Borg::Ship::move(int warp)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > this->_maxWarp || this->_home == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}

bool			Borg::Ship::move(Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Borg::Ship::move()
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}
