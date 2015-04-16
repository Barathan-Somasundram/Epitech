/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 21:18:40 2013 a
** Last update Wed Dec 18 23:32:43 2013 a
*/

#include "../includes/my_lib.h"

static int	my_count_word(char *str, char s)
{
  int		count;
  int		i;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == s || str[i] == '\t')
	{
	  while ((str[i] == s || str[i] == '\t') && str[i + 1] != '\0')
	    i = i + 1;
	  count = count + 1;
	}
      i = i + 1;
    }
  return (count);
}

static int	word_len(char *str, char s)
{
  int		len;

  len = 0;
  while (str[len] != s && str[len] != '\0')
    len = len + 1;
  return (len);
}

static char	**my_malloc_tab(char **tab, char *str, char s)
{
  int		count_word;
  int		y;
  int		i;

  count_word = my_count_word(str, s);
  y = 0;
  i = 0;
  if ((tab = malloc(sizeof(char*) * count_word + 2)) == NULL)
    return (NULL);
  while (y < count_word + 1)
    {
      if ((tab[y] = malloc(sizeof(char) * word_len(&str[i], s) + 1)) == NULL)
	return (NULL);
      i = i + word_len(&str[i], s);
      y = y + 1;
    }
  tab[count_word + 1] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str, char s)
{
  char	**tab;
  int	i;
  int	y;
  int	x;
  int	tmp;

  i = 0;
  y = 0;
  if ((tab = my_malloc_tab(tab, str, s)) == NULL)
    return (NULL);
  while (y < (my_count_word(str, s) + 1))
    {
      x = 0;
      tmp = i + word_len(&str[i], s);
      while (i < tmp)
      	{
      	  tab[y][x] = str[i];
      	  x = x + 1;
      	  i = i + 1;
      	}
      tab[y][x] = '\0';
      i = i + 1;
      y = y + 1;
    }
  return (tab);
}
