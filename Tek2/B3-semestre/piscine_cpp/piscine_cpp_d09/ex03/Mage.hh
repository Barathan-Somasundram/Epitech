//
// Mage.hh for  in /home/somasu_b/rendu/piscine_cpp_d09/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Jan 16 01:56:43 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 02:07:10 2015 SOMASUNDRAM Barathan
//

#ifndef MAGE_HH_
# define MAGE_HH_

#include <iostream>
#include <string>
#include "Character.hh"

class				Mage : virtual public Character
{
public:
  Mage(const std::string&, int);
  ~Mage();

  int				CloseAttack();
  int				RangeAttack();
  void				RestorePower();
};

#endif /* !MAGE_HH_ */
