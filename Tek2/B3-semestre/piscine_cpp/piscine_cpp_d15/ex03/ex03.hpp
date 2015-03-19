//
// ex03.hpp for  in /home/somasu_b/rendu/piscine_cpp_d15/ex03
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 21 14:59:05 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 21 15:06:05 2015 SOMASUNDRAM Barathan
//

#ifndef EX03_H_
# define EX03_H_

#include <iostream>

template <typename X>
void	foreach(const X* array, void (func)(const X&), const int size)
{
  int	i = 0;

  while (i < size)
    {
      (*func)(array[i]);
      i++;
    }
}

template <typename X>
void	print(const X& a)
{
  std::cout << a << std::endl;
}

#endif /* !EX03_H_ */
