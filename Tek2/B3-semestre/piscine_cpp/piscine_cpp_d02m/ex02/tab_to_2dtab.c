/*
** tab_to_2dtab.c for tab_to_2dtab in /home/somasu_b/rendu/piscine_cpp_d02m/ex02
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 11:04:22 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 11:25:07 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int	i = 0;
  int	j = 0;
  int	k = 0;

  if ((*res = malloc(sizeof(int*) * (length + 1))) == NULL)
    return;
  while (i <= length)
    {
      if (((*res)[i] = malloc(sizeof(int) * (width + 1))) == NULL)
	return;
      i++;
    }
  i = 0;
  while (i < length)
    {
      j = 0;
      while (j < width)
	{
	  (*res)[i][j] = tab[k];
	  k++;
	  j++;
	}
      i++;
    }
}
