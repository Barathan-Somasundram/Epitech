/*
** char_is_num.c for char_is_num in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 11:19:53 2013 a
** Last update Wed Dec 18 20:00:31 2013 a
*/

#include "../includes/my_lib.h"

int	char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}
