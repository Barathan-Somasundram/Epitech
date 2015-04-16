/*
** lfork.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM/op_code
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Fri Apr  4 14:09:31 2014 taille_a
** Last update Tue Apr  8 15:37:21 2014 taille_a
*/

#include "asm.h"

int		lfork(t_list **list)
{
  if (((*list)->byte_used = fork_asm(list)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->op_code = 15;
  return ((*list)->byte_used);
}
