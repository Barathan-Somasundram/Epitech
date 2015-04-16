/*
** my_strcmp.c for my_strcmp in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 13:54:01 2013 a
** Last update Wed Dec 18 19:35:44 2013 a
*/

#include "../includes/my_lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	compare;

  compare = 0;
  while ((s1[compare] == s2[compare]) &&
	 (s1[compare] != '\0' || s2[compare] != '\0'))
    compare = compare + 1;
  return (s1[compare] - s2[compare]);
}
