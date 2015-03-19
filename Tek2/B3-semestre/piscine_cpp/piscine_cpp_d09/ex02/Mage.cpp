//
// Mage.cpp for  in /home/somasu_b/rendu/piscine_cpp_d09/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Jan 16 08:41:46 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 09:30:37 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Character.hh"
#include "Mage.hh"

Mage::Mage(const std::string& name, int level) : Character(name, level)
{
  this->_level = level;
  this->_hp = 100;
  this->_power = 100;
  this->_Stamina = 6;
  this->_Spirit = 11;
  this->_Agility = 7;
  this->_Strength = 6;
  this->_Intelligence = 12;
  this->Range = CLOSE;
  std::cout << this->_name << "teleported" << std::endl;
}

Mage::~Mage()
{

}

int			Mage::CloseAttack()
{
  if (this->Range == RANGE)
    return (this->RangeAttack());
  this->Range = RANGE;
  if (this->_power < 10)
    {
      std::cout << this->_name << " out of power" << std::endl;
      return (0);
    }
  this->_power -= 10;
  std::cout << this->_name << " blinks" << std::endl;
  return (0);
}

int			Mage::RangeAttack()
{
  int	damage = 20;

  if (this->_power < 25)
    {
      std::cout << this->_name << " out of power" << std::endl;
      return (0);
    }
  this->_power -= 25;
  damage += this->_Spirit;
  std::cout << this->_name << " launches a fire ball" << std::endl;
  return (damage);
}

void			Mage::RestorePower()
{
  this->_power += 50 + this->_Intelligence;
  if (this->_power > 100)
    this->_power = 100;
  std::cout << this->_name << " takes a mana potion" << std::endl;
}
