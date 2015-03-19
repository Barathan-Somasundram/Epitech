/*
** add.c for add in /home/somasu_b/rendu/piscine_cpp_d02m/ex04
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 13:21:00 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 16:33:48 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "castmania.h"

int	normal_add(int a, int b)
{
  return (a+b);
}

int	absolute_add(int a, int b)
{
  return ((a < 0 ? -a : a) + (b < 0 ? -b : b));
}

void	exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
  if (operation->add_type == ABSOLUTE)
    operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}
