/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/somasu_b/rendu/PSU_2013_minishell1/te
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Dec 19 17:44:36 2013 a
** Last update Mon Jan  6 10:19:24 2014 a
*/

#include "my_lib/includes/my_lib.h"

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
	  while (str[i] == s || str[i] == '\t')
	    i = i + 1;
	  count = count + 1;
	}
      i = i + 1;
    }
  return (count + 1);
}

char	**my_copy(char *new_str, char **tab, char s, int i)
{
  int	y;

  y = 0;
  while (new_str[i] != '\0')
    {
      tab[y] = &new_str[i];
      while (new_str[i] != s && new_str[i] != '\0')
	i = i + 1;
      while (new_str[i] != '\0' && (new_str[i] == s || new_str[i] == '\t'))
	i = i + 1;
      y = y + 1;
    }
  tab[y] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str, char s)
{
  int	count_word;
  int	i;
  int	y;
  char	*new_str;
  char	**tab;

  count_word = my_count_word(str, s);
  i = 0;
  y = 0;
  if ((new_str = my_strdup(str)) == NULL)
    return (NULL);
  if ((tab = malloc(sizeof(char*) * (count_word + 1))) == NULL)
    return (NULL);
  tab = my_copy(new_str, tab, s, i);
  i = 0;
  while (new_str[i] != '\0')
    {
      if (new_str[i] == s || new_str[i] == '\t')
	new_str[i] = '\0';
      i = i + 1;
    }
  return (tab);
}
