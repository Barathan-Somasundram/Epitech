/*
** div.c for div in /home/somasu_b/rendu/piscine_cpp_d02m/ex04
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 13:20:03 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 18:06:51 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "castmania.h"

int	integer_div(int a, int b)
{
  return ((b ? a / b : 0));
}

float	decimale_div(int a, int b)
{
  return ((b ? (float)a / (float)b : (float)0));
}

void	exec_div(t_div *operation)
{
  if (operation->div_type == INTEGER)
    ((t_integer_op*)(operation->div_op))->res = 
      integer_div(((t_integer_op*)(operation->div_op))->a,
		  ((t_integer_op*)(operation->div_op))->b);
  if (operation->div_type == DECIMALE)
    ((t_decimale_op*)(operation->div_op))->res = 
      decimale_div(((t_decimale_op*)(operation->div_op))->a, 
		   ((t_decimale_op*)(operation->div_op))->b);
}
