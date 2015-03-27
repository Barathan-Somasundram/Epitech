/*
** main.c for  in /home/somasu_b
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 14:07:41 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:40:07 2015 SOMASUNDRAM Barathan
*/

#include <stdio.h>
#include <string.h>
#include "elcrypt.h"

t_b64			my_pow(t_b64 a, int power)
{
  t_b64			nb;
  int			i;

  nb = 1;
  i = 0;
  while (i < power)
    {
      nb *= a;
      i++;
    }
  return (nb);
}

t_b64			get_nbr_ascii(char* str)
{
  t_b64			res;
  int			nb_base;
  int			i;
  int			k;

  res = 0;
  i = strlen(str);
  nb_base = 128;
  k = 0;
  while (--i >= 0)
    {
      res = res + str[i] * my_pow(nb_base, k);
      ++k;
    }
  return (res);
}

t_b64			getnbr_base(char* str, char* base)
{
  t_b64			res;
  int			nb_base;
  int			i;
  int			j;
  int			k;

  printf("%s <=> %s\n", str, base);
  if (strcmp(base , "ASCII") == 0)
    return (get_nbr_ascii(str));
  res = 0;
  i = strlen(str);
  nb_base = strlen(base);
  k = 0;
  while (--i >= 0)
    {
      j = 0;
      while (base[j] && base[j] != str[i])
	++j;
      if (base[j] == '\0')
	return (-1);
      res = res + j * my_pow(nb_base, k);
      printf("=> %ld\n", res);
      ++k;
    }
  return (res);
}

int			check_base(char* key)
{
  int			i;

  while (key[++i])
    if (!(key[i] >= '0' && key[i] <= '9'))
      return (0);
  return (1);
}

char*			get_base(char* key)
{
  char*			base;

  if (key[0] == '0' && key[1] == 'x')
    base = HEXADECIMAL1;
  else if (key[0] == '%')
    base = BINAIRE;
  else if (check_base(key) == 1)
    base = DECIMAL;
  else
    base = ASCII;
  return (base);
}
