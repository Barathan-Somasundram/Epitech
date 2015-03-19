/*
** Fruit.h for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 20 09:59:20 2015 SOMASUNDRAM Barathan
** Last update Wed Jan 21 00:48:12 2015 SOMASUNDRAM Barathan
*/

#ifndef FRUIT_H_
# define FRUIT_H_

#include <iostream>
#include <string>

class				Fruit
{
 protected:
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
