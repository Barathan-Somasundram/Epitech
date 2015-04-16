/*
** texture.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Feb  4 21:45:47 2014 somasu_b
** Last update Sun Feb 16 21:33:32 2014 a
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "../../includes/bonus.h"

static int	texture(char *directory)
{
  char		*buffer;
  int		fd;

  if ((fd = open(directory, O_RDONLY)) == -1)
    return (-1);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      my_putstr(buffer);
      my_putstr("\n");
      free(buffer);
    }
  if ((close(fd)) == -1)
    return (-1);
  return (0);
}

int	opening(void)
{
  my_putstr(B_RED);
  if (texture("./texture/open.txt") == -1)
    return (-1);
  my_putstr(NORMAL);
  if (my_getchar() == -1)
    return (-1);
  return (0);
}

int	menu_bg(void)
{
  my_putstr(S_YELLOW);
  if (texture("./texture/menu.txt") == -1)
    return (-1);
  my_putstr(NORMAL);
  return (0);
}

int	i_lost(void)
{
  my_putstr(B_CYAN);
  if (texture("./texture/lost.txt") == -1)
    return (-1);
  my_putstr(NORMAL);
  return (0);
}

int	i_win(void)
{
  my_putstr(B_MAGENTA);
  if (texture("./texture/win.txt") == -1)
    return (-1);
  my_putstr(NORMAL);
  return (0);
}
