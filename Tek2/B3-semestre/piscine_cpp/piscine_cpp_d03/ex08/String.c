/*
** String.c for String in /home/somasu_b/rendu/piscine_cpp_d03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 10:14:26 2015 SOMASUNDRAM Barathan
** Last update Sat Jan 10 09:12:02 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

static char const*	c_str(String *this)
{
  if (this == NULL || this->str == NULL)
    return (NULL);
  return (this->str);
}

static size_t	copy(String *this, char *s, size_t n, size_t pos)
{
  int		i = 0;

  if (this == NULL || this->str == NULL)
    return (0);
  if (s == NULL)
    if ((s = malloc(sizeof(char) * (n + 1))) == NULL)
      return (0);
  if (pos > strlen(this->str))
    return (0);
  while (this->str[pos] && pos < n)
    {
      s[i] = this->str[pos];
      pos++;
      i++;
    }
  return (i);
}

static int	compare_s(String *this, const String *str)
{
  if (this == NULL && str == NULL)
    return (0);
  else if (this == NULL && str != NULL)
    if (str->str == NULL)
      return (0);
    else
      return (-(str->str[0]));
  else if (this != NULL && str == NULL)
    {
      if (this->str == NULL)
	return (0);
      else
	return (this->str[0]);
    }
  return (strcmp(this->str, str->str));
}

static int	compare_c(String *this, char const *str)
{
  if (this == NULL && str == NULL)
    return (0);
  else if (this == NULL && str != NULL)
    return (-(str[0]));
  else if (this != NULL && str == NULL)
    {
      if (this->str == NULL)
	return (0);
      else
	return (this->str[0]);
    }
  return (strcmp(this->str, str));
}

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
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
  this->copy = &copy;
  this->c_str = &c_str;
}

void	StringDestroy(String *this)
{
  free(this->str);
  this->str = NULL;
}
