/*
** my_read.c for asm in /home/potierg/rendu/corewar
** 
** Made by potier_g
** potier_g   <potierg@epitech.net>
** 
** Started on  Wed Mar 26 22:38:46 2014 potier_g
** Last update Sun May  4 19:39:29 2014 potier_g
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int	my_strlen(char *str)
{
  int	pos;

  pos = 0;
  if (str == NULL)
    return (-1);
  while (str[pos] != '\0')
    pos++;
  return (pos);
}

void	*my_alloc(int size)
{
  void	*str;

  if ((str = malloc(size)) == NULL)
    {
      write(2, "malloc error\n", 13);
      return (NULL);
    }
  return (str);
}

char	*my_malloc(int size)
{
  char	*str;

  if ((str = malloc(size)) == NULL)
    {
      write(2, "malloc error\n", 13);
      return (NULL);
    }
  return (str);
}

char	*my_strcat(char *str, char *tmp)
{
  char	*new;
  int	a;
  int	b;

  if ((new = malloc(my_strlen(str) + my_strlen(tmp) + 1)) == NULL)
    return (NULL);
  a = 0;
  b = 0;
  while (str[a] != '\0')
    {
      if (detect_char_null(str[a]) == 1)
	return (NULL);
      new[b++] = str[a++];
    }
  while (tmp[a] != '\0')
    new[b++] = tmp[a++];
  new[b] = '\0';
  return (new);
}

char	*my_read()
{
  char	*str;
  char	*tmp;
  int	len;
  int	buff;

  buff = 1024;
  if ((str = malloc(1)) == NULL)
    return (NULL);
  else if ((tmp = malloc(buff + 1)) == NULL)
    return (NULL);
  str[0] = 0;
  while (42)
    {
      if ((len = read(0, tmp, buff)) <= 0)
	return (str);
      tmp[len] = '\0';
      if ((str = my_strcat(str, tmp)) == NULL)
	return (NULL);
    }
  return (NULL);
}
