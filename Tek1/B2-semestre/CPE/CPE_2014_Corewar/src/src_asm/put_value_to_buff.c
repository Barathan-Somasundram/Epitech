/*
** put_value_to_buff.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Apr 10 01:01:51 2014 taille_a
** Last update Sat Apr 12 17:00:26 2014 taille_a
*/

#include "asm.h"
#include "op.h"
#include "my.h"

char		*put_value_to_buffer(t_list **list, t_toke *elem,
				     int cpt, char *buff)
{
  int		i;
  long		nb;

  i = 0;
  while (i < op_tab[(*list)->op_code - 1].nbr_args)
    {
      elem = elem->prev;
      nb = 0;
      if ((elem->buff[0] == DIRECT_CHAR &&
	   elem->buff[1] == LABEL_CHAR) ||
	  elem->buff[0] == LABEL_CHAR)
      	nb = search_label(list, elem->buff);
      else
	{
	  nb = my_getnbr(elem->buff);
	  verif_value(list, nb, (*list)->line, elem->buff);
	}
      if ((*list)->tab[i] != 1)
	buff = put_byte_to_buff(buff, (*list)->tab[i], cpt, nb);
      else
      	buff[cpt] = nb;
      cpt += (*list)->tab[i++];
    }
  return (buff);
}
