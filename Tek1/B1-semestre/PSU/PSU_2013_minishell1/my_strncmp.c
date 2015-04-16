/*
** my_strncmp.c for my_strncmp in /home/somasu_b/rendu/Piscine-C-Jour_06/ex_06
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Oct  8 06:24:33 2013 a
** Last update Sat Dec 28 19:49:50 2013 a
*/

#include <string.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	compare;

  compare = 0;
  if (!s1 || !s2)
    return (-1);
  while (compare < n && s1[compare] == s2[compare]
  	 && s1[compare] != '\0' && s2[compare] != '\0')
    compare = compare + 1;
  return (s1[compare] - s2[compare]);
}
