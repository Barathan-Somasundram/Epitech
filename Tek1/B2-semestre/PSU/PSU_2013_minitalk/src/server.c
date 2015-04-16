/*
** client.c for minitalk in /home/somasu_b/rendu/minitalk/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Mar 22 23:32:47 2014 somasu_b
** Last update Sun Mar 23 18:35:42 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void		get_sig(int sig)
{
  static char	c = 0;
  static char	b = 0;

  if (sig == SIGUSR2)
    c = (c * 2) + 1;
  if (sig == SIGUSR1)
    c = (c * 2) + 0;
  if (sig == SIGUSR1 || sig == SIGUSR2)
    ++b;
  if (b > 7)
    {
      my_putchar(STDOUT_FILENO, c);
      c = 0;
      b = 0;
    }
}

int	my_signal(void)
{
  if (signal(SIGUSR1, get_sig) == SIG_ERR)
    return (my_perror("A problem has happened while catching message\n"));
  if (signal(SIGUSR2, get_sig) == SIG_ERR)
    return (my_perror("A problem has happened while catching message\n"));
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 1)
    return (my_perror("Too many argument(s)\nUsage: ./server\n"));
  if (my_signal() == -1)
    return (-1);
  my_putstr("Server PID id : ");
  my_put_nbr(getpid());
  my_putstr("\n");
  while (42)
    pause();
  return (0);
}
