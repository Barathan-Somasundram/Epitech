/*
** get_next_line.c for get_next_line in /home/somasu_b
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Nov 23 14:34:30 2013 a
** Last update Sun Nov 24 18:43:23 2013 a
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[j] != '\0')
    j = j + 1;
  dest[j] = ' ';
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      j = j + 1;
      i = i + 1;
    }
  dest[j] = '\0';
  return (dest);
}

char	*my_realloc(char *str, int alloc)
{
  int	length;
  char	*str2;

  while (str[length] != '\0')
    length = length + 1;
  str2 = malloc(sizeof(char) * (length + alloc));
  str2[0] = 0;
  str2 = my_strcat(str2, str);
  return (str2);
}

int	check_buffer(char *buffer)
{
  int	count;
  int	i;

  count = 0;
  i = 0;
  while (buffer[i] != 0)
    {
      if (buffer[i] == 10)
	count = count + 1;
      i = i + 1;
    }
  return (count);
}

char	*make_line(int *h, char **unret)
{
  char	*line;
  int	n;
  int	j;

  n = 0;
  j = 0;
  if (*h > 0)
    {
      j = 0;
      n = 0;
      while ((*unret)[n] != '\n' && (*unret)[n] != '\0')
	n = n + 1;
      line = malloc(sizeof(char) * n + 1);
      if (line == NULL)
	return (NULL);
      while (j < n)
	{
	  line[j] = (*unret)[j];
	  j = j + 1;
	}
      line[j] = 0;
      (*unret) = &(*unret)[j + 1];
    }
  *h = *h - 1;
  return (line);
}

char		*get_next_line(const int fd)
{
  static char	*unret;
  static int	k = -1;
  static int	h = 0;
  char		buffer[BUF_LEN + 1];

  if (h == 0)
    {
      unret = malloc(sizeof(char) * BUF_LEN + 1);
      if (unret == NULL)
	return (NULL);
      unret[0] = 0;
      k = 1;
    }
  while (k > 0 && h == 0)
    {
      k = read(fd, buffer, BUF_LEN);
      if (k < 1)
	return (NULL);
      buffer[k] = 0;
      unret = my_strcat(unret, buffer);
      h = check_buffer(buffer);
      if (h == 0)
	unret = my_realloc(unret, BUF_LEN);
    }
  return (make_line(&h, &unret));
}
