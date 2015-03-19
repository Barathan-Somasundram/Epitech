//
// Federation.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 10:52:33 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 18:58:58 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Federation.hh"

/*
** FEDERATION STARFLEET SHIP
*/

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;

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

/*
** FEDERATION SHIP
*/

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
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
