/*
** LittleHand.h for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex01
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 20 23:01:36 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 20 23:03:52 2015 SOMASUNDRAM Barathan
*/

#ifndef LITTLEHAND_H_
# define LITTLEHAND_H_

#include "FruitBox.h"

class				LittleHand
{
 public:
  LittleHand();
  ~LittleHand();
  
  void				sortFruitBox(FruitBox& unsorted, FruitBox& lemons,
					     FruitBox& bananas, FruitBox& limes);
};

#endif /* !LITTLEHAND_H_ */
