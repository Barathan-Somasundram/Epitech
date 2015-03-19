//
// Warrior.cpp for  in /home/somasu_b/rendu/piscine_cpp_d09/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 15 16:07:27 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 16 09:17:43 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Character.hh"
#include "Warrior.hh"

Warrior::Warrior(std::string& name, int level) : Character(name, level)
{
  this->_level = level;
  this->_hp = 100;
  this->_power = 100;
  this->_Stamina = 12;
  this->_Spirit = 5;
  this->_Agility = 7;
  this->_Strength = 12;
  this->_Intelligence = 6;
  this->Range = CLOSE;
  this->weaponName = "hammer";
  std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{

}

int				Warrior::CloseAttack()
{
  int	damage = 20;

  if (this->_power < 30)
    {
      std::cout << this->_name << " out of power" << std::endl;
      return (0);
    }
  this->_power -= 30;
  damage += this->_Strength;
  std::cout << this->_name << " strikes with his " << this->weaponName << std::endl;
  return (damage);
}

int				Warrior::RangeAttack()
{
  if (this->Range == CLOSE)
    return (this->CloseAttack());
  this->Range = CLOSE;
  if (this->_power < 10)
    {
      std::cout << this->_name << " out of power" << std::endl;
      return (0);
    }
  this->_power -= 10;
  std::cout << this->_name << " intercepts" << std::endl;
  return (0);
}
