//
// Toy.cpp for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 10:22:42 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 18:47:33 2015 Stuart Sulaski
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
