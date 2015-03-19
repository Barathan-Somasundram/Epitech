//
// LittleHand.cpp for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 20 23:05:05 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 21 00:51:13 2015 SOMASUNDRAM Barathan
//

#include "LittleHand.h"

void				LittleHand::sortFruitBox(FruitBox& unsorted, FruitBox& lemons,
							 FruitBox& bananas,  FruitBox& limes)
{
  FruitBox			tmp(unsorted.nbFruits());  
  Fruit*			fruit;
  
  while ((fruit = tmp.pickFruit()) != NULL)
    tmp.putFruit(fruit);
  while ((fruit = tmp.pickFruit()) != NULL)
    if (fruit->getVitamins() == 5)
      bananas.putFruit(fruit);
    else if (fruit->getVitamins() == 3)
      lemons.putFruit(fruit);
    else if (fruit->getVitamins() == 2)
      limes.putFruit(fruit);
    else
      unsorted.putFruit(fruit);
}
