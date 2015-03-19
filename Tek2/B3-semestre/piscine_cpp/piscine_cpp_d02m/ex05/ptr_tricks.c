/*
** ptr_tricks.c for ptr_tricks in /home/somasu_b/rendu/piscine_cpp_d02m/ex05
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 18:08:56 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 19:29:15 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ptr_tricks.h"

int	get_array_nb_elem(int *ptr1, int*ptr2)
{
  return (ptr1 < ptr2 ? ptr2 - ptr1 : ptr1 - ptr2);
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
  t_whatever	tmp;
  
  return ((t_whatever*)(member_ptr - (get_array_nb_elem((int*)&tmp, &tmp.member))));
}
