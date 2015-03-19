//
// RadScorpion.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:54:19 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 03:50:25 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "AEnemy.hh"
#include "RadScorpion.hh"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
  std::cout << "* SPROTCH *" << std::endl;
}
