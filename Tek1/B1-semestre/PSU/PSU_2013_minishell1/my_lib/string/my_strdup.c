/*
** my_strdup.c for my_strdup.c in /home/somasu_b/Desktop/my_lib
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 22:25:23 2013 a
** Last update Wed Dec 18 22:31:54 2013 a
*/

#include "../includes/my_lib.h"

char	*my_strdup(char *str)
{
  char	*new;

  if ((new = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  if ((new = my_strcpy(new, str)) == NULL)
    return (NULL);
  return (new);
}
