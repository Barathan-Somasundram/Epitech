/*
** main.c for  in /home/somasu_b/rendu/PSU_2014_myftp/sources/server
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Mar 13 00:21:09 2015 SOMASUNDRAM Barathan
** Last update Fri Mar 13 00:23:52 2015 SOMASUNDRAM Barathan
*/

#include "server.h"

static int	check_port(char *port)
{
  int		i;
  int		is_there_nb;

  i = 0;
  is_there_nb = 0;
  while (str && str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	is_there_nb = 1;
      else
	{
	  fprintf(stderr, ERR_PORT);
	  return (1);
	}
      ++i;
    }
  if (is_there_nb != 1)
    {
      fprintf(stderr, ERR_PORT);
      return (1);
    }
  return (0);
}

int		main(int ac, char** av)
{
  t_server	server;

  if (ac != 2)
    {
      fprintf(stderr, USAGE_SERVER);
      return (1);
    }
  if (check_port(av[1]) == 1)
    return (1);
  server.port = atoi(av[1]);
  if (server_ftp(&server) == 1)
    return (1);
  return (0);
}
