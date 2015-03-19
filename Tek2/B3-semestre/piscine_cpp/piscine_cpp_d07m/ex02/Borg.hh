//
// Borg.hh for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 19:00:36 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 21:30:32 2015 SOMASUNDRAM Barathan
//

#ifndef BORG_H_
# define BORG_H_

#include <iostream>
#include <string>
#include "Warpsystem.hh"
#include "Destination.hh"

namespace			Borg
{
  class				Ship
  {
    int				_side;
    short			_maxWarp;
    WarpSystem::Core		*core;
    Destination			_location;
    Destination			_home;
    
  public:
    Ship();
    ~Ship();
    void			setupCore(WarpSystem::Core *core);
    void			checkCore();
    bool			move(int warp, Destination d); // move _location to d
    bool			move(int warp); // move _location to _home
    bool			move(Destination d); // move _location to d
    bool			move(); // move _location to _home  
  };
};

#endif /* !BORG_H_ */
