/*
** my_strdup.c for my_strdup.c in /home/somasu_b/rendu/PSU_2013_minishell1/te
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Dec 19 17:45:28 2013 a
** Last update Thu Dec 19 18:24:03 2013 a
*/

#include "my_lib/includes/my_lib.h"

char	*my_strdup(char *src)
{
  int	length;
  int	i;
  char	*new_src;

  if (src == NULL)
    return (NULL);
  length = my_strlen(src);
  i = 0;
  if ((new_src = malloc(sizeof(char) * (length + 1))) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      new_src[i] = src[i];
      i = i + 1;
    }
  new_src[i] = '\0';
  return (new_src);
}
