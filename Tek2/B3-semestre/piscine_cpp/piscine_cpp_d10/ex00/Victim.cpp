//
// Victim.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 00:54:32 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 01:43:56 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Victim.hh"

Victim::Victim(std::string name)
{
  this->name = name;
  std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::~Victim()
{
  std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
}

std::string			Victim::getName() const
{
  return (this->name);
}

void				Victim::getPolymorphed() const
{
  std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream&			operator<<(std::ostream& w_exit, Victim& victim)
{
  w_exit << "I'm " << victim.getName() << " and i like otters !" << std::endl;
  return (w_exit);
}

