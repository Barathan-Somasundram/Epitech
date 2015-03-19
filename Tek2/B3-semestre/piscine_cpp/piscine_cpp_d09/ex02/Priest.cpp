//
// Priest.cpp for  in /home/somasu_b/rendu/piscine_cpp_d09/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Jan 16 08:41:49 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 09:29:54 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Character.hh"
#include "Mage.hh"
#include "Priest.hh"

Priest::Priest(const std::string& name, int level) : Character(name, level), Mage(name, level)
{
  this->_level = level;
  this->_hp = 100;
  this->_power = 100;
  this->_Stamina = 4;
  this->_Spirit = 21;
  this->_Agility = 2;
  this->_Strength = 4;
  this->_Intelligence = 42;
  this->Range = CLOSE;
  std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
  
}

int			Priest::CloseAttack()
{
  int	damage = 10;

  if (this->_power < 10)
    {
      std::cout << this->_name << " out of power" << std::endl;
      return (0);
    }
  this->_power -= 10;
  damage += this->_Spirit;
  std::cout << this->_name << " uses a spirit explosion" << std::endl;
  return (damage);
}

void			Priest::Heal()
{
  this->_hp += 50;
  if (this->_hp > 100)
    this->_hp = 100;
  std::cout << this->_name << " takes a potion" << std::endl;
}
