/*
** new_channel.c for new_channel in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:31:57 2015 Potier Guillaume
** Last update Sun Apr 12 16:32:22 2015 Potier Guillaume
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

int			if_exist(char *name, t_list_channel *channel)
{
  t_list_channel	*tmp;

  tmp = channel;
  while (tmp)
    {
      if (strcmp(tmp->name, name) == 0)
	return (tmp->id);
      tmp = tmp->next;
    }
  return (0);
}

t_list_channel		*new_channel(char *name,
				     t_list_channel *channel,
				     int *id)
{
  t_list_channel	*new;
  t_list_channel	*tmp;

  if ((new = malloc(sizeof(t_list_channel))) == NULL)
    return (NULL);
  if ((new->name = strdup(name)) == NULL)
    return (NULL);
  new->next = NULL;
  if (channel == NULL)
    {
      channel = new;
      new->id = 1;
    }
  else
    {
      tmp = channel;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      new->id = tmp->id + 1;
    }
  *id = new->id;
  return (channel);
}
