/*
** flag.c for  in /home/somasu_b/rendu/elcrypt/sources
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 18:15:15 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:15:15 2015 SOMASUNDRAM Barathan
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "elcrypt.h"

int		flag_action(char **av, int arg, t_elcrypt *param)
{
  if (strcmp(av[arg], "-d") == 0)
    {
      if (param->action != -1 && param->action != 0)
	{
	  write(2, "You must choose between decrypt and crypt\n", 42);
	  return (-1);
	}
      param->action = 0;
    }
  else if (strcmp(av[arg], "-e") == 0)
    {
      if (param->action != -1 && param->action != 1)
	{
	  write(2, "You must choose between decrypt and crypt\n", 42);
	  return (-1);
	}
      param->action = 1;
    }
  else
    return (0);
  return (1);
}

int		flag_file(int ac, char **av, int arg, t_elcrypt *param)
{
  if (strcmp(av[arg], "-f") == 0)
    {
      if (arg + 1 >= ac)
	return (-1);
      if ((param->in = strdup(av[arg + 1])) == NULL)
	return (-1);
    }
  else if (strcmp(av[arg], "-o") == 0)
    {
      if (arg + 1 >= ac)
	return (-1);
      if ((param->out = strdup(av[arg + 1])) == NULL)
	return (-1);
    }
  else
    return (0);
  return (2);
}

int		flag_key(int ac, char **av, int arg, t_elcrypt *param)
{
  if (strcmp(av[arg], "-k") == 0)
    {
      if (arg + 1 >= ac)
	return (-1);
      if ((param->key = strdup(av[arg + 1])) == NULL)
	return (-1);
    }
  else
    return (1);
  return (2);
}
