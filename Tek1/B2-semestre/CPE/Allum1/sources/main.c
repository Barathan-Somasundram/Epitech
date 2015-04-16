/*
** main.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Feb  3 11:57:03 2014 somasu_b
** Last update Sun Feb 16 21:58:31 2014 a
*/

#include <termios.h>
#include "../includes/game.h"


int	my_clear_full_screen(void)
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  return (0);
}

int	games(t_alum **alum)
{
  int	line;
  int	ret;

  ret = 0;
  while (ret == 0)
    {
      line = strlen_alum(alum);
      my_show(alum, line);
      ret = player(alum, line);
      if (ret == 3)
	my_putstr(B_GREEN "YOU LOSE !! Try again ;)\n" NORMAL);
      if (ret == 2 || ret == 3 || ret == -1)
	return (ret);
      my_clear_full_screen();
      line = strlen_alum(alum);
      ret = ia(alum);
      if (ret == 3)
	my_putstr(B_MAGENTA "YOU WIN °(T_T)°\n" NORMAL);
    }
  return (ret);
}

int		main(int ac, char **av, char **env)
{
  t_term	backup;
  t_term	gameone;
  t_alum	*alum;
  int		line;
  int		ret;

  line = 4;
  guide();
  if ((init_alum(&alum, line)) == -1)
    return (-1);
  if ((init_term(&backup, &gameone, env)) == -1)
    return (-1);
  my_clear_full_screen();
  if ((games(&alum)) == -1)
    return (-1);
  if ((tcsetattr(0, 0, &backup)) == -1)
    return (-1);
  tputs(tgetstr("ve", NULL), 1, my_putchar);
  return (0);
}
