//
// FruitBox.cpp for  in /home/somasu_b/rendu/piscine_cpp_d14m/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 20 22:01:29 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 20 22:48:28 2015 SOMASUNDRAM Barathan
//

#include "FruitBox.h"

FruitBox::FruitBox(int size)
{
  _size = size;
  _nb = 0;
  _list = NULL;
}

FruitBox::~FruitBox()
{

}

int				FruitBox::nbFruits() const
{
  return (_nb);
}

FruitNode*			FruitBox::head() const
{
  return (_list);
}

bool				FruitBox::putFruit(Fruit* fruit)
{
  FruitNode*			tmp;
  FruitNode*			elem;

  if (_nb >= _size)
    return (false);
  elem = new FruitNode();
  elem->fruit = fruit;
  tmp = _list;
  if (_list == NULL)
    _list = elem;
  else
    {
      while (tmp->next != NULL)
	{
	  if (tmp->fruit == fruit)
	    return (false);
	  tmp = tmp->next;
	}
      tmp->next = elem;
    }
  _nb++;
  return (true);
}

Fruit*				 FruitBox::pickFruit()
{
  FruitNode*			tmp;
  Fruit*			fruit;
	
  if (_nb == 0)
    return (NULL);
  fruit = _list->fruit;
  tmp = _list->next;
  delete _list;
  _list = tmp;
  _nb--;
  return (fruit);
}
