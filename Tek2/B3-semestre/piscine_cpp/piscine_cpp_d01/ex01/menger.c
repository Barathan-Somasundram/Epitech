/*
** menger.c for menger in /home/somasu_b/rendu/piscine_cpp_d01/ex01
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Wed Jan  7 11:30:26 2015 SOMASUNDRAM Barathan
** Last update Wed Jan  7 23:35:06 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <stdio.h>

int	menger(int size, int lvl, int x, int y)
{
  int	blk_s = size / 3;

  /* if (lvl > 0) */
  /*   { */
  /*     printf("%.3d %.3d %.3d\n", blk_s, x + blk_s, y + blk_s); */
  /*     while (x < size) */
  /* 	{ */
  /* 	  while (y < size) */
  /* 	    { */
  /* 	      menger(size / 3, lvl - 1, x, y); */
  /* 	      y = y + blk_s; */
  /* 	    } */
  /* 	  y = y - size; */
  /* 	  x = x + blk_s; */
  /* 	} */
  /*   } */
  if (lvl > 0)
    {
      printf("%.3d %.3d %.3d\n", size, y + blk_s, x + blk_s);
      menger(size / 3, lvl - 1, x, y);
      menger(size / 3, lvl - 1, x + blk_s, y);
      menger(size / 3, lvl - 1, x + 2 * size / 3, y);
      menger(size / 3, lvl - 1, x, y + size / 3);
      menger(size / 3, lvl - 1, x + 2 * size / 3, y + size / 3);
      menger(size / 3, lvl - 1, x + size / 3, y + 2 * size / 3);
      menger(size / 3, lvl - 1, x + 2 * size / 3, y + 2 * size / 3);
    }

  return (0);
}
