//
// Borg.hh for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 19:00:36 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 19:50:43 2015 SOMASUNDRAM Barathan
//

#ifndef BORG_H_
# define BORG_H_

#include <iostream>
#include <string>
#include "Warpsystem.hh"

namespace			Borg
{
  class				Ship
  {
    int				_side;
    short			_maxWarp;
    WarpSystem::Core		*core;
    
  public:
    Ship();
    ~Ship();
    void			setupCore(WarpSystem::Core *core);
    void			checkCore();
  };
};

#endif /* !BORG_H_ */
