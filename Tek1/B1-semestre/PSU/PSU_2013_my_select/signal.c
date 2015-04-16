/*
** signal.c for my_select in /home/somasu_b/TEST/select
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 23:07:40 2014 a
** Last update Sun Jan 19 21:35:41 2014 a
*/

#include "my_select.h"

void		win_resize(int signal)
{
  t_wins	winsize;
  int		length;

  if (signal == SIGWINCH)
    {
      length = my_long_strlen();
      if (ioctl(0, TIOCGWINSZ, &winsize) == -1)
	exit(0);
      my_clear_full_screen();
      my_aff(&winsize, length);
    }
}

void		my_control(int signal)
{
  t_term	new;

  if (signal == SIGINT || signal == SIGKILL)
    {
      if ((tcgetattr(0, &new)) == -1)
	exit(0);
      new.c_lflag |= ICANON;
      new.c_lflag |= ECHO;
      new.c_cc[VMIN] = 1;
      new.c_cc[VTIME] = 0;
      if ((tcsetattr(0, 0, &new)) == -1)
	exit(0);
    }
  exit(1);
}

void	my_signal(void)
{
  signal(SIGINT, my_control);
  signal(SIGKILL, my_control);
  signal(SIGWINCH, win_resize);
}
