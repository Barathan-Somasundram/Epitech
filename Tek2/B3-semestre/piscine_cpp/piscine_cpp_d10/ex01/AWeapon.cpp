//
// AWeapon.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:44:20 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 09:07:59 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "AWeapon.hh"

AWeapon::AWeapon(std::string const& name, int apcost, int damage)
{
  this->name = name;
  this->apcost = apcost;
  this->damage = damage;
}

AWeapon::~AWeapon()
{

}

std::string const&			AWeapon::getName() const
{
  return (this->name);
}

int					AWeapon::getAPCost() const
{
  return (this->apcost);
}

int					AWeapon::getDamage() const
{
  return (this->damage);
}

void					AWeapon::attack() const
{

}
