/*
** asm_init.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Tue Mar 25 14:01:55 2014 taille_a
** Last update Sun Apr 13 17:28:16 2014 a
*/

#include <stdlib.h>
#include "asm.h"

void		opcodefunc_init(int (*tab[17])(t_list **))
{
  tab[0] = &live;
  tab[1] = &ld;
  tab[2] = &st;
  tab[3] = &add;
  tab[4] = &sub;
  tab[5] = &and;
  tab[6] = &or;
  tab[7] = &xor;
  tab[8] = &zjmp;
  tab[9] = &ldi;
  tab[10] = &sti;
  tab[11] = &fork_asm;
  tab[12] = &lld;
  tab[13] = &lldi;
  tab[14] = &lfork;
  tab[15] = &aff;
  tab[16] = NULL;
}

void		opcode_init(char *tab[17])
{
  tab[0] = "live";
  tab[1] = "ld";
  tab[2] = "st";
  tab[3] = "add";
  tab[4] = "sub";
  tab[5] = "and";
  tab[6] = "or";
  tab[7] = "xor";
  tab[8] = "zjmp";
  tab[9] = "ldi";
  tab[10] = "sti";
  tab[11] = "fork";
  tab[12] = "lld";
  tab[13] = "lldi";
  tab[14] = "lfork";
  tab[15] = "aff";
  tab[16] = NULL;
}
