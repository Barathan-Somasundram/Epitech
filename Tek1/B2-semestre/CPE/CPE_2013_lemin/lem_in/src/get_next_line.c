/*
** get_next_line.c for getnextline source in /home/somasu_b/rendu/CPE_2013_getnextline
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Nov 24 12:02:50 2013 a
** Last update Sat May  3 20:11:16 2014 song_k
*/

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

static char    	*my_gnl_strcat(char *dest, char *src)
{
  int		i;
  int		j;

  j = 0;
  i = -1;
  if (!dest || !src)
    return (NULL);
  while (dest[++i]);
  while (src[j])
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = 0;
  return (dest);
}

static char	*my_gnl_realloc(char *src, int ret_read)
{
  char          *dest;
  int		i;

  i = 0;
  if (!src)
    return (NULL);
  while (src[i++]);
  if (ret_read == 0)
    return (src);
  if ((dest = malloc((i + ret_read + 1) * sizeof(char))) == NULL)
    return (NULL);
  *dest = 0;
  if (my_gnl_strcat(dest, src) == NULL)
    return (NULL);
  free(src);
  return (dest);
}

static int	strcat_buffer(char *buffer, char *line)
{
  int           j;

  j = 0;
  if (!buffer || !line)
    return (-1);
  while (line[j] != 0)
    {
      if (line[j] == '\n')
        {
          line[j] = 0;
          *buffer = 0;
	  if (my_gnl_strcat(buffer, &line[j + 1]) == NULL)
	    return (-1);
          return (0);
        }
      j = j + 1;
    }
  *buffer = 0;
  return (1);
}

char            *get_next_line(const int fd)
{
  static char   buffer[BUF_LEN + 1];
  char          *unret;
  int           ret_read;
  int		i;

  unret = malloc((BUF_LEN + 1) * sizeof(char));
  if (unret == NULL || fd < 0)
    return (NULL);
  *unret = 0;
  if (my_gnl_strcat(unret, buffer) == NULL)
    return (NULL);
  *buffer = 0;
  ret_read = BUF_LEN;
  while ((i = strcat_buffer(buffer, unret)) > 0 && ret_read == BUF_LEN)
    {
      if ((ret_read = read(fd, buffer, BUF_LEN)) == -1)
	return (NULL);
      buffer[ret_read] = 0;
      if ((unret = my_gnl_realloc(unret, ret_read)) == NULL
	  || my_gnl_strcat(unret, buffer) == NULL)
	return (NULL);
    }
  if (*unret == 0 && my_strlen(buffer) == 0 && ret_read != BUF_LEN)
    return (NULL);
  return ((i == -1) ? NULL : unret);
}
