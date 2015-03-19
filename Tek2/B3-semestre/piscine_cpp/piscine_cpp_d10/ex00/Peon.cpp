//
// Peon.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 00:44:31 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 00:50:25 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Peon.hh"

Peon::Peon(std::string name) : Victim(name)
{
  std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
  std::cout << "Bleuark..." << std::endl;
}

void				Peon::getPolymorphed() const
{
  std::cout << this->name << " has been turned into a pink pony !" << std::endl;
}
