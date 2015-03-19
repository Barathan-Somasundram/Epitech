/*
** new.c for  in /home/llyth/Workstation/Rush1/ex_01
**
** Made by llyth
** Login   <llyth@epitech.net>
**
** Started on  Sat Jan 10 10:03:33 2015 llyth
** Last update Sat Jan 10 14:21:24 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h> 
#include "new.h" 
#include "object.h" 
#include "raise.h" 
#include "point.h"

void* new(Class* class) 
{
  Object *objet;

  if ((objet = malloc(sizeof(class->__size__))) == NULL)
    raise("Cannot allocate memory.");
  class->__init__(objet);
  return (objet);
}

void delete(Object* ptr) 
{ 
  if (ptr == NULL) 
    return ;  
  free(ptr);
  Point->__del__(ptr); 
}
