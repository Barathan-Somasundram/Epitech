/*
** cmd_center.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Feb  4 16:16:37 2014 somasu_b
** Last update Sun Feb 16 21:28:45 2014 somasu_b
*/

#include "../../includes/bonus.h"

static int	select_chk(t_alum **alum)
{
  t_alum	*tmp_al;
  t_line	*tmp_li;
  int		select;

  select = 0;
  tmp_al = (*alum)->next;
  while (tmp_al != *alum)
    {
      tmp_li = tmp_al->line->next;
      while (tmp_li != tmp_al->line)
	{
	  if (tmp_li->select == TRUE)
	    select = 1;
	  tmp_li = tmp_li->next;
	}
      tmp_al = tmp_al->next;
    }
  if (select == 1)
    return (1);
  else
    return (0);
  return (0);
}

static int	my_keycode_to_func(int keycode, t_alum **alum)
{
  if (keycode == ESCAPE)
    return (-2);
  else if (keycode == UP)
    {
      select_out(alum);
      return (move_up(alum));
    }
  else if (keycode == DOWN)
    {
      select_out(alum);
      return (move_down(alum));
    }
  else if (keycode == LEFT)
    return (move_left(alum));
  else if (keycode == RIGHT)
    return (move_right(alum));
  else if (keycode == SELECT)
    return (select_it(alum));
  else if (keycode == ENTER)
    {
      if (select_chk(alum) == 0)
	return (0);
      return (valide_it(alum));
    }
  return (0);
}

int		player(t_alum **alum, int line)
{
  int		read_ret;
  int		keys_ret;
  int		keycode;

  keycode = 0;
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
  my_show(alum, line);
  while ((read_ret = read(0, &keycode, 4)) > 0)
    {
      keys_ret = my_keycode_to_func(keycode, alum);
      if (keycode == ENTER)
      	my_clear_full_screen();
      keycode = 0;
      if (keys_ret == -1)
	return (-1);
      else if (keys_ret == -2)
	return (2);
      else if (keys_ret == 1)
	return (1);
      else if (keys_ret == 2)
	return (3);
      tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
      my_show(alum, line);
    }
  return (0);
}
