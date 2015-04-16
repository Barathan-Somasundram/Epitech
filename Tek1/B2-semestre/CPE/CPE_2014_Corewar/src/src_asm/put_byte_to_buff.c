/*
** put_byte_to_buff.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sat Apr  5 16:29:48 2014 taille_a
** Last update Wed Apr  9 16:40:25 2014 taille_a
*/

#include "asm.h"
#include "my.h"

char		*put_byte_to_buff(char *buff, int size, int i, int nb)
{
  int		cpt;
  int		endian;

  endian = my_get_endian();
  cpt = -1;
  if (endian == BIG)
    {
      while (cpt++ < size)
  	buff[i + cpt] = nb >> 8 * cpt;
    }
  else
    {
      while (cpt < size)
  	{
  	  buff[i + (size - (cpt + 1))] = nb >> 8 * cpt;
  	  ++cpt;
  	}
    }
  return (buff);
}
