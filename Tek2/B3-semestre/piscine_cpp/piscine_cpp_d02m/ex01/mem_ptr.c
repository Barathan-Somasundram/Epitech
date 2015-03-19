/*
** mem_ptr.c for mem_ptr in /home/somasu_b/rendu/piscine_cpp_d02m/ex01
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 10:19:21 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 18:41:27 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mem_ptr.h"

void	add_str(char *str1, char *str2, char **res)
{
  int	i = 0;
  int	j = 0;

  if ((*res = malloc(sizeof(char*) * (((!str1) ? 0 : (int)strlen(str1))
				      + ((!str2) ? 0 : (int)strlen(str2)) + 1)))
      == NULL)
    return;
  while (str1 && i < (int)strlen(str1))
    {
      (*res)[i] = str1[i];
      i++;
    }
  while (str2 && j < (int)strlen(str2))
    {
      (*res)[i] = str2[j];
      i++;
      j++;
    }
  (*res)[i] = '\0';
}

void	add_str_struct(t_str_op *str_op)
{
  int	i = 0;
  int	j = 0;

  if ((str_op->res = malloc(sizeof(char*) * (((!str_op->str1) ? 0 : (int)strlen(str_op->str1))
				      + ((!str_op->str2) ? 0 : (int)strlen(str_op->str2)) + 1)))
      == NULL)
    return;
  while (str_op->str1 && i < (int)strlen(str_op->str1))
    {
      (str_op->res)[i] = str_op->str1[i];
      i++;
    }
  while (str_op->str2 && j < (int)strlen(str_op->str2))
    {
      str_op->res[i] = str_op->str2[j];
      i++;
      j++;
    }
  str_op->res[i] = '\0';
}
