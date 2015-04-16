/*
** my_fillinstr.c for fdf in /home/song_k/rendu/B1-IGraph/MUL_2013_fdf
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Mon Dec  2 18:36:24 2013 song_k
** Last update Sat May  3 19:08:14 2014 song_k
*/

#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

static int	checkread(char *str)
{
  static int	chk = 0;
  int		i;

  if (chk == 0)
    {
      i = -1;
      while (str[++i] == '-');
      while (str[++i] && str[i] >= '0' && str[i] <= '9');
      if (i == 0 || str[i] != '\n' || str[i] == '-')
	{
	  my_putstr(CHAR_ERR, 2);
	  return (-1);
	}
      chk = 1;
    }
  else
    {
      i = my_strlen(str);
      if (i > 2 && str[i - 1] == '\n' && str[i - 2] == '\n')
	{
	  my_putstr("Empty Line\n", 2);
	  return (-1);
	}
    }
  return (0);
}

/*
** char	*my_fillinstr(const int fd)
** {
**   char	buff[4096 + 1];
**   char	*stock;
**   int	chk_read;
**
**   stock = NULL;
**   chk_read = 1;
**   while (chk_read > 0)
**     {
**       if ((chk_read = read(fd, buff, 4096)) == -1)
** 	return (NULL);
**       buff[chk_read] = '\0';
**       if (stock == NULL && chk_read)
** 	stock = my_strdup(buff);
**       else if (chk_read > 0)
** 	stock = my_realloc(stock, buff);
**     }
**   if (stock == NULL)
**     my_putstr(EMPT_FIL, 2);
**   return (stock);
** }
*/

char	*my_fillinstr(const int fd)
{
  char	*stock;
  char	*buf;

  stock = NULL;
  while ((buf = get_next_line(fd)) != NULL)
    {
      if (buf[0] != '#' || (my_strcmp(buf, START_TAG) == 0)
	  || (my_strcmp(buf, END_TAG) == 0))
	{
	  if ((buf = my_realloc(buf, "\n")) == NULL)
	    return (NULL);
	  if (stock == NULL)
	    stock = my_strdup(buf);
	  else
	    stock = my_realloc(stock, buf);
	  if (stock == NULL)
	    return (NULL);
	  if (checkread(stock) == -1)
	    return (stock);
	}
    }
  if (stock == NULL)
    my_putstr(EMPT_FIL, 2);
  return (stock);
}
