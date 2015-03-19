//
// Object.cpp for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 10:20:00 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 00:44:02 2015 XU Alexandre
//

#include <iostream>
#include <string>
#include "Object.hh"

Object::Object(std::string name)
{
  name = name;
  type = NOTKNOWN;
  isTake = false;
}

Object::Object(Object const& other)
{
  name = other.getName();
  type = other.getType();
  isTake = other.getIsTaken();
}

Object::~Object()
{

}

void				Object::operator=(Object const& other)
{
  name = other.getName();
  type = other.getType();
  isTake = other.getIsTaken();
}

std::string			Object::getName() const
{
  return (name);
}

types				Object::getType() const
{
  return (type);
}

bool				Object::isToy() const
{
  if (type == TEDDY || type == LITTLEPONY)
    return (true);
  return (false);
}

bool				Object::isWrap() const
{
  if (type == BOX || type == PAPER)
    return (true);
  return (false);
}

bool				Object::getIsTaken() const
{
  return (isTake);
}

void				Object::isTaken()
{
  isTake = true;
}
