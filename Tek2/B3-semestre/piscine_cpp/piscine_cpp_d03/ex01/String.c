/*
** String.c for String in /home/somasu_b/rendu/piscine_cpp_d03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 10:14:26 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 11:43:00 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"


static void	assign_s(String *this, String const *str)
{
  if (this == NULL)
    return;
  if (str == NULL || str->str == NULL)
    return;
  if (this->str)
    free(this->str);
  if ((this->str = malloc(sizeof(char) * (strlen(str->str) + 1))) == NULL)
    return;
  strcpy(this->str, str->str);
}

static void	assign_c(String *this, char const *s)
{
  if (this == NULL)
    return ;
  if (this->str != NULL)
    free(this->str);
  this->str = NULL;
  if (s == NULL)
    return;
  if ((this->str = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return;
  strcpy(this->str, s);
}

void	StringInit(String *this, char const *s)
{
  this->str = NULL;
  if ((this->str = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
    return;
  strcpy(this->str, s);
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
}

void	StringDestroy(String *this)
{
  free(this->str);
  this->str = NULL;
}
