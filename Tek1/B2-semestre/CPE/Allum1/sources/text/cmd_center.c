/*
** cmd_center.c for alum-1 in /home/somasu_b/TEST/alum-1/sources/text
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri Feb  7 17:49:11 2014 somasu_b
** Last update Fri Feb  7 17:51:34 2014 somasu_b
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "game.h"

int	my_getchar(void)
{
  int	ret;
  char	s[1];

  if ((ret = read(0, &s, 1)) == -1)
    return (-1);
  return (0);
}

int	texture(char *directory)
{
  char	*buffer;
  int	fd;

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
}

static int	my_keycode_to_func(int keycode, t_menu **menu)
{
  if (keycode == ESCAPE)
    return (2);
  else if (keycode == UP)
    return (up(menu));
  else if (keycode == DOWN)
    return (down(menu));
  else if (keycode == LEFT)
    return (left(menu));
  else if (keycode == RIGHT)
    return (right(menu));
  else if (keycode == ENTER)
    return (1);
  return (0);
}

int	cmd_center(t_menu **menu)
{
  int	read_ret;
  int	keys_ret;
  int	keycode;

  my_clear_full_screen();
  if ((texture("../../texture/menu.txt")) == -1)
    return (-1);
  show_menu(menu);
  while ((read_ret = read(0, &keycode, 4)) != -1)
    {
      keys_ret = my_keycode_to_func(keycode, menu);
      keycode = 0;
      if (keys_ret == -1)
	return (-1);
      else if (keys_ret == 1)
	return (1);
      else if (keys_ret == 2)
	{
	  my_clear_full_screen();
	  return (2);
	}
      show_menu(menu);
    }
  return (0);
}
