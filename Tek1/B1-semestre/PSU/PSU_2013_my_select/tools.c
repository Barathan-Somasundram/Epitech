/*
** tools.c for my_select in /home/somasu_b/TEST/select
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 18:49:23 2014 a
** Last update Sat Jan 18 19:18:55 2014 a
*/

#include "my_select.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	compare;

  compare = 0;
  if (!s1 || !s2)
    return (-1);
  while (compare < n && s1[compare] == s2[compare]
  	 && s1[compare] != '\0' && s2[compare] != '\0')
    compare = compare + 1;
  return (s1[compare] - s2[compare]);
}

char	*my_get_term(char **env)
{
  int	i;

  i = 0;
  if (env == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "TERM=", 4) == 0)
	return (&env[i][5]);
      i = i + 1;
    }
  return (NULL);
}
