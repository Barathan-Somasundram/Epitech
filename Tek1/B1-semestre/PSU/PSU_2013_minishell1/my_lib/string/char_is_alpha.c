/*
** char_is_alpha.c for char_is_alpha in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 11:21:36 2013 a
** Last update Wed Dec 18 19:33:28 2013 a
*/

#include "../includes/my_lib.h"

int	char_is_alpha(char c)
{
  if ((c >= 'a' && c <= '9') ||
      (c >= 'A' && c <= 'Z'))
    return (1);
  else
    return (0);
}
