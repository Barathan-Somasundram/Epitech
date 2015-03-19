/*
** generic_list.c for generic_list in /home/somasu_b/rendu/piscine_cpp_d02a/ex03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 08:22:21 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 09:53:38 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "generic_list.h"

unsigned int	list_get_size(t_list list)
{
  t_list	tmp = list;
  unsigned int	i = 0;
  
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

t_bool		list_is_empty(t_list list)
{
  if (list == NULL)
    return (TRUE);
  return (FALSE);
}


t_bool	list_add_elem_at_front(t_list *front_ptr, void *elem)
{
  t_list	new = NULL;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FALSE);
  new->value = elem;
  new->next = *front_ptr;
  *front_ptr = new;
  return (TRUE);
}

t_bool	list_add_elem_at_back(t_list *front_ptr, void *elem)
{
  t_list	tmp = *front_ptr;
  t_list	new = NULL;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FALSE);
  new->value = elem;
  new->next = NULL;
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  else
    *front_ptr = new;
  return (TRUE);
}

t_bool	list_add_elem_at_position(t_list *front_ptr, void *elem, unsigned int position)
{
  t_list	tmp1 = *front_ptr;
  t_list	tmp2 = NULL;
  t_list	new = NULL;
  unsigned int	i = 0;
  unsigned int	len = 0;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FALSE);
  new->value = elem;
  len = list_get_size(*front_ptr);
  if (len < position)
    return (FALSE);
  if (position == 0)
    return (list_add_elem_at_front(front_ptr, elem));
  tmp1 = *front_ptr;
  while (i < position)
    {
      i++;
      tmp1 = tmp1->next;
    }
  tmp2 = tmp1->next;
  new->next = tmp2;
  tmp1->next = new;
  return (TRUE);
}

t_bool	list_del_elem_at_front(t_list *front_ptr)
{
  t_list	tmp = NULL;
  if (*front_ptr != NULL)
    tmp = (*front_ptr)->next;
  else
    return (FALSE);
  free(*front_ptr);
  *front_ptr = tmp;
  return (TRUE);
}

t_bool	list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp = *front_ptr;
  t_list	tmp1 = *front_ptr;
  int		i = 0;

  if (*front_ptr == NULL)
    return (FALSE);
  while (tmp->next != NULL)
    {
      if (i >= 1)
	tmp1 = tmp1->next;
      tmp = tmp->next;
      ++i;
    }
  free(tmp);
  tmp1->next = NULL;
  return (TRUE);
}

t_bool	list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	tmp = *front_ptr;
  t_list	tmp1 = *front_ptr;
  unsigned int	j = 0;
  unsigned int	len = 0;
  int		i = 0;

  if (*front_ptr == NULL)
    return (FALSE);
  len = list_get_size(*front_ptr);
  if (len < position)
    return (FALSE);
  while (j < position)
    {
      if (i >= 1)
	tmp1 = tmp1->next;
      tmp = tmp->next;
      ++i;
      ++j;
    }
  tmp1->next = tmp->next;
  free(tmp);
  return (TRUE);
}

void	list_clear(t_list *front_ptr)
{
  while (*front_ptr != NULL)
    list_del_elem_at_front(front_ptr);
  *front_ptr = NULL;
}

void	*list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return ((void*)0);
  return (list->value);
}

void	*list_get_elem_at_back(t_list list)
{
  t_list	tmp = list;

  if (list == NULL)
    return ((void*)0);
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp->value);
}

void	*list_get_elem_at_position(t_list list, unsigned int position)
{
  t_list	tmp = list;
  unsigned int	i = 0;
  unsigned int	len = 0;

  if (list == NULL)
    return ((void*)0);
  len = list_get_size(list);
  if (len < position)
    return (FALSE);
  if (position == 0)
    return (list_get_elem_at_front(list));
  while (i < position)
    {
      tmp = tmp->next;
      i++;
    }
  return (tmp->value);
}

void	list_dump(t_list list, t_value_displayer val_disp)
{
  t_list	tmp = list;
  
  while (tmp != NULL)
    {
      val_disp(tmp->value);
      tmp = tmp->next;
    }
}

t_node  *list_get_first_node_with_value(t_list list, void *value, t_value_comparator val_comp)
{
  t_list	tmp = list;
  int		i;

  if (tmp == NULL)
    return (NULL);
  while (tmp->next != NULL)
    {
      i = val_comp(value, tmp->value);
      if (i == 0)
	return (tmp->value);
      tmp = tmp->next;
    }
  return (NULL);
}
