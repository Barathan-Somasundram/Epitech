/*
** my_string_evol.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 14:59:42 2014 somasu_b
** Last update Mon Mar  3 18:02:34 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1)))
      == NULL)
    return (NULL);
  i = 0;
  while (dest[i] != '\0')
    new[i] = dest[i++];
  j = 0;
  while (src[j] != '\0')
    new[i++] = src[j++];
  new[i] = '\0';
  return (new);
}

int	my_strcmp(char *s1, char *s2)
{
  int	count;

  count = 0;
  if (!s1 || !s2)
    return (-1);
  while ((s1[count] == s2[count]) && (s1[count] != '\0' || s2[count] != '\0'))
    count++;
  return (s1[count] - s2[count]);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	count;

  count = 0;
  if (!s1 || !s2)
    return (-1);
  while (count < n &&(s1[count] == s2[count])
	 && (s1[count] != '\0' || s2[count] != '\0'))
    count++;
  return (s1[count] - s2[count]);
}

static char	*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] != '\0')
    dest[i] = src[i++];
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  if ((new = my_strcpy(new, str)) == NULL)
    return (NULL);
  return (new);
}
