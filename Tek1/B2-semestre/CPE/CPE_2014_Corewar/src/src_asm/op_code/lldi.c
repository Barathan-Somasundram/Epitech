/*
** lldi.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 31 15:08:02 2014 taille_a
** Last update Wed Apr  9 13:48:46 2014 taille_a
*/

#include "asm.h"

int		lldi(t_list **list)
{
  if (((*list)->byte_used = ldi(list)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->op_code = 14;
  return ((*list)->byte_used);
}
