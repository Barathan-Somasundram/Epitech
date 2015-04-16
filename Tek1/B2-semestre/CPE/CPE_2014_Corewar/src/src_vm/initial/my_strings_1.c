/*
** my_strings.c for corewar in /home/somasu_b/rendu/corewar/VM/retcode/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Mar 31 10:42:22 2014 somasu_b
** Last update Sun Apr 13 18:04:59 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_strings.h"

int	my_putchar(const int fd, const int c)
{
  if (write(fd, &c, 1) == -1)
    return (-1);
  return (0);
}

int	my_putstr(const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      my_putchar(STDOUT_FILENO, str[i++]);
  return (0);
}

int	my_perror(const char *error1, const char *error2)
{
  int	i;

  i = 0;
  if (error1 != NULL)
    while (error1[i] != '\0')
      my_putchar(STDERR_FILENO, error1[i++]);
  if (error2 != NULL)
    while (error2[i] != '\0')
      my_putchar(STDERR_FILENO, error2[i++]);
  if (error2 != NULL)
    my_putchar(STDERR_FILENO, '\n');
  return (-1);
}

int	my_strcmp(const char *s1, const char *s2)
{
  int	compare;

  compare = 0;
  while (s1[compare] != '\0' && s2[compare] != '\0'
	 && s1[compare] == s2[compare])
    ++compare;
  return (s1[compare] - s2[compare]);
}

char	*my_strdup(const char *str)
{
  char	*new;
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    ++i;
  if ((new = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      new[i] = str[i];
      ++i;
    }
  new[i] = '\0';
  return (new);
}
