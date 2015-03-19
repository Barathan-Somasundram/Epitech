//
// Admiral.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex04
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 14 09:03:59 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 14 09:41:40 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Destination.hh"
#include "Federation.hh"
#include "Borg.hh"
#include "Admiral.hh"

Federation::Starfleet::Admiral::Admiral(std::string name)
{
  this->_name = name;
  firePtr = &Federation::Starfleet::Ship::fire;
  movePtr = &Federation::Starfleet::Ship::move;  
  std::cout << "Admiral " << this->_name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{
  
}

void		Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship* ea, Borg::Ship* borg)
{
  std::cout << "On order from Admiral " << this->_name << ":"  << std::endl;
  (ea->*firePtr)(borg);
}

bool		Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship* ea, Destination d)
{
  return ((ea->*movePtr)(d));
}

