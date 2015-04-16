/*
** my_strlen_tab.c for my_strlen_tab in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 10:33:28 2013 a
** Last update Wed Dec 18 19:37:43 2013 a
*/

#include "../includes/my_lib.h"

int	my_strlen_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}
