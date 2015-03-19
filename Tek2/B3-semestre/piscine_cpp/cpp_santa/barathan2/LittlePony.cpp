//
// LittlePony.cpp for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 09:48:25 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 00:46:19 2015 XU Alexandre
//

#include <iostream>
#include <string>
#include "Toy.hh"
#include "LittlePony.hh"

LittlePony::LittlePony(std::string name) : Toy(name)
{
  this->type = LITTLEPONNY;
  this->isTake = false;
}

LittlePony::LittlePony(LittlePony const& other) : Toy(other.getName())
{
  this->type = LITTLEPONNY;
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

std::ostream&			LittlePony::operator<<(std::ostream &os, LittlePony const &somasu)
{
  os << somasu.getName() << std::endl;
}

void				LittlePony::isTaken()
{
  this->isTake = true;
  std::cout << "yo man" << std::endl;
}
