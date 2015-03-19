//
// Warpsystem.hh for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 10:51:26 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 17:50:47 2015 SOMASUNDRAM Barathan
//

#ifndef WARPSYSTEM_H_
# define WARPSYSTEM_H_

#include <iostream>
#include <string>

namespace			WarpSystem
{
  class				QuantumReactor
  {
    bool			_stability;

  public:
    QuantumReactor();
    ~QuantumReactor();
    bool			isStable();
    void			setStability(bool);
  };

  class				Core
  {
    QuantumReactor		*_coreReactor;

  public:
    Core(QuantumReactor *core);
    ~Core();
    QuantumReactor		*checkReactor();

  };
};

#endif /* !WARPSYSTEM_H_ */
