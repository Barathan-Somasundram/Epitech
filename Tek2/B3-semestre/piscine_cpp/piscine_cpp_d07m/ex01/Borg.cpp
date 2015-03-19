//
// Borg.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 19:00:14 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 19:15:49 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Borg.hh"


Borg::Ship::Ship()
{
  this->_side = 300;
  this->_maxWarp = 9;
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
