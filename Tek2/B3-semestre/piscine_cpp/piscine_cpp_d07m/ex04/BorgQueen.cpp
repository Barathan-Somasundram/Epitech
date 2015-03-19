//
// BorgQueen.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex04
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 14 09:31:30 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 14 09:42:09 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Destination.hh"
#include "Federation.hh"
#include "Borg.hh"
#include "BorgQueen.hh"

Borg::BorgQueen::BorgQueen()
{
  movePtr = &Borg::Ship::move;
  firePtr = &Borg::Ship::fire;
  destroyPtr = &Borg::Ship::fire;
}

Borg::BorgQueen::~BorgQueen()
{

}

bool		Borg::BorgQueen::move(Borg::Ship* borg, Destination d)
{
  return ((borg->*movePtr)(d));
}

void		Borg::BorgQueen::fire(Borg::Ship* borg, Federation::Starfleet::Ship* ea)
{
  (borg->*firePtr)(ea);
}

void		Borg::BorgQueen::destroy(Borg::Ship* borg, Federation::Ship* vu)
{
  (borg->*destroyPtr)(vu);
}
