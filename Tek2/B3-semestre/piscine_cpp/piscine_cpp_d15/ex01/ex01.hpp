//
// ex01.hpp for  in /home/somasu_b/rendu/piscine_cpp_d15/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 21 10:06:08 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 21 12:11:38 2015 SOMASUNDRAM Barathan
//

#ifndef EX01_H_
# define EX01_H_

#include <cstring>

template<typename X>
int	compare(const X& a, const X& b)
{
  if (a < b)
    return (-1);
  else if (a == b)
    return (0);
  return (1);
}

template<>
int	compare<const char*>(const char* const& a, const char* const &b)
{
  int	i;

  i = strcmp(a, b);
  if (i == 0)
    return (0);
  else if (i < 0)
    return (-1);
  return (1);
}

#endif /* !EX01_H_ */
