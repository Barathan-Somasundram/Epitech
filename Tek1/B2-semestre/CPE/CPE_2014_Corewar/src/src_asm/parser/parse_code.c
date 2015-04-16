/*
** parse_code.c for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 12:41:41 2014 taille_a
** Last update Sun Apr 13 18:48:35 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"

int		get_comment(char *buff, int *i)
{
  int		n;

  n = 0;
  while (buff[*i] != '\"' && buff[*i] != '\0')
    ++(*i);
  if (buff[*i] != '\0')
    ++*i;
  n = *i;
  while (buff[*i] != '\"' && buff[*i] != '\0')
    ++(*i);
  if (buff[*i] == '\0')
    return (-1);
  return (n);
}

static int     	mem_set(header_t *header)
{
  int		i;

  i = 0;
  while (i <= COMMENT_LENGTH)
    {
      header->comment[i] = 0;
      ++i;
    }
  return (0);
}

int		parse_comment2(t_list *elem, header_t *header,
			       t_list **list, int name)
{
  int		i;
  int		n;
  int		cpt2;

  i = 0;
  if ((n = get_comment(elem->buff, &i)) == -1)
    return (fct_err_line(elem->line, elem->ne_buff, 1));
  cpt2 = -1;
  if (i - n > COMMENT_LENGTH)
    return (LINE_TOO_LONG);
  while (cpt2++ <= COMMENT_LENGTH)
    {
      if (n < i && elem != NULL)
	header->comment[cpt2] = elem->buff[n++];
      else
	header->comment[cpt2] = 0;
    }
  if (name == 0)
    return (fct_err_line(elem->line, elem->ne_buff, 1));
  *list = elem;
  parse_code_rmv(list);
  return (0);
}

int		parse_comment(t_list **list, header_t *header, int name)
{
  t_list	*elem;

  elem = *list;
  mem_set(header);
  while (elem != NULL)
    {
      if (my_strncmp(elem->buff, ".comment \"", 10) == 0)
	return (parse_comment2(elem, header, list, name));
      elem = elem->prev;
    }
  return (0);
}
