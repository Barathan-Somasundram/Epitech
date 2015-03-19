//
// PlasmaRifle.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:49:16 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 03:46:47 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
  
}

PlasmaRifle::~PlasmaRifle()
{

}

void				PlasmaRifle::attack() const
{
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
