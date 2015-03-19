/*
** main.c for menger in /home/somasu_b/rendu/piscine_cpp_d01/ex01
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Wed Jan  7 11:29:54 2015 SOMASUNDRAM Barathan
** Last update Wed Jan  7 22:49:30 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <stdio.h>

int	menger(int size, int lvl, int x, int y);

int	my_get_nbr(char *str)
{
  int	res = 0;
  int	i = -1;

  while (str[++i] != '\0')
    if (!(str[i] >= '0' && str[i] <= '9'))
      return (-1);
  i = -1;
  while (str[++i])
    res = (res * 10) + (str[i] - '0');
  return (res);
}

int	main(int argc, char **argv)
{
  int	size;
  int	lvl;

  if (argc < 3 || argc > 3)
    {
      printf("Error: in paramters\n");
      return (1);
    }
  size = my_get_nbr(argv[1]);
  lvl = my_get_nbr(argv[2]);
  if ((size <= 1 || size % 3 != 0) || (lvl > size || lvl < 0)/* || */)
    {
      printf("Error: in parameters\n");
      return (1);
    }
  printf("lvl = %d, size = %d\n", lvl, size);
  menger(size, lvl, 0, 0);
  return (0);
}
