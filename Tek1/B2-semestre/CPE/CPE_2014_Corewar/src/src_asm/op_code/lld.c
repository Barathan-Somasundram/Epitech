/*
** lld.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 31 15:06:59 2014 taille_a
** Last update Sun Apr 13 17:32:48 2014 a
*/

#include "asm.h"

int		lld(t_list **list)
{
  if (((*list)->byte_used = ld(list)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->op_code = 13;
  return ((*list)->byte_used);
}
