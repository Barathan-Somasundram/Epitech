//
// Character.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:58:46 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 09:04:09 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Character.hh"

Character::Character(std::string const & name)
{
  this->name = name;
  this->ap = 40;
  this->weapon = NULL;
}

Character::~Character()
{

}

void				Character::recoverAP() 
{
  ap += 10;
  if (ap > 40)
    ap = 40;
}

void				Character::equip(AWeapon* weapon)
{
  this->weapon = weapon;
}

void				Character::attack(AEnemy* enemy)
{
  if (this->weapon == NULL || enemy == NULL)
    return ;
  if (this->ap >= this->weapon->getAPCost())
    {
      ap -= this->weapon->getAPCost();
      std::cout << this->name << " attacks " << enemy->getType()
		<< " with a " << this->weapon->getName() << std::endl;
      this->weapon->attack();
      enemy->takeDamage(this->weapon->getDamage());
      if (enemy->getHP() <= 0)
	delete enemy;
    }
}

std::string const&		Character::getName() const 
{
  return (this->name);
}

int				Character::getAp() const 
{
  return (this->ap);
}

AWeapon*			Character::getWeapon() const
{
  return (this->weapon);
}

std::ostream&			operator<<(std::ostream& w_exit, Character const& chara)
{
  w_exit << chara.getName() << " has " << chara.getAp() << " AP and ";
  if (chara.getWeapon() == NULL)
    w_exit << "is unarmed" << std::endl;
  else
    w_exit << "wields a " << chara.getWeapon()->getName() << std::endl;
  return (w_exit);
}
