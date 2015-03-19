/*
** String.c for String in /home/somasu_b/rendu/piscine_cpp_d03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 10:14:26 2015 SOMASUNDRAM Barathan
** Last update Sat Jan 10 09:02:46 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

static int	size(String *this)
{
  if (this == NULL || this->str == NULL)
    return (-1);
  return (strlen(this->str));
}

static void	clear(String *this)
{
  int		i = -1;

  if (this == NULL || this->str == NULL)
    return;
  while (this->str[++i])
    this->str[i] = '\0';
}

static char	at(String *this, size_t pos)
{
  if (this == NULL || this->str == NULL)
    return (-1);
  if (strlen(this->str) < pos)
    return (-1);
  return (this->str[pos]);
}

static void	append_s(String *this, String const *ap)
{
  char		*tmp = NULL;

  if (this == NULL || ap == NULL)
    return;
  if (this->str == NULL || ap->str == NULL)
    return;
  if ((tmp = strdup(this->str)) == NULL)
    return;
  free(this->str);
  if ((this->str = malloc(sizeof(char) * (strlen(tmp) + strlen(ap->str) + 1)))
      == NULL)
    return;
  this->str[0] = '\0';
  strcat(this->str, tmp);
  strcat(this->str, ap->str);
  free(tmp);
}

static void	append_c(String *this, char const *ap)
{
  char		*tmp = NULL;

  if (this == NULL)
    return;
  if (this->str == NULL || ap == NULL)
    return;
  if ((tmp = strdup(this->str)) == NULL)
    return;
  free(this->str);
  if ((this->str = malloc(sizeof(char) * (strlen(tmp) + strlen(ap) + 1)))
      == NULL)
    return;
  this->str[0] = '\0';
  strcat(this->str, tmp);
  strcat(this->str, ap);
  free(tmp);  
}

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
  this->append_s = &append_s;
  this->append_c = &append_c;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
}

void	StringDestroy(String *this)
{
  free(this->str);
  this->str = NULL;
}
