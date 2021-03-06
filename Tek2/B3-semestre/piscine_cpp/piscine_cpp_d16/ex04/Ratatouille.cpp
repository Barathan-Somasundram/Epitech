//
// Ratatouille.cpp for  in /home/somasu_b/rendu/piscine_cpp_d16/ex04
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Jan 23 05:49:32 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 23 09:13:39 2015 SOMASUNDRAM Barathan
//

#include "Ratatouille.h"

Ratatouille::Ratatouille() 
{

}

Ratatouille::Ratatouille(const Ratatouille& other) 
{
  _str.str("");
  _str << other._str.rdbuf();
}

Ratatouille::~Ratatouille() 
{

}

Ratatouille& Ratatouille::operator=(const Ratatouille& other) 
{
  _str.str("");
  _str << other._str.rdbuf();
  return (*this);
}

Ratatouille& Ratatouille::addVegetable(unsigned char ingre) 
{
  _str << ingre;
  return (*this);
}

Ratatouille& Ratatouille::addCondiment(unsigned int ingre) 
{
  _str << ingre;
  return (*this);
}

Ratatouille& Ratatouille::addSpice(double ingre) 
{
  _str << ingre;
  return (*this);
}

Ratatouille& Ratatouille::addSauce(std::string ingre) 
{
  _str << ingre;
  return (*this);
}

std::string Ratatouille::kooc() 
{
  return (_str.str());
}

