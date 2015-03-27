/*
** convert.c for  in /home/somasu_b/rendu/elcrypt/sources
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 18:15:26 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:46:16 2015 SOMASUNDRAM Barathan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "elcrypt.h"

char			*convert_char_bin(int c)
{
  int			nb;
  char			*oct;
  int			pos;

  if (c < 0)
    return (convert_char_bin(128 + (128 - (c * -1))));
  nb = c;
  if ((oct = malloc(9)) == NULL)
    return (NULL);
  pos = 7;
  oct[8] = 0;
  while (nb > 0)
    {
      oct[pos] = (nb % 2) + '0';
      nb = nb / 2;
      pos--;
    }
  while (pos >= 0)
    oct[pos--] = '0';
  return (oct);
}

char			*convert_big_nbr(t_b64 nbr)
{
  t_b64			nb;
  char			*oct;
  int			pos;

  nb = nbr;
  printf("KEY NBR => %ld\n", nbr);
  if ((oct = malloc(65)) == NULL)
    return (NULL);
  pos = 63;
  oct[64] = 0;
  while (nb > 0)
    {
      oct[pos] = (nb % 2) + '0';
      nb = nb / 2;
      pos--;
    }
  while (pos >= 0)
    oct[pos--] = '0';
  return (oct);
}

char			*convert_key_bin(t_b64 nbr)
{
  char			*bin_64;
  char			*bin_56;
  int			i;
  int			j;

  if ((bin_64 = convert_big_nbr(nbr)) == NULL)
    return (NULL);
  printf("KEY 64 => %s\n", bin_64);
  if ((bin_56 = malloc(57)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (i < 64 && j < 56)
    {
      if (i % 8 != 7)
	bin_56[j++] = bin_64[i];
      i++;
    }
  printf("KEY 56 => %s\n", bin_56);
  return (bin_56);
}

char			*convert_bin(char *key, int size_key)
{
  char			*bin;
  char			*oct;
  int			size;
  int			pos;

  size = size_key * 8;
  if ((bin = malloc(size + 1)) == NULL)
    return (NULL);
  bin[0] = 0;
  pos = 0;
  while (pos < size_key)
    {
      if ((oct = convert_char_bin(key[pos])) == NULL)
	return (NULL);
      bin = strcat(bin, oct);
      pos++;
    }
  return (bin);
}
