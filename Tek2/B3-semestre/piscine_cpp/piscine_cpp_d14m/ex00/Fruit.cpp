//
// Fruit.cpp for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 20 10:02:07 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 20 22:46:46 2015 SOMASUNDRAM Barathan
//

#include "Fruit.h"

Fruit::Fruit()
{
  _name = "fruit";
  _vitamins = 0;
}

Fruit::Fruit(std::string const name, int vita)
{
  _name = name;
  _vitamins = vita;
}

Fruit::~Fruit()
{

}

std::string const&		Fruit::getName() const
{
  return (_name);
}

int				Fruit::getVitamins() const
{
  return (_vitamins);
}
