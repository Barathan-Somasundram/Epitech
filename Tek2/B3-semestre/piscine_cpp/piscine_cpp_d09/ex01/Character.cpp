//
// Character.cpp for  in /home/somasu_b/rendu/piscine_cpp_d09/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 15 14:17:25 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 02:11:47 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Character.hh"

Character::Character(std::string& name, int level)
{
  this->_name = name;
  this->_level = level;
  this->_hp = 100;
  this->_power = 100;
  this->_Stamina = 5;
  this->_Spirit = 5;
  this->_Agility = 5;
  this->_Strength = 5;
  this->_Intelligence = 5;
  this->Range = CLOSE;
  std::cout << this->_name << " Created" << std::endl;
}

Character::~Character()
{

}

const std::string&		Character::getName() const
{
  return (this->_name);
}

int				Character::getLvl() const
{
  return (this->_level);
}

int				Character::getPv() const
{
  return (this->_hp);
}

int				Character::getPower() const
{
  return (this->_power);
}

int				Character::CloseAttack()
{
  int	damage = 10;

  if (this->_power < 10)
    {
      std::cout << this->_name << " out of power" << std::endl;
      return (0);
    }
  this->_power -= 10;
  damage += this->_Strength;
  std::cout << this->_name << " strikes with a wood stick" << std::endl;
  return (damage);
}

int				Character::RangeAttack()
{
  int	damage = 5;

  if (this->_power < 10)
    {
      std::cout << this->_name << " out of power" << std::endl;
      return (0);
    }
  this->_power -= 10;
  damage += this->_Strength;
  std::cout << this->_name << " launches a stone" << std::endl;
  return (damage);
}

void				Character::Heal()
{
  this->_hp += 50;
  if (this->_hp > 100)
    this->_hp = 100;
  std::cout << this->_name << " takes a potion" << std::endl;
}

void				Character::RestorePower()
{
  this->_power = 100;
  std::cout << this->_name << " eats" << std::endl;
}

void				Character::TakeDamage(int _damage)
{
  this->_hp -= _damage;
  if (this->_hp <= 0)
    std::cout << this->_name << " out of combat" << std::endl;
  else
    std::cout << this->_name << " takes " << _damage << " damage" << std::endl;
}
