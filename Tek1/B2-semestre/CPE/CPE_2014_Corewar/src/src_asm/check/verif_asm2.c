/*
** verif_asm2.c for corewar in /home/taille_a/Travail/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sat Apr 12 13:00:23 2014 taille_a
** Last update Sun Apr 13 13:00:13 2014 taille_a
*/

#include "op.h"
#include "asm.h"

int		verif_direct2(char *buff)
{
  int		i;
  int		dash;

  i = 1;
  dash = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '-')
	{
	  ++dash;
	  if (buff[i + 1] != '\0')
	    ++i;
	  else
	    return (INVALID_FILE);
	}
      if (buff[i] < '0' || buff[i++] > '9')
	return (INVALID_FILE);
    }
  if (dash > 1)
    return (INVALID_FILE);
  return (0);

}

int		verif_label_in_dir(char *buff)
{
  int		i;
  int		cpt;

  i = 2;
  while (buff[i])
    {
      cpt = 0;
      while (LABEL_CHARS[cpt] != buff[i]
	     && LABEL_CHARS[cpt] != '\0')
	cpt++;
      if (LABEL_CHARS[cpt] == '\0')
	return (INVALID_FILE);
      ++i;
    }
  return (0);
}
