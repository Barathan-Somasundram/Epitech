//
// Toy.cpp for  in /home/somasu_b/rendu/piscine_cpp_d13/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 19 10:04:00 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 19 12:57:38 2015 SOMASUNDRAM Barathan
//

#include "Toy.h"

Toy::Toy()
{
  _Type = BASIC_TOY;
  _Name = "toy";
}

Toy::Toy(const Toy& other)
{
  _Name = other.getName();
  _Type = other.getType();
  _Picture.data = other.getAscii();
}

Toy::Toy(const ToyType type, const std::string name, const std::string filename)
{
  _Name = name;
  _Type = type;
  _Picture.getPictureFromFile(filename);
}

Toy::~Toy()
{

}

Toy&					Toy::operator=(const Toy& other)
{
  _Name = other.getName();
  _Type = other.getType();
  _Picture.data = other.getAscii();
  return (*this);
}

Toy::ToyType				Toy::getType() const
{
  return (_Type);
}

std::string			Toy::getName() const
{
  return (_Name);
}

std::string			Toy::getAscii() const
{
  return (_Picture.data);
}

void				Toy::setName(std::string name)
{
  _Name = name;
}

bool				Toy::setAscii(std::string filename)
{
  if (_Picture.getPictureFromFile(filename))
    return (true);
  return (false);
}

