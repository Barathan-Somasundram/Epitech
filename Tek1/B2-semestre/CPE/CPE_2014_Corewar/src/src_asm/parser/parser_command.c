/*
** parser_command.c for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 17:38:18 2014 taille_a
** Last update Sat Apr 12 16:53:10 2014 taille_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

int		parse_label(t_list **list)
{
  t_list	*elem;

  elem = *list;
  while (elem != NULL)
    {
      if (elem->token_list != NULL)
	if (elem->token_list->buff
	    [my_strlen(elem->token_list->buff) -1] == LABEL_CHAR)
	  {
	    if ((verif_label(elem->token_list->buff)) == INVALID_FILE)
	      return (fct_err_line(elem->line, elem->ne_buff, 0));
	    else
	      {
		if (elem->token_list->buff[1] == '\0')
		  return (fct_err_line(elem->line, elem->ne_buff, 0));
		elem->is_a_label = elem->token_list->buff;
		elem->is_a_label[my_strlen(elem->is_a_label) - 1] = '\0';
		if (verif_existing_label(&elem, elem->is_a_label) == INVALID_FILE)
		  return (fct_err_line(elem->line, elem->ne_buff, 0));
		elem->token_list = elem->token_list->prev;
	      }
	  }
      elem = elem->prev;
    }
  return (0);
}

int		search_op_code(t_list *elem, char **tab)
{
  int		cpt;

  cpt = 0;
  while (my_strcmp(elem->token_list->buff,
		   tab[cpt]) != 0 && tab[cpt])
    ++cpt;
  return (cpt);
}

int		search_command(t_list **list, char **tab,
			       int(*ptr[17])(t_list **))
{
  t_list	*elem;
  int		i;
  int		cpt;

  elem = (*list);
  i = 0;
  while ((elem) != NULL)
    {
      cpt = 0;
      if (elem->buff[0] != COMMENT_CHAR && elem->token_list != NULL)
	{
	  if (elem->token_list->buff != NULL)
	    {
	      cpt = search_op_code(elem, tab);
	      if (tab[cpt] == NULL ||
		  (elem->byte_used = ptr[cpt](&elem)) == INVALID_FILE)
		return (fct_err_line(elem->line, elem->ne_buff, 1));
	      if (elem->token_list->prev->buff == NULL)
		return (fct_err_line(elem->line, elem->ne_buff, 1));
	    }
	}
      elem = elem->prev;
      ++i;
    }
  return (0);
}

int		parser_command2(t_list **elem, char *op, int i, int cpt)
{
  t_toke	*tmp;

  while ((*elem)->buff[i] != '\0')
    {
      if ((tmp = malloc(sizeof(*tmp))) == NULL)
	my_exit(elem, "Can't perform malloc\n");
      op = my_get_token((*elem)->buff, &i);
      if (op[0] == COMMENT_CHAR)
      	return (0);
      if ((tmp->buff = malloc(sizeof(char) *
			      my_strlen(op) + 1)) == NULL)
	my_exit(elem, "Can't perform malloc\n");
      my_strncpy(tmp->buff, op, 0, my_strlen(op));
      tmp->next = (*elem)->token_list;
      if ((*elem)->token_list != NULL)
	(*elem)->token_list->prev = tmp;
      (*elem)->token_list = tmp;
      ++cpt;
    }
  if ((*elem)->token_list != NULL)
    (*elem)->token_list->prev = NULL;
  if (cpt > 5)
    return (fct_err_line((*elem)->line, (*elem)->ne_buff, 1));
  return (0);
}

int		parser_command(t_list **list)
{
  t_list	*elem;
  char		*op;
  int		(*op_code[17])(t_list **);
  char		*tab[17];

  opcode_init(tab);
  op = NULL;
  opcodefunc_init(op_code);
  elem = *list;
  while (elem != NULL && elem->buff[0] == '\0')
    elem = elem->prev;
  while (elem != NULL)
    {
      elem->is_a_label = NULL;
      parser_command2(&elem, op, 0, 0);
      if (elem->token_list != NULL)
	while (elem->token_list->next != NULL)
	  elem->token_list = elem->token_list->next;
      elem = elem->prev;
    }
  if ((parse_label(list)) == INVALID_FILE)
    return (INVALID_FILE);
  if ((search_command(list, tab, op_code)) == INVALID_FILE)
    return (INVALID_FILE);
  return (0);
}
