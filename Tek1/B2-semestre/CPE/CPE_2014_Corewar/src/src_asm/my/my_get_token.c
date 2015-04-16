/*
** my_get_token.c for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 18:58:50 2014 taille_a
** Last update Sun Apr 13 13:03:12 2014 taille_a
*/

#include <stdlib.h>
#include "op.h"

static char	*my_strncpy(char *dest, char *src,
			    int n, int i)
{
  int		cpt;

  cpt = 0;
  while (n < i && src[n])
    {
      dest[cpt] = src[n];
      ++cpt;
      ++n;
    }
  dest[cpt] = '\0';
  return (dest);
}

char		*my_get_token(char *buffer, int *i)
{
  int		cpt;
  char		*token;

  while ((buffer[(*i)] == '\t' ||
	  buffer[(*i)] == ' ') && buffer[(*i)] != '\0')
    ++(*i);
  cpt = *i;
  while (buffer[(*i)] != ' ' && buffer[(*i)] != '\t' &&
	 buffer[(*i)] != SEPARATOR_CHAR && buffer[(*i)] != '\0')
    ++(*i);
  if ((token = malloc(sizeof(char) * ((*i) - cpt) + 1)) == NULL)
    return (NULL);
  token = my_strncpy(token, buffer, cpt, *i);
  while ((buffer[(*i)] == ',' || buffer[(*i)] == ' ') && buffer[(*i)])
    ++(*i);
  return (token);
}
