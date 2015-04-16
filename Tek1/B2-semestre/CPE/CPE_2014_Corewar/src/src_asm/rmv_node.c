/*
** rmv_node.c for corewar in /home/taille_a/Travail/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sat Apr 12 10:37:14 2014 taille_a
** Last update Sun Apr 13 17:31:22 2014 a
*/

#include <stdlib.h>
#include "asm.h"

void		rmv_case_3(t_list **list)
{
  t_list        *tail;

  tail = *list;
  tail = tail->next;
  tail->prev = NULL;
  free((*list)->buff);
  free((*list)->ne_buff);
  free(*list);
  *list = tail;
}

void		rmv_case_2(t_list **list)
{
  t_list	*head;

  head = *list;
  head = head->prev;
  free((*list)->buff);
  free((*list)->ne_buff);
  free(*list);
  *list = head;
  (*list)->next = NULL;
}

void		rmv_case_1(t_list **list)
{
  t_list	*head;
  t_list	*tail;

  head = *list;
  tail = *list;
  tail = tail->next;
  head = head->prev;
  head->next = head->next->next;
  tail->prev = tail->prev->prev;
  free((*list)->buff);
  free((*list)->ne_buff);
  free(*list);
  (*list) = head;
}

int		parse_code_rmv(t_list **list)
{
  t_list	*head;
  t_list	*tail;

  head = *list;
  tail = *list;
  if (*list == NULL)
    return (-1);
  if (head->prev != NULL && tail->next != NULL)
    rmv_case_1(list);
  else if (tail->next == NULL && head->prev != NULL)
    rmv_case_2(list);
  else if (tail->next != NULL && head->prev == NULL)
    rmv_case_3(list);
  else if (tail->next == NULL && head->next == NULL)
    {
      free((*list)->buff);
      free((*list)->ne_buff);
      free(*list);
      *list = NULL;
      return (0);
    }
  while ((*list)->next != NULL)
    (*list) = (*list)->next;
  return (0);
}
