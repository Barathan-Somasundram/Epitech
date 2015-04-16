/*
** my_string_base.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 14:35:05 2014 somasu_b
** Last update Mon Mar  3 18:02:48 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"

int	my_putchar(int c, int fd)
{
  write(fd, &c, 1);
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i++] != '\0');
  return (i);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      my_putchar(str[i++], STDOUT_FILENO);
  return (0);
}

int	my_puterror(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      my_putchar(str[i++], STDERR_FILENO);
  return (0);
}
