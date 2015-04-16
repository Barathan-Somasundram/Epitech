/*
** my_show_word_tab.c for my_show_word_tab in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 13:38:23 2013 a
** Last update Wed Dec 18 20:04:49 2013 a
*/

#include "../includes/my_lib.h"

void	my_show_word_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      i = i + 1;
    }
}
