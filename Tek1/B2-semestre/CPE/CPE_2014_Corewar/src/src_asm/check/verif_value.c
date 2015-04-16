/*
** verif_value.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Apr 10 00:52:19 2014 taille_a
** Last update Sat Apr 12 16:27:14 2014 taille_a
*/

#include <unistd.h>
#include "my.h"
#include "op.h"
#include "asm.h"

void		verif_case_one(t_list *elem, int line)
{
  write(2, "Warning Indirection to far line ", 32);
  my_putnbr(line);
  write(2, "\n", 1);
  write(2, elem->ne_buff, my_strlen(elem->ne_buff));
  write(2, "\n", 1);
}

void		verif_value(t_list **list, long nb,
			    int line, char *buff)
{
  t_list	*elem;

  elem = *list;
  if (buff[0] == 'r' && (nb > REG_NUMBER || nb < 0 || nb == 0))
    {
      write(2, "no such register line ", 22);
      my_putnbr(line);
      my_exit(list, "\n");
    }
  else if (buff[0] != DIRECT_CHAR
  	   && (nb > IDX_MOD || nb < -IDX_MOD) && buff[0] != 'r')
    verif_case_one(elem, line);
  else if (buff[0] == DIRECT_CHAR && (nb > 2147483647 || nb < -2147483648))
    {
      write(2, "Warning direct too big line ", 28);
      my_putnbr(line);
      write(2, "\n", 1);
      write(2, elem->ne_buff, my_strlen(elem->ne_buff));
      write(2, "\n", 1);
    }
}
