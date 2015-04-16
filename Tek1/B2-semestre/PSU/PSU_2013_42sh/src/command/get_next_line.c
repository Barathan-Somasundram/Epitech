/*
** get_next_line.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed May 14 23:45:38 2014 somasu_b
** Last update Thu May 29 21:54:28 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

static int	gnl_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i++] != '\0');
  return (i);
}

static char	*strcat_buff(char *buffer, char *str)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  while (buffer[i] && buffer[i] != '\n')
    i = i + 1;
  while (buffer[i] == '\n')
    i = i + 1;
  while (buffer[i])
    buffer[n++] = buffer[i++];
  buffer[n] = '\0';
  return (str);
}

static char	*begin(char *buffer, int *i)
{
  int		n;
  char		*str;

  n = 0;
  if ((str = malloc(sizeof(*buffer) * (gnl_strlen(buffer) + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (buffer[*i] && buffer[*i] != '\n')
    {
      str[n++] = buffer[*i];
      *i = *i + 1;
    }
  str[n] = '\0';
  return (str);
}

static char	*make_line(char *buffer, char *str, int *i)
{
  int		n;
  char		*str2;

  n = 0;
  str2 = malloc(sizeof(*str) * gnl_strlen(buffer) + gnl_strlen(str) + 1);
  if (str2 == NULL)
    return (NULL);
  while (str[n])
    {
      str2[n] =  str[n];
      ++n;
    }
  while (buffer[*i] && buffer[*i] != '\n')
    {
      str2[n++] = buffer[*i];
      *i = *i + 1;
    }
  str2[n] = '\0';
  free(str);
  return (str2);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUF_LEN + 1];
  char		*str;
  int		i;
  int		ret;

  i = 0;
  if ((str = begin(buffer, &i)) == NULL)
    return (NULL);
  if (buffer[i] == '\n')
    return (strcat_buff(buffer, str));
  while ((ret = read(fd, buffer, BUF_LEN)) > 0)
    {
      i = 0;
      buffer[ret] = '\0';
      if ((str = make_line(buffer, str, &i)) == NULL)
	return (NULL);
      if (buffer[i] == '\n')
	return (strcat_buff(buffer, str));
    }
  if (ret <= 0)
    return (NULL);
  buffer[ret] = '\0';
  if (ret == 0 && str == NULL)
    return (NULL);
  return (str);
}
