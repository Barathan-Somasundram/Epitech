//
// AEnemy.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:38:57 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 09:03:05 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const & type)
{
  this->hp = hp;
  this->type = type;
}

AEnemy::~AEnemy()
{

}

std::string const&		AEnemy::getType() const
{
  return (this->type);
}

int				AEnemy::getHP() const
{
  return (this->hp);
}

void				AEnemy::takeDamage(int damage)
{
  if (damage > 0)
    this->hp -= damage;
}
