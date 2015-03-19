//
// ex06.hpp for  in /home/somasu_b/rendu/piscine_cpp_d15/ex06
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 22 05:44:52 2015 SOMASUNDRAM Barathan
// Last update Thu Jan 22 09:10:22 2015 SOMASUNDRAM Barathan
//

#ifndef EX06_H_
# define EX06_H_

#include <iostream>
#include <sstream>
#include <string>


template <typename X, typename Y = X>
class				Tuple
{
public:
  X				a;
  Y				b;

  std::string			toString()
  {
    std::string			sent;

    sent = std::string("[TUPLE [") + print(a) + "] [" + print(b) + "]]";
    return (sent);
  }
};

template<typename T>
std::string print(T) 
{
  return (std::string("???"));
}

template<>
std::string print(int a) 
{
  std::stringstream tostr;

  tostr << a;
  return (std::string("int:") + tostr.str());
}

template<>
std::string print(float a) 
{
  std::stringstream tostr;

  tostr << a;
  return (std::string("float:") + tostr.str());
}

template<>
std::string print(std::string a) 
{
  return (std::string("string:\"") + a + "\"");
}

#endif /* !EX06_H_ */
