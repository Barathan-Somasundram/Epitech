/*
** get_next_line.c for get_next_line in /home/taille_a/Travail/getnext_line$/TP1
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Nov 21 12:34:40 2013 taille_a
** Last update Sun Apr 13 18:09:35 2014 somasu_b
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void		empty_buff(char *buffer, int and, int *cursor)
{
  int		i;

  i = 0;
  if (and == 0)
    while (i < BUFFSIZE)
      buffer[i++] = '\0';
  if (and == 1)
    if (buffer[(*cursor)] == '\n')
      (*cursor)++;
}

void		verif_buffer(char *buffer, char *str,
			     int *cursor, int *back)
{
  int		i;

  i = 0;
  *back = 0;
  while (buffer[*cursor] != '\0' && buffer[*cursor] != '\n')
    {
      str[*back] = buffer[*cursor];
      (*back)++;
      (*cursor)++;
    }
  if (buffer[*cursor] != '\n')
    {
      while (i < BUFFSIZE)
	buffer[i++] = '\0';
      *cursor = 0;
    }
}

char		*my_realloc(char *line, int util)
{
  char		*tmp;
  int		i;

  i = 0;
  if ((tmp = malloc(sizeof(char) * (BUFFSIZE * (util)))) == NULL)
    return (NULL);
  while (line[i] != '\0')
    {
      tmp[i] = line[i];
      i++;
    }
  tmp[i] = '\0';
  free(line);
  if ((line = malloc(sizeof(*line) * BUFFSIZE * ((util)))) == NULL)
    return (NULL);
  i = 0;
  while (tmp[i])
    {
      line[i] = tmp[i];
      i++;
    }
  line[i] = '\0';
  free(tmp);
  return (line);
}

void		fusion_str(char *line, char *buff,
			   int *back, int *cursor)
{
  *cursor = 0;
  while (buff[(*cursor)] != '\0' && buff[(*cursor)] != '\n')
    {
      line[*back] = buff[*cursor];
      (*back)++;
      (*cursor)++;
    }
  if (buff[*cursor] == '\0')
    empty_buff(buff, 0, cursor);
}

char		*get_next_line(const int fd)
{
  static char	buf[BUFFSIZE];
  t_cursor	cpt;
  static int	crs = 0;
  char		*line;

  cpt.util = 0;
  if ((line = malloc(sizeof(*line) * BUFFSIZE)) == NULL)
    return (NULL);
  line[0] = '\0';
  verif_buffer(buf, line, &crs, &cpt.back);
  cpt.save = 1;
  while (buf[crs] != '\n' &&  cpt.save != 0)
    {
      if ((cpt.save = read(fd, buf, BUFFSIZE - 1)) == -1)
	return (NULL);
      buf[cpt.save] = '\0';
      if ((line = my_realloc(line, ++cpt.util)) == NULL)
	return (NULL);
      fusion_str(line, buf, &cpt.back, &crs);
    }
  empty_buff(buf, 1, &crs);
  if (cpt.save == 0 && crs == 0 && cpt.back == 0)
    return (NULL);
  line[cpt.back] = '\0';
  return (line);
}
