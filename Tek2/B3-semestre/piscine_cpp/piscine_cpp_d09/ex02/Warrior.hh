//
// Warrior.hh for  in /home/somasu_b/rendu/piscine_cpp_d09/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 15 16:07:00 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 02:20:30 2015 SOMASUNDRAM Barathan
//

#ifndef WARRIOR_HH_
# define WARRIOR_HH_

#include <iostream>
#include <string>
#include "Character.hh"

class				Warrior :  public Character
{
 protected:
  std::string			weaponName;

 public:
  Warrior(std::string&, int);
  ~Warrior();

  int				CloseAttack();
  int				RangeAttack();
};

#endif /* !WARRIOR_HH_ */
