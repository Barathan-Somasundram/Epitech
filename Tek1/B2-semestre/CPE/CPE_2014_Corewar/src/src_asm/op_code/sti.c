/*
** sti.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sun Mar 30 16:32:26 2014 taille_a
** Last update Sun Apr 13 17:33:08 2014 a
*/

#include "op.h"
#include "asm.h"

static char	get_byte_code1(int *tab)
{
  char		code;

  code = (tab[0] == T_REG) ? 0b01 << 6 :
    (tab[0] == T_DIR) ? 0b10 << 6 : (tab[0] == T_IND) ? 0b11 << 6 : 0;
  code += (tab[1] == T_REG) ? 0b01 << 4 :
    (tab[1] == T_DIR) ? 0b10 << 4 : (tab[1] == T_IND) ? 0b11 << 4 : 0;
  code += (tab[2] == T_DIR) ? 0b10 << 2 : (tab[2] == T_REG) ? 0b01 << 2 : 0;
  return (code);
}

static void	resize_tab(int *tab)
{
  tab[0] = 1;
  tab[1] = (tab[1] == T_REG) ? 1 : IND_SIZE;
  tab[2] = (tab[2] == T_REG) ? 1 : IND_SIZE;
}

int		sti(t_list **list)
{
  t_toke	*elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 11;
  if (elem == NULL)
    return (INVALID_FILE);
  if ((verif_register(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->tab[0] = T_REG;
  elem = elem->prev;
  if (elem == NULL)
    return (INVALID_FILE);
  if (((*list)->tab[1] = get_type_argument(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  elem = elem->prev;
  if (elem == NULL)
    return (INVALID_FILE);
  if (((*list)->tab[2] = get_type_argument(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  if (elem->prev != NULL)
    return (INVALID_FILE);
  (*list)->code = get_byte_code1((*list)->tab);
  resize_tab((*list)->tab);
  return ((*list)->tab[1] + (*list)->tab[2] + (*list)->tab[0] + 1);
}
