//
// Priest.hh for  in /home/somasu_b/rendu/piscine_cpp_d09/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Jan 16 01:56:07 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 09:06:43 2015 SOMASUNDRAM Barathan
//

#ifndef PRIEST_HH_
# define PRIEST_HH_

#include <iostream>
#include <string>
#include "Character.hh"

class				Priest : public Mage
{
public:
  Priest(const std::string&, int);
  ~Priest();

  int				CloseAttack();
  void				Heal();
};

#endif /* !PRIEST_HH_ */
