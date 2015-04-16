/*
** fct_parse_code.c for zzz in /home/sam_t/Workstation/CPE_2014_corewar
**
** Made by sam_t
** Login   <sam_t@epitech.net>
**
** Started on  Fri Apr 11 16:27:48 2014 sam_t
** Last update Sun Apr 13 18:49:01 2014 somasu_b
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

void		init_value_in_list(t_list **list)
{
  (*list)->byte_used = 0;
  (*list)->tab[0] = 0;
  (*list)->tab[1] = 0;
  (*list)->tab[2] = 0;

}

static void    	mem_set(header_t *header)
{
  int		i;

  i = 0;
  while (i <= PROG_NAME_LENGTH)
    header->prog_name[i++] = 0;
}

int		get_name(t_list *elem, header_t *header, t_list **list)
{
  int		i;
  int		cpt;
  int		cpt2;

  i = 6;
  if ((cpt = get_comment(elem->buff, &i)) == -1)
    return (fct_err_line(elem->line, elem->ne_buff, 1));
  cpt2 = -1;
  if (i - cpt > PROG_NAME_LENGTH)
    return (LINE_TOO_LONG);
  while (cpt2++ <= PROG_NAME_LENGTH)
    {
      if (cpt < i && elem != NULL)
	header->prog_name[cpt2] = elem->buff[cpt++];
      else
	header->prog_name[cpt2] = 0;
    }
  *list = elem;
  parse_code_rmv(list);
  return (0);
}

int		parse_code(t_list **list, header_t *header)
{
  t_list	*elem;

  elem = *list;
  mem_set(header);
  while (elem != NULL)
    {
      if (my_strncmp(elem->buff, COMMENT_CMD_STRING, 8) == 0)
	return (fct_err_line(elem->line, elem->ne_buff, 1));
      if (my_strcmp(elem->buff, ".name") == 0)
	return (fct_err_line(elem->line, elem->ne_buff, 1));
      if (my_strncmp(elem->buff, ".name \"", 7) == 0)
	return (get_name(elem, header, list));
      elem = elem->prev;
    }
  return (0);
}
