//
// my_exception.cpp for  in /home/somasu_b/rendu/cpp_plazza/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:20:19 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:20:19 2015 SOMASUNDRAM Barathan
//

#include "my_exception.hpp"

my_exception::my_exception(std::string error)
{
  _msg = error;
}

my_exception::~my_exception() throw()
{

}

const char*	my_exception::what() const throw()
{
  return (_msg.c_str());
}
