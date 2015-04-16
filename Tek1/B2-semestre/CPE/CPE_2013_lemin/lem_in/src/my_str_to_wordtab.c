/*
** my_str_to_wordtab.c for lib in /home/song_k/rendu
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Mon Feb 24 10:19:42 2014 song_k
** Last update Sun May  4 23:38:10 2014 a
*/

#include <stdlib.h>
#include "lemin.h"

static char	*my_replace_sep(char *str, char sep)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == sep)
	str[i] = '\0';
      ++i;
    }
  return (str);
}

static char	**my_malloc_wordtab(char *str, char sep, int *max)
{
  char		**wordtab;
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == sep)
	{
	  while (str[i] && str[i] == sep)
	    ++i;
	}
      if (str[i])
	{
	  ++(*max);
	  while (str[i] && str[i] != sep)
	    ++i;
	}
    }
  if ((wordtab = malloc(sizeof(char *) * (*max + 1))) == NULL)
    return (NULL);
  return (wordtab);
}

static char	**my_fillwordtab(char **wordtab, char *str, int max, int l)
{
  int		i;
  int		ct;

  i = 0;
  ct = 0;
  while (ct < max && i < l)
    {
      while (i < l && str[i] == '\0')
	++i;
      if (i < l)
	if ((wordtab[ct] = my_strdup(str + i)) == NULL)
	  return (NULL);
      ++ct;
      while (str[i] != '\0')
	++i;
    }
  wordtab[ct] = NULL;
  return (wordtab);
}

char		**my_str_to_wordtab(char *str, char sep)
{
  int		l;
  int		max;
  char		**wordtab;

  max = 0;
  l = 0;
  while (str && str[l])
    ++l;
  if ((wordtab = my_malloc_wordtab(str, sep, &max)) == NULL)
    return (NULL);
  str = my_replace_sep(str, sep);
  if ((wordtab = my_fillwordtab(wordtab, str, max, l)) == NULL)
    return (NULL);
  return (wordtab);
}
