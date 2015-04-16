/*
** main.c for my_select in /home/somasu_b/TEST/select
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Jan 16 10:36:27 2014 somasu_b
** Last update Sun Jan 19 20:42:49 2014 a
*/

#include "my_select.h"

int	my_clear_full_screen()
{
  tputs(tgetstr("cl", NULL), 1, tputchar);
  return (0);
}

int	init_term(t_term *backup, t_term *termcap, char **env)
{
  char	*term;

  if (my_get_term(env) == NULL)
    return (-42);
  term = my_get_term(env);
  if (tgetent(0, term) != 1)
    return (-42);
  if ((tcgetattr(0, backup)) == -1)
    return (-1);
  if ((tcgetattr(0, termcap)) == -1)
    return (-1);
  (*termcap).c_lflag &= ~ICANON;
  (*termcap).c_lflag &= ~ECHO;
  (*termcap).c_cc[VMIN] = 1;
  (*termcap).c_cc[VTIME] = 0;
  if ((tcsetattr(0, 0, termcap)) == -1)
    return (-1);
  return (0);
}

int		my_long_strlen()
{
  t_list	*tmp;
  int		length;
  int		temp;

  tmp = g_list->next;
  length = 0;
  while (tmp != g_list)
    {
      temp = my_strlen(tmp->item);
      if (temp > length)
	length = temp;
      tmp = tmp->next;
    }
  return (length);
}

int	my_return(t_term *backup, int number)
{
  tputs(tgetstr("ve", NULL), 1, tputchar);
  if ((tcsetattr(0, 0, backup)) == -1)
    return (-1);
  return (number);
}

int    		main(int ac, char **av, char **env)
{
  t_term	backup;
  t_term	termcap;
  int		length;
  int		ret;

  if (init_list(ac, av) == -1)
    return (-1);
  if ((ret = init_term(&backup, &termcap, env)) == -1)
    return (-1);
  if (ret == -42)
    return (-42);
  if (my_clear_full_screen() == -1)
    return (my_return(&backup, -1));
  length = my_long_strlen();
  my_signal();
  if ((ret = my_take_keys(length)) == -1)
    return (my_return(&backup, -1));
  if (ret == 1)
    return (my_return(&backup, 0));
  return (0);
}
