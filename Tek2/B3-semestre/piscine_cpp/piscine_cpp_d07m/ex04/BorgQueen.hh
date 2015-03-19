//
// BorgQueen.hh for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex04
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 14 02:21:40 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 14 09:33:07 2015 SOMASUNDRAM Barathan
//

#ifndef BORGQUEEN_H_
# define BORGQUEEN_H_

#include <iostream>
#include <string>
#include "Destination.hh"
#include "Federation.hh"
#include "Borg.hh"

namespace			Borg
{
  class				BorgQueen
  {
  public:
    BorgQueen();
    ~BorgQueen();
    bool			(Borg::Ship::*movePtr)(Destination d);
    bool			move(Borg::Ship* borg, Destination d);
    void			(Borg::Ship::*firePtr)(Federation::Starfleet::Ship* ea);
    void			fire(Borg::Ship* borg, Federation::Starfleet::Ship* ea);
    void			(Borg::Ship::*destroyPtr)(Federation::Ship* vu);
    void			destroy(Borg::Ship* borg, Federation::Ship* vu);
  };
};

#endfi /* !BORGQUEEN_H_ */
