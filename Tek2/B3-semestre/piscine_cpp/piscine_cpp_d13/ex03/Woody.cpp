//
// Woody.cpp for  in /home/somasu_b/rendu/piscine_cpp_d13/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 19 11:54:49 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 19 12:14:50 2015 SOMASUNDRAM Barathan
//

#include "Toy.h"
#include "Woody.h"

Woody::Woody(const std::string name, const std::string filename) : Toy(Toy::WOODY, name, filename)
{
}

Woody::~Woody()
{

}

void				Woody::speak(const std::string statement)
{
    std::cout << "WOODY: " << _Name << " \"" << statement << "\"" << std::endl;
}
