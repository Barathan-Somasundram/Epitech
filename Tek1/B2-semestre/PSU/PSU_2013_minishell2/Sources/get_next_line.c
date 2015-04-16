/*
** get_next_line.c for get_next_line in /home/gauvai_b/rendu/libmy
**
** Made by gauvai_b
** Login   <gauvai_b@epitech.net>
**
** Started on  Tue Dec  3 19:07:10 2013 gauvai_b
** Last update Mon Mar  3 18:06:51 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../Includes/mysh.h"

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i++] != '\0');
  return (i);
}

static char	*put_buff(char *buffer, char *str)
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

static char	*start(char *buffer, int *i)
{
  int		n;
  char		*str;

  n = 0;
  if ((str = malloc(sizeof(*buffer) * (my_strlen(buffer) + 1))) == NULL)
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

static char	*buffer_to_str(char *buffer, char *str, int *i)
{
  int		n;
  char		*str2;

  n = 0;
  str2 = malloc(sizeof(*str) * my_strlen(buffer) + my_strlen(str) + 1);
  if (str2 == NULL)
    return (NULL);
  while (str[n])
    str2[n] =  str[n++];
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
  if ((str = start(buffer, &i)) == NULL)
    return (NULL);
  if (buffer[i] == '\n')
    return (put_buff(buffer, str));
  while ((ret = read(fd, buffer, BUF_LEN)) > 0)
    {
      i = 0;
      buffer[ret] = '\0';
      if ((str = buffer_to_str(buffer, str, &i)) == NULL)
	return (NULL);
      if (buffer[i] == '\n')
	return (put_buff(buffer, str));
    }
  if (ret <= 0)
    return (NULL);
  buffer[ret] = '\0';
  if (ret == 0 && str == NULL)
    return (NULL);
  return (str);
}
