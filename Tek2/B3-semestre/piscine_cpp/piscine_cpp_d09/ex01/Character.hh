//
// Character.hh for  in /home/somasu_b/rendu/piscine_cpp_d09/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 15 14:18:00 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 02:22:46 2015 SOMASUNDRAM Barathan
//

#ifndef CHARACTER_HH_
# define CHARACTER_HH_

#include <iostream>
#include <string>


class				Character
{
protected:
  std::string			_name;
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

  Character(std::string&, int);
  virtual ~Character();
  virtual const std::string&		getName() const;
  virtual int				getLvl() const;
  virtual int				getPv() const;
  virtual int				getPower() const;

  virtual int				CloseAttack();
  virtual int				RangeAttack();
  virtual void				Heal();
  virtual void				RestorePower();
  virtual void				TakeDamage(int _damage);
};

#endif /* !CHARACTER_HH_ */
