//
// SuperMutant.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:56:32 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 03:38:48 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
  std::cout << "Aaargh ..." << std::endl;
}

void				SuperMutant::takeDamage(int damage)
{
  AEnemy::takeDamage(damage - 3);
}
