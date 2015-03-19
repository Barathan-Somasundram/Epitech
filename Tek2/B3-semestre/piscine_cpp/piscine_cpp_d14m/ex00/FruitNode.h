/*
** FruitNode.h for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 20 22:20:43 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 20 22:47:57 2015 SOMASUNDRAM Barathan
*/

#ifndef FRUITNODE_H_
# define FRUITNODE_H_

#include "Fruit.h"

class				FruitNode
{
 public:
  Fruit*			fruit;
  FruitNode*			next;
};

#endif /* !FRUITNODE_H_ */
