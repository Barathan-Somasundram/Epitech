/*
** my_string2.c for lem_in in /home/somasu_b/rendu/prog_elem/somasu_b/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Apr 22 21:58:43 2014 somasu_b
** Last update Sat May  3 13:04:35 2014 song_k
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(const char *str)
{
  return (str ? (*str ? my_strlen(str + 1) + 1 : 0) : 0);
}

int	my_strncmp(const char *s1, const char *s2, const int n)
{
  int	i;

  i = 0;
  if (!s1 && s2)
    return (0 - s2[0]);
  else if (s1 && !s2)
    return (s1[0]);
  while ((s1 && s2) && (s1[i] || s2[i]))
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      ++i;
      if (i == n)
	return (0);
    }
  return (0);
}

char	*my_strdup(const char *str)
{
  char	*new;
  int	i;

  if (!str || (new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = -1;
  while (str && str[++i])
    new[i] = str[i];
  new[i] = '\0';
  return (new);
}

char	*my_realloc(char *s1, char *s2)
{
  char	*new;
  int	i;
  int	j;

  i = -1;
  j = 0;
  new = malloc(sizeof(*new) * (my_strlen(s1) + my_strlen(s2) + 1));
  if (new == NULL)
    return (NULL);
  while (s1 && s1[++i])
    new[i] = s1[i];
  free(s1);
  while (s2 && s2[j])
    new[i++] = s2[j++];
  new[i] = '\0';
  return (new);
}

int	my_isnum(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	return (i);
      ++i;
    }
  return (-1);
}
