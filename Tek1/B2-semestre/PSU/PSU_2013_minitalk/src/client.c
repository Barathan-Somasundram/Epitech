/*
** server.c for minitalk in /home/somasu_b/rendu/minitalk/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Mar 22 22:56:40 2014 somasu_b
** Last update Sun Mar 23 19:06:21 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int	send_signal(const pid_t server, int bin)
{
  if (bin == 1)
    {
      if (kill(server, SIGUSR2) == -1)
	return (my_perror("Cannot send signal\n"));
    }
  else
    {
      if (kill(server, SIGUSR1))
	return (my_perror("Cannot send signal\n"));
    }
  return (0);
}

int	send_bit(const pid_t server, char c)
{
  int	bin[8];
  int	i;

  i = 7;
  while (i >= 0)
    {
      bin[i--] = c % 2;
      c = c / 2;
    }
  i = 0;
  while(i < 8)
    {
      if (send_signal(server, bin[i]) == -1)
	return (-1);
      ++i;
      if (usleep(1000) == -1)
	return (my_perror("Error\n"));
    }
  return (0);
}

int	client(char **av)
{
  int	i;
  pid_t	server;

  i = 0;
  server = my_get_nbr(av[1]);
  if (server < 1)
    return(my_perror("Error : pid is not valid\n"));
  while (av[2][i] != '\0')
    {
      if (send_bit(server, av[2][i]) == -1)
  	return (-1);
      ++i;
    }
  if (send_bit(server, av[2][i]) == -1)
    return (-1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 3)
    return (my_perror("ERROR: Too few arguements\n"
		      "Usage: ./client [server PID] [Message]\n"));
  if (ac > 3)
    return (my_perror("ERROR: Too many arguements\n"
		      "Usage: ./client [server PID] [Message]\n"));
  if (client(av) == -1)
    return (-1);
  return (0);
}
