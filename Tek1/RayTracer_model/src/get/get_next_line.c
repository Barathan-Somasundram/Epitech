/*
** get_next_line.c for get in /home/collio_v//local/Get_Next_Line
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu Nov 22 14:12:07 2012 vincent colliot
** Last update Sun May 26 03:31:50 2013 vincent colliot
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	test_nl(char *str)
{
  int	i;

  i = 0;
  while (i < SIZE_READ)
    if (str[i++] == '\n')
      return (1);
  return (0);
}

char	*init_pass(int w)
{
  char	*pass;
  int	i;

  i = 0;
  if ((pass = malloc(sizeof(*pass) * (w + 1))) == NULL)
    return (NULL);
  while (i < w + 1)
    pass[i++] = 0;
  return (pass);
}

void	inc(char *str1, char *str2, int i)
{
  str1[i] = str2[i];
}

void	memorize(int *w, char **buffer, char memory[])
{
  char	*pass;
  int	i;
  int	i2;

  i = 0;
  if ((pass = init_pass(*w)) == NULL)
    return ;
  if (*buffer)
    while (i < *w - SIZE_READ && (*buffer)[i])
      inc(pass, *buffer, i++);
  if (*buffer)
    free(*buffer);
  i2 = 0;
  while (i2 < SIZE_READ && memory[i2] != '\n')
    pass[i++] = memory[i2++];
  *buffer = pass;
  i = 0;
  if (!test_nl(memory))
    while (i < SIZE_READ)
      memory[i++] = '\0';
  else
    while (i2 < SIZE_READ)
      memory[i++] = memory[i2++];
  while (i < SIZE_READ)
    memory[i++] = '\0';
}

char	*get_next_line(const int fd)
{
  char		*buffer;
  static char	memory[SIZE_READ + 1];
  int		w;
  int		lr;

  w = 0;
  lr = SIZE_READ;
  buffer = NULL;
  while ((!test_nl(memory) || !w) && lr == SIZE_READ)
    {
      if (!memory[0])
	if ((lr = read(fd, memory, SIZE_READ)) <= 0 && w == 0)
	  return (NULL);
      w = w + SIZE_READ;
      memorize(&w, &buffer, memory);
      if (buffer == NULL)
	return (NULL);
    }
  w = 0;
  lr = 1;
  while (w + 1 < SIZE_READ && memory[w])
    memory[w++] = memory[lr++];
  memory[w] = '\0';
  return (buffer);
}
