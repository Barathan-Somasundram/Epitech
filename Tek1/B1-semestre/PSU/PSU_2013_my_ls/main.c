/*
** main.c for my_ls in /home/somasu_b/my_files
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Nov 30 01:05:36 2013 a
** Last update Sun Dec  1 18:55:43 2013 a
*/

#include "my_ls.h"

char	*fill_flags(char *flags, char arg)
{
  if (arg == 'l')
    flags[0] = '1';
  else if (arg == 'R')
    flags[1] = '1';
  else if (arg == 'r')
    flags[2] = '1';
  else if (arg == 't')
    flags[3] = '1';
  else if (arg == 'd')
    flags[4] = '1';
  else if (arg != 'l' || arg != 'R' || arg != 'r' ||
	   arg != 't' || arg != 'd')
    exit(0);
  flags[5] = '\0';
  return (flags);
}

int	directory(int ac, char **av)
{
  int	i;
  int	count;

  i = 1;
  count = 0;
  while (i < ac)
    {
      if (av[i][0] != '-')
	count = count + 1;
      i = i + 1;
    }
  return (count);
}

char	*flags(int ac, char **av)
{
  int	i;
  int	j;
  char	*flags;

  i = 0;
  j = 0;
  flags = malloc(sizeof(char) * 6);
  while (i < 6)
    {
      flags[i] = '0';
      i = i + 1;
    }
  i = 1;
  while (i < ac)
    {
      j = 1;
      if (av[i][0] == '-')
	while (av[i][j] != '\0')
	  {
	    flags = fill_flags(flags, av[i][j]);
	    j = j + 1;
	  }
      i = i + 1;
    }
  return (flags);
}

int	main(int ac, char **av)
{
  char	*flag;
  int	i;

  i = 1;
  flag = flags(ac, av);
  if (directory(ac, av) == 0)
    my_ls(".", flag);
  else
    {
      while (i < ac)
	{
	  if (av[i][0] != '-')
	    my_ls(av[i], flag);
	  if (directory(ac, av) != 1)
	    my_putchar('\n');
	  i = i + 1;
	}
    }
  free(flag);
  return (0);
}
