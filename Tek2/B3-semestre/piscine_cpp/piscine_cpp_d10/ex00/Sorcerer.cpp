//
// Sorcerer.cpp for  in /home/somasu_b/rendu/piscine_cpp_d10/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 01:12:30 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 01:40:47 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Victim.hh"
#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string name, std::string title)
{
  this->name = name;
  this->title = title;
  std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
  std::cout << this->name << ", " << this->title
	    << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string			Sorcerer::getName() const
{
  return (this->name);
}

std::string			Sorcerer::getTitle() const
{
  return (this->title);
}

void				Sorcerer::polymorph(Victim const& victim) const
{
  victim.getPolymorphed();
}

std::ostream&			operator<<(std::ostream& w_exit, Sorcerer& sorcerer)
{
  w_exit << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
  return (w_exit);
}

