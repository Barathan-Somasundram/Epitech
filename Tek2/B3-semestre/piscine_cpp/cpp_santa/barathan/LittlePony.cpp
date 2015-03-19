//
// LittlePony.cpp for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 09:48:25 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 02:12:23 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Toy.hh"
#include "LittlePony.hh"

LittlePony::LittlePony(std::string name) : Toy(name)
{
  this->type = LITTLEPONY;
  this->isTake = false;
}

LittlePony::LittlePony(LittlePony const& other) : Toy(other.getName())
{
  this->type = LITTLEPONY;
  this->isTake = getIsTaken();
}

LittlePony::~LittlePony()
{

}

void				LittlePony::operator=(LittlePony const& other)
{
  this->name = other.getName();
  this->type = other.getType();
  this->isTake = other.getIsTaken();
}

std::ostream&			operator<<(std::ostream &os, LittlePony const &somasu)
{
  os << somasu.getName() << std::endl;
}

void				LittlePony::isTaken()
{
  this->isTake = true;
  std::cout << "yo man" << std::endl;
}
