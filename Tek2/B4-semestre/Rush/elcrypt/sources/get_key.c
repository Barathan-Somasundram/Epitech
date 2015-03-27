/*
** get_kay.c for  in /home/somasu_b/rendu/elcrypt/sources
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 18:31:59 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:35:30 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "elcrypt.h"

t_b64			get_key(char* key)
{
  t_b64			key_dec;
  char*			base;
  int			i;

  if ((base = get_base(key)) == NULL)
    return (-1);
  if (strcmp(base, HEXADECIMAL1) == 0 || strcmp(base, HEXADECIMAL2) == 0)
    i = 2;
  else if (strcmp(base, BINAIRE) == 0)
    i = 1;
  else if (strcmp(base, DECI_ASCII) == 0)
    i = 0;
  if ((key_dec = getnbr_base(key + i, base)) == -1)
    return (-1);
  if (key_dec == -1 && strcmp(base, HEXADECIMAL1) == 0)
    if ((key_dec = getnbr_base(key + i, HEXADECIMAL2)) == -1)
      return (-1);
  return (key_dec);
}
