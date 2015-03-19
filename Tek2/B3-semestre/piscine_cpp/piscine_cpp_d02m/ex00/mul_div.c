/*
** mul_div.c for mul_div in /home/somasu_b/rendu/piscine_cpp_d02m/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 10:09:30 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 10:12:16 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <stdio.h>

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  (*add) = first + second;
  (*mul) = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  int	tmp1 = *first;
  int	tmp2 = *second;

  (*first) = tmp1 + tmp2;
  (*second) = tmp1 * tmp2;
}
