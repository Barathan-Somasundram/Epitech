/*
** rotate.c for  in /home/somasu_b/rendu/elcrypt
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 18:41:26 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:46:34 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "elcrypt.h"

static char*		get_last32(char* key)
{
  char*		last32;

  if ((last32 = strdup(&key[24])) == NULL)
    return (NULL);
  free(key);
  return (last32);
}

static void		put_last4(char** key, char bits[4], int ite[3])
{
  ite[0] = 0;
  while (ite[0] < 4)
    {
      (*key)[ite[1]] = bits[ite[0]];
      ite[0]++;
      ite[1]++;
    }
}

char			*rotate_key(char *key, int turn)
{
  char*		tmp;
  char		bits[4];
  int		ite[3];

  if ((tmp = strdup(key)) == NULL)
    return (NULL);
  ite[2] = -1;
  while (++(ite[2]) < turn + 1)
    {
      ite[0] = 0;
      ite[1] = 0;
      while (tmp[ite[0]] != '\0')
	{
	  if (ite[0] < 4)
	    bits[ite[0]] = tmp[ite[0]];
	  else
	    {
	      tmp[ite[1]] = tmp[ite[0]];
	      ++(ite[1]);
	    }
	  ++(ite[0]);
	}
      put_last4(&tmp, bits, ite);
    }
  return (get_last32(tmp));
}

static int		bin_to_dec(char* bin)
{
  int			dec;
  int			i;
  int			j;

  dec = 0;
  i = strlen(bin) - 1;
  j = 0;
  while (i >= 0)
    {
      dec += (bin[i] - '0') *  my_pow(2, j);
      ++j;
      --i;
    }
  return (dec);
}

char			*bin32_to_string(char* bin)
{
  char*			str;
  char*			tmp;
  int			i;

  if ((str = malloc(sizeof(char) * 5)) == NULL)
    return (NULL);
  i = 0;
  while (i < 4)
    {
      tmp = strndup(bin, 8);
      str[i] = bin_to_dec(tmp);
      free(tmp);
      bin += 8;
      ++i;
    }
  str[i] = '\0';
  return (str);
}
