/*
** Fruit.h for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 20 09:59:20 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 20 22:15:29 2015 SOMASUNDRAM Barathan
*/

#ifndef FRUIT_H_
# define FRUIT_H_

#include <iostream>
#include <string>

class				Fruit
{
  std::string			_name;
  int				_vitamins;
  
 public:
  Fruit();
  Fruit(std::string const, int);
  virtual ~Fruit();

  std::string const&		getName() const;
  int				getVitamins() const;
};

#endif /* !FRUIT_H_ */
