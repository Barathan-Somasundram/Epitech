/*
** ia_tools.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Feb  8 22:43:08 2014 somasu_b
** Last update Sun Feb 16 21:28:58 2014 somasu_b
*/

#include "../../includes/bonus.h"

int		strlen_alum(t_alum **alum)
{
  t_alum	*tmp_al;
  int		i;

  i = 0;
  tmp_al = (*alum)->next;
  while (tmp_al != *alum)
    {
      i = i + 1;
      tmp_al = tmp_al->next;
    }
  return (i);
}

int	int_tab(int len, t_alum **alum, int **sizes)
{
  t_alum	*tmp_al;
  int		i;

  i = 0;
  if ((*sizes = malloc(sizeof(int) * len)) == NULL)
    return (-1);
  tmp_al = (*alum)->next;
  while (tmp_al != *alum)
    {
      (*sizes)[i] = tmp_al->size;
      tmp_al = tmp_al->next;
      i = i + 1;
    }
  return (0);
}

int	my_xor(int len, int *sizes)
{
  int	res;
  int	i;

  i = 0;
  res = 0;
  while (i < len)
    res = res ^ sizes[i++];
  return (res);
}
