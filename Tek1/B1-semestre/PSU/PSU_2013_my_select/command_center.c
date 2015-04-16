/*
** command_center.c for my_select in /home/somasu_b/TEST/select
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 13:57:42 2014 somasu_b
** Last update Sun Jan 19 21:23:59 2014 a
*/

#include "my_select.h"

static int	my_keycode_to_func(int keycode)
{
  if (keycode == 27)
    return (1);
  else if (keycode == UP)
    my_cursor_up();
  else if (keycode == DOWN)
    my_cursor_down();
  else if (keycode == BACKSPACE|| keycode == DEL)
    {
      my_clear_full_screen();
      key_delete();
    }
  else if (keycode == SPACE)
    select_item();
  else if (keycode == ENTER)
    return (key_validate());
  return (0);
}

static int	my_do_key_func(t_wins *winsize,
			       int keycode, int length)
{
  int		keys_ret;

  if ((ioctl(0, TIOCGWINSZ, winsize)) == -1)
    return (-1);
  keys_ret = my_keycode_to_func(keycode);
  if (keys_ret == 1)
    return (1);
  else if (keys_ret == -1)
    return (-1);
  if (g_list->item == NULL && g_list->next->item == NULL
      && g_list->previous->item == NULL)
    {
      my_clear_full_screen();
      return (1);
    }
  my_aff(winsize, length);
  return (0);
}

int		my_take_keys(int length)
{
  t_wins	winsize;
  int		read_ret;
  int		keys_ret;
  int		keycode;

  if ((ioctl(0, TIOCGWINSZ, &winsize)) == -1)
    return (-1);
  my_aff(&winsize, length);
  while ((read_ret = read(0, &keycode, 4)) != -1)
    {
      keys_ret = my_do_key_func(&winsize, keycode, length);
      keycode = 0;
      if (keys_ret == -1)
      	return (-1);
      else if (keys_ret == 1)
      	return (1);
    }
  return (0);
}
