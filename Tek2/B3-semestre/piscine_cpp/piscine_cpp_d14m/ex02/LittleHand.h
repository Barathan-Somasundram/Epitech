/*
** LittleHand.h for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex01
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 20 23:01:36 2015 SOMASUNDRAM Barathan
** Last update Wed Jan 21 08:55:29 2015 SOMASUNDRAM Barathan
*/

#ifndef LITTLEHAND_H_
# define LITTLEHAND_H_

#include "FruitBox.h"
#include "Coconut.h"

class				LittleHand
{
 public:
  LittleHand();
  ~LittleHand();
  
  static void	       		sortFruitBox(FruitBox& unsorted, FruitBox& lemons,
					     FruitBox& bananas, FruitBox& limes);
  static FruitBox * const *	organizeCoconut(Coconut const * const * coconuts_packet);
};

#endif /* !LITTLEHAND_H_ */
