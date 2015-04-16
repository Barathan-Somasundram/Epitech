/*
** texture.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Feb  4 21:45:47 2014 somasu_b
** Last update Fri Feb  7 17:51:36 2014 somasu_b
*/

#include "game.h"

int	my_putchar(int c)
{
  write(1, &c, 1);
  return (0);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      my_putchar(str[i++]);
}

int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
    my_putchar('0' + nb);
  return (0);
}

int	init_term(t_term *backup, t_term *gameone, char **env)
{
  char	*term;

  if ((term = my_get_term(env)) == NULL)
    return (-1);
  if (tgetent(0, term) != 1)
    return (-1);
  if (term != NULL)
    free(term);
  if ((tcgetattr(0, backup)) == -1)
    return (-1);
  if ((tcgetattr(0, gameone)) == -1)
    return (-1);
  (*gameone).c_lflag &= ~ICANON;
  (*gameone).c_lflag &= ~ECHO;
  (*gameone).c_cc[VMIN] = 1;
  (*gameone).c_cc[VTIME] = 0;
  if ((tcsetattr(0, 0, gameone)) == -1)
    return (-1);
  return (0);
}

int	my_clear_full_screen(void)
{
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_term	backup;
  t_term	gameone;
  t_menu	*menu;

  if (init_term(&backup, &gameone, env) == -1)
    return (-1);
  if (init_menu(&menu) == -1)
    return (-1);
  if (game_menu(&menu) == -1)
    return (-1);
  return (0);
}
