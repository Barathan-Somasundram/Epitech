/*
** my_free.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Feb 27 13:33:42 2014 somasu_b
** Last update Fri Mar  7 13:00:01 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>

void	my_free_tab(char ***tab)
{
  int	i;

  i = 0;
  if ((*tab) != NULL)
    while ((*tab)[i] != NULL)
      free((*tab)[i++]);
  if (*tab != NULL)
    free(*tab);
}
