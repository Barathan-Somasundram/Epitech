//
// Admiral.hh for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex04
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 14 02:11:13 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 14 09:04:42 2015 SOMASUNDRAM Barathan
//

#ifndef AMIRAL_H_
# define AMIRAL_H_

#include <iostream>
#include <string>
#include "Destination.hh"
#include "Federation.hh"
#include "Borg.hh"

namespace		Federation
{
  namespace		Starfleet
  {
    class		Admiral
    {
      std::string	_name;

    public:
      Admiral(std::string name);
      ~Admiral();
      void		(Federation::Starfleet::Ship::*firePtr)(Borg::Ship *borg)
      void		fire(Federation::Starfleet::Ship*, Borg::Ship*);
      bool		(Federation::Starfleet::Ship::*movePtr)(Destination d)
      bool		move(Federation::Starfleet::Ship*, Destination);
    };
  };
};

#endif /* !AMIRAL_H_ */
