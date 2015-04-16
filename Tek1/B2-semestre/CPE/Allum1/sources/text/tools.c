/*
** tools.c for my_select in /home/somasu_b/TEST/select
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 18:49:23 2014 a
** Last update Tue Feb  4 13:23:25 2014 somasu_b
*/

#include "game.h"

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      i++;
  return (i);
}

static char	*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

static int	my_strncmp(char *s1, char *s2, int n)
{
  int		compare;

  compare = 0;
  if (!s1 || !s2)
    return (-1);
  while (compare < n && s1[compare] == s2[compare]
  	 && s1[compare] != '\0' && s2[compare] != '\0')
    compare = compare + 1;
  return (s1[compare] - s2[compare]);
}

char	*my_strdup(char *str)
{
  char	*new;

  if (str == NULL)
    return (NULL);
  if ((new = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  if ((new = my_strcpy(new, str)) == NULL)
    return (NULL);
  return (new);
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
	return (my_strdup(&env[i][5]));
      i = i + 1;
    }
  return (NULL);
}
