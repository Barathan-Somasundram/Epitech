/*
** func_ptr.c for func_ptr in /home/somasu_b/rendu/piscine_cpp_d02m/ex03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 11:29:53 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 14:19:11 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func_ptr.h"

void	print_normal(char *str)
{
  printf("%s\n", str);
}

void	print_reverse(char *str)
{
  int	i = 0;

  if (!str)
    printf("%s\n", "");
  else
    {
      i = (int)strlen(str) - 1;
      while (i >= 0)
	printf("%c", str[i--]);
      printf("\n");
    }
}

void	print_upper(char *str)
{
  int	i = -1;

  if (str)
    {
      while (str[++i] != '\0')
	if (str[i] >= 'a' && str[i] <= 'z')
	  printf("%c", str[i] - 32);
	else
	  printf("%c", str[i]);
      printf("\n");
    }
}

void	print_42(char *str)
{
  (void)str;
  printf("42\n");
}

void	do_action(t_action action, char *str)
{
  void	(*print_fct[4])(char *str);

  if (action > 3)
    return;
  print_fct[PRINT_NORMAL] = print_normal;
  print_fct[PRINT_REVERSE] = print_reverse;
  print_fct[PRINT_UPPER] = print_upper;
  print_fct[PRINT_42] = print_42;
  print_fct[action](str);
}
