/*
** FruitBox.h for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 20 22:00:52 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 20 22:33:11 2015 SOMASUNDRAM Barathan
*/

#ifndef FRUITBOX_H_
# define FRUITBOX_H_

#include <iostream>
#include <string>
#include "FruitNode.h"
#include "Fruit.h"

class				FruitBox
{
 protected:
  int				_nb;
  int				_size;
  FruitNode*			_list;

 public:
  FruitBox(int);
  virtual ~FruitBox();

  int				nbFruits() const;
  FruitNode*			head() const;

  bool				putFruit(Fruit*);
  Fruit*			pickFruit();
};

#endif /* !FRUITBOX_H_ */
