/*
** my_putchar.c for my_putchar in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 10:29:54 2013 a
** Last update Wed Dec 18 19:33:54 2013 a
*/

#include "../includes/my_lib.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
