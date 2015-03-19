//
// Character.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:11:36 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 03:45:20 2015 SOMASUNDRAM Barathan
//

#ifndef CHARACTER_HH_
# define CHARACTER_HH_

#include <iostream>
#include <string>
#include "AWeapon.hh"
#include "AEnemy.hh"

class				Character
{
protected:
  std::string			name;
  int				ap;
  AWeapon			*weapon;

public:
  Character(std::string const& name);
  ~Character();

  std::string const&		getName() const;
  void				recoverAP();
  void				equip(AWeapon *weapon);
  void				attack(AEnemy *enemy);
  int				getAp() const;
  AWeapon*			getWeapon() const;
  //bool				action(int cost);
};

std::ostream&			operator<<(std::ostream& w_exit, Character const& chara);

#endif /* !CHARACTER_HH_ */
