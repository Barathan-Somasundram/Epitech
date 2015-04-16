/*
** my_strcmp.c for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 16:40:45 2014 taille_a
** Last update Sat Apr 12 12:16:47 2014 taille_a
*/

#include <stdlib.h>

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
      if (s1[i] != s2[i])
	return (1);
      ++i;
    }
  return (0);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (1);
      ++i;
    }
  if (s1[i] != s2[i])
    return (1);
  return (0);
}
