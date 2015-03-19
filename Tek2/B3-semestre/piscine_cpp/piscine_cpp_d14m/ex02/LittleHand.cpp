//
// LittleHand.cpp for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 20 23:05:05 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 21 08:56:17 2015 SOMASUNDRAM Barathan
//

#include "LittleHand.h"
#include "Coconut.h"

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

FruitBox * const *		LittleHand::organizeCoconut(Coconut const * const * coconuts_packet)
{
  FruitBox*			box;
  int				nb = 0;
  int				i = 0;
  
  while (coconuts_packet[nb] != NULL)
    nb++;
  nb--;
  box = new FruitBox*[nb / 8];
  while (i < nb)
    {
      if (!(i % 6))
	box[i % 6] = new FruitBox(6);
      box[(i % 6) / 6]->putFruit(const_cast<Fruit*>(const_cast<Fruit* const*>(coconuts_packet)[i]));
      i++;
    }
  box[nb / 7] = NULL;
  return (box);
}
