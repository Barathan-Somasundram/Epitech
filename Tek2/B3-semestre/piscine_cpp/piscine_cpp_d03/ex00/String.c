/*
** String.c for String in /home/somasu_b/rendu/piscine_cpp_d03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 10:14:26 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 10:55:45 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

void	StringInit(String *this, char const *s)
{
  this->str = NULL;
  if ((this->str = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return;
  strcpy(this->str, s);
}

void	StringDestroy(String *this)
{
  free(this->str);
  this->str = NULL;
}
