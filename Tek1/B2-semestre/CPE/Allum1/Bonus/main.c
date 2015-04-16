/*
** main.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Feb  3 11:57:03 2014 somasu_b
** Last update Sun Feb 16 21:59:11 2014 a
*/

#include <termios.h>
#include "../includes/bonus.h"

int	my_clear_full_screen(void)
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  return (0);
}

int	which_player(t_alum **alum, t_menu *menu, int line, int w_player)
{
  int	ret;

  ret = 0;
  if (w_player == 1)
    if (menu->next->mode == TRUE)
      ret = player(alum, line);
    else
      ret = ia(alum);
  else
    if (menu->next->next->mode == TRUE)
      ret = player(alum, line);
    else
      ret = ia(alum);
  if (ret == 1)
    return (0);
  return (ret);
}

void	winner(int w_player)
{
  my_clear_full_screen();
  if (w_player == 1)
    {
      my_putstr("Player 1\n");
      i_win();
    }
  else
    {
      my_putstr("Player 1\n");
      i_lost();
    }
}

int	games(t_alum **alum, t_menu *menu)
{
  int	line;
  int	ret;

  ret = 0;
  while (ret == 0)
    {
      my_clear_full_screen();
      line = strlen_alum(alum);
      my_show(alum, line);
      ret = which_player(alum, menu, line, 1);
      if (ret == 3)
	winner(1);
      if (ret == 2 || ret == 3 || ret == -1)
	return (ret);
      my_clear_full_screen();
      line = strlen_alum(alum);
      ret = which_player(alum, menu, line, 2);
      if (ret == 3)
	winner(2);
    }
  return (ret);
}

int		main(int ac, char **av, char **env)
{
  t_term	backup;
  t_term	gameone;
  t_alum	*alum;
  t_menu	*menu;
  int		ret;

  if ((init_term(&backup, &gameone, env)) == -1)
    return (-1);
  my_clear_full_screen();
  if (init_menu(&menu) == -1)
    return (-1);
  if ((ret = game_menu(&menu)) == -1 || ret == 2)
    return (-1);
  if ((init_alum(&alum, menu->next->next->next->nb_alum)) == -1)
    return (-1);
  my_clear_full_screen();
  guide();
  my_clear_full_screen();
  if (((ret = games(&alum, menu))) == -1)
    return (-1);
  if ((tcsetattr(0, 0, &backup)) == -1)
    return (-1);
  tputs(tgetstr("ve", NULL), 1, my_putchar);
  return (0);
}
