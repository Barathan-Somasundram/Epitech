//
// Teddy.cpp for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 09:49:02 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 00:47:09 2015 XU Alexandre
//

#include <iostream>
#include <string>
#include "Toy.hh"
#include "Teddy.hh"

Teddy::Teddy(std::string name) : Toy(name)
{
  this->type = TEDDY;
  this->isTake = false;
}

Teddy::Teddy(Teddy const& other) : Toy(other.getName())
{
  this->type = TEDDY;
  this->isTake = other.getIsTaken();
}

Teddy::~Teddy()
{

}

void				Teddy::operator=(Teddy const& other)
{
  this->name = other.getName();
  this->type = TEDDY;
  this->isTake = other.getIsTaken();
}

std::ostream&			Teddy::operator<<(std::ostream &os, Teddy const &barati)
{
  os << barati.getName() << std::endl;
  return os;
}

void				Teddy::isTaken()
{
  this->isTake = true;
  std::cout << "gra hu" << std::endl;
}
