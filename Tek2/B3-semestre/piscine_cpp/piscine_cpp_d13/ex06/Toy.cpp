//
// Toy.cpp for  in /home/somasu_b/rendu/piscine_cpp_d13/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 19 10:04:00 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 19 23:08:06 2015 SOMASUNDRAM Barathan
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
  _Error.setType(Error::PICTURE);
  return (false);
}

bool				Toy::speak(const std::string statement)
{
  std::cout << _Name << " \"" << statement << "\"" << std::endl;
  return (true);
}

bool				Toy::speak_es(const std::string statement)
{
  (void)statement;
  _Error.setType(Error::SPEAK);
  return (false);
}

Toy&				Toy::operator<<(const std::string& ascii)
{
  _Picture.data = ascii;
  return (*this);
}

std::ostream&			operator<<(std::ostream& os, const Toy& other)
{
  os << other.getName() << std::endl;
  os << other.getAscii() << std::endl;
  return (os);
}

Toy::Error const&		Toy::getLastError() const
{
  return (_Error);
}

Toy::Error::Error()
{
  type = Toy::Error::UNKNOWN;
}

Toy::Error::~Error()
{

}

void				Toy::Error::setType(ErrorType type)
{
  this->type = type;
}

std::string			Toy::Error::what() const
{
  if (type == PICTURE)
    return ("bad new illustration");
  else if (type == SPEAK)
    return ("wrong mode");
  return ("");
}

std::string			Toy::Error::where() const
{
  if (type == PICTURE)
    return ("setAscii");
  else if (type == SPEAK)
    return ("speak_es");
  return ("");  
}
