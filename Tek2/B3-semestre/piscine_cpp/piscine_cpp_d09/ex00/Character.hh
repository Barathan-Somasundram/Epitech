//
// Character.hh for  in /home/somasu_b/rendu/piscine_cpp_d09/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 15 14:18:00 2015 SOMASUNDRAM Barathan
// Last update Thu Jan 15 15:45:27 2015 SOMASUNDRAM Barathan
//

#ifndef CHARACTER_HH_
# define CHARACTER_HH_

#include <iostream>
#include <string>


class				Character
{
protected:
  const std::string		_name;
  std::string			_race;
  int				_level;
  int				_power;
  int				_hp;
  int				_Stamina;
  int				_Spirit;
  int				_Agility;
  int				_Strength;
  int				_Intelligence;

public:
  enum				AttackRange
    {
      CLOSE,
      RANGE
    };
  
  AttackRange			Range;

  Character(const std::string&, int);
  ~Character();
  const std::string&		getName() const;
  int				getLvl() const;
  int				getPv() const;
  int				getPower() const;

  int				CloseAttack();
  int				RangeAttack();
  void				Heal();
  void				RestorePower();
  void				TakeDamage(int _damage);
};

#endif /* !CHARACTER_HH_ */
