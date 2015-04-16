/*
** my_list.c for corewar in /home/somasu_b/rendu/corewar/VM/retcode/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Apr  1 17:58:12 2014 somasu_b
** Last update Sun Apr 13 18:04:52 2014 a
*/

#include "vm.h"

int		free_champ(t_champs *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
  return (0);
}

int		kill_champs(t_champs **champs, t_champs *elem)
{
  t_champs	*tmp;

  tmp = (*champs)->next;
  while (tmp != *champs)
    {
      if (tmp != elem && tmp->my_father == elem->my_number)
  	{
  	  tmp->prev->next = tmp->next;
  	  tmp->next->prev = tmp->prev;
  	  free(tmp);
	  tmp = (*champs)->next;
  	}
      tmp = tmp->next;
    }
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
  return (0);
}

int		my_join_champs(t_champs **champs, t_champs **elem, int tri)
{
  t_champs	*tmp;

  tmp = (*champs)->next;
  if (tri == 1)
    while (tmp != *champs && tmp->my_number < (*elem)->my_number)
      tmp = tmp->next;
  else
    while (tmp->next != *champs)
      tmp = tmp->next;
  (*elem)->prev = tmp->prev;
  (*elem)->next = tmp;
  tmp->prev->next = (*elem);
  tmp->prev = (*elem);
  return (0);
}

int		create_root_champ(t_champs **champs)
{
  if ((*champs = malloc(sizeof(**champs))) == NULL)
    return (-1);
  (*champs)->prev = *champs;
  (*champs)->next = *champs;
  return (0);
}
