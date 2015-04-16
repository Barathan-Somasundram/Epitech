/*
** get_next_line.c for get_next_line in /home/gauvai_b/rendu/libmy
**
** Made by gauvai_b
** Login   <gauvai_b@epitech.net>
**
** Started on  Tue Dec  3 19:07:10 2013 gauvai_b
** Last update Sun Feb 16 21:27:10 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../../includes/bonus.h"

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i++] != '\0');
  return (i);
}

static char	*stock_buf(char *buf, char *str)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  while (buf[i] && buf[i] != '\n')
    ++i;
  while (buf[i] == '\n')
    ++i;
  while (buf[i])
    buf[n++] = buf[i++];
  buf[n] = '\0';
  return (str);
}

static char	*begin(char *buf, int *i)
{
  int		j;
  char		*str;

  j = 0;
  if ((str = malloc(sizeof(*buf) * (my_strlen(buf) + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (buf[*i] && buf[*i] != '\n')
    {
      str[j++] = buf[*i];
      *i = *i + 1;
    }
  str[j] = '\0';
  return (str);
}

static char	*make_line(char *buf, char *str, int *i)
{
  int		n;
  char		*line;

  n = 0;
  line = malloc(sizeof(*str) * my_strlen(buf) + my_strlen(str) + 1);
  if (line == NULL)
    return (NULL);
  while (str[n])
    line[n] =  str[n++];
  while (buf[*i] && buf[*i] != '\n')
    {
      line[n++] = buf[*i];
      *i = *i + 1;
    }
  line[n] = '\0';
  free(str);
  return (line);
}

char		*get_next_line(const int fd)
{
  static char	buf[BUF_LEN + 1];
  char		*str;
  int		i;
  int		ret;

  i = 0;
  if ((str = begin(buf, &i)) == NULL)
    return (NULL);
  if (buf[i] == '\n')
    return (stock_buf(buf, str));
  while ((ret = read(fd, buf, BUF_LEN)) > 0)
    {
      i = 0;
      buf[ret] = '\0';
      if ((str = make_line(buf, str, &i)) == NULL)
	return (NULL);
      if (buf[i] == '\n')
	return (stock_buf(buf, str));
    }
  if (ret <= 0)
    return (NULL);
  buf[ret] = '\0';
  if (ret == 0 && str == NULL)
    return (NULL);
  return (str);
}
