//
// PowerFist.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:52:23 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 03:48:05 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "AWeapon.hh"
#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{

}

PowerFist::~PowerFist()
{

}

void				PowerFist::attack() const 
{
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
