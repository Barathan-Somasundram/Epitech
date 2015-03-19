//
// Toy.cpp for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 10:22:42 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 05:56:24 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Object.hh"
#include "Toy.hh"

Toy::Toy(std::string name) : Object(name)
{

}

Toy::Toy(Toy const& other) : Object(other.getName())
{
  this->type = other.getType();
  this->isTake = other.getIsTaken();
}

Toy::~Toy()
{

}

void				Toy::operator=(Toy const& other)
{
  this->name = other.getName();
  this->type = other.getType();
  this->isTake = other.getIsTaken();
}

Object*			wrapMeThat(Object const * &, Object const * &, Object const * &)
{
  std::cerr << "Sorry, you cannot call this function" << std::endl;
  return (NULL);
}

void				openMe()
{
  std::cerr << "Sorry, you cannot call this function" << std::endl;
}

void				closeMe()
{
  std::cerr << "Sorry, you cannot call this function" << std::endl;
}

bool				isOpen()
{
  std::cerr << "Sorry, you cannot call this function" << std::endl;
  return (false);
}

bool				isEmpty()
{
  std::cerr << "Sorry, you cannot call this function" << std::endl;
  return (false);
}

void				fillMe()
{
  std::cerr << "Sorry, you cannot call this function" << std::endl;
}
