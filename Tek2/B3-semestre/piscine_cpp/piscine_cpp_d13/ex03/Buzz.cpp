//
// Buzz.cpp for  in /home/somasu_b/rendu/piscine_cpp_d13/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 19 11:58:23 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 19 12:14:29 2015 SOMASUNDRAM Barathan
//

#include "Toy.h"
#include "Buzz.h"

Buzz::Buzz(const std::string name, const std::string filename) : Toy(Toy::BUZZ, name, filename)
{
}

Buzz::~Buzz()
{

}

void				Buzz::speak(const std::string statement)
{
  std::cout << "BUZZ: " << _Name << " \"" << statement << "\"" << std::endl;
}
