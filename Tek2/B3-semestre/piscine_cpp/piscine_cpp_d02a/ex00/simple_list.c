/*
** simple_list.c for simple_list in /home/somasu_b/rendu/piscine_cpp_d02a/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 19:01:47 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 09:51:26 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "simple_list.h"

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

void	list_dump(t_list list)
{
  t_list	tmp = list;
  
  while (tmp != NULL)
    {
      printf("%f\n", tmp->value);
      tmp = tmp->next;
    }
}

t_bool	list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	new = NULL;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FALSE);
  new->value = elem;
  new->next = *front_ptr;
  *front_ptr = new;
  return (TRUE);
}

t_bool	list_add_elem_at_back(t_list *front_ptr, double elem)
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

t_bool	list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
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
  while (i < position - 1)
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

double	list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return ((double)0);
  return (list->value);
}

double	list_get_elem_at_back(t_list list)
{
  t_list	tmp = list;

  if (list == NULL)
    return ((double)0);
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp->value);
}

double	list_get_elem_at_position(t_list list, unsigned int position)
{
  t_list	tmp = list;
  unsigned int	i = 0;
  unsigned int	len = 0;

  if (list == NULL)
    return ((double)0);
  len = list_get_size(list);
  if (len < position)
    return (0);
  if (position == 0)
    return (list_get_elem_at_front(list));
  while (i < position)
    {
      tmp = tmp->next;
      i++;
    }
  return (tmp->value);
}

t_node	*list_get_first_node_with_value(t_list list, double value)
{
  t_list	tmp = list;

  if (tmp == NULL)
    return (NULL);
  while (tmp->next != NULL)
    {
      if (tmp->value == value)
	return ((t_node*)tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
