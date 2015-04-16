/*
** my_putchar_error.c for my_putchar_error in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 10:35:15 2013 a
** Last update Wed Dec 18 19:34:07 2013 a
*/

#include "../includes/my_lib.h"

void	my_putchar_error(char e)
{
  write(2, &e, 1);
}
