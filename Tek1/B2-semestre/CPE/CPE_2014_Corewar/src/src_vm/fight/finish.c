/*
** finish.c for corewar in /home/somasu_b/rendu/corewar/vm
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Apr  5 21:19:39 2014 somasu_b
** Last update Sun Apr 13 18:47:10 2014 somasu_b
*/

#include "vm.h"
#include "my_strings.h"

int		corewar_winner(t_core *corewar, t_champs *champs)
{
  my_putstr("Le joueur n°");
  my_put_nbr(corewar->winner.pid);
  my_putstr(", ");
  my_putstr(corewar->winner.name);
  my_putstr(", a gagné\n");
  return (0);
}

int		arena_dump(t_core *corewar, t_champs *champs)
{
  int		line;
  int		i;

  line = 0;
  i = 0;
  my_put_nbr_base(line, 16);
  my_putstr(" :\t");
  while (i < MEM_SIZE)
    {
      if (corewar->arena[i] < 16)
      	my_putstr("0");
      my_put_nbr_base((int)corewar->arena[i++], 16);
      if (i % 16 == 0)
	{
	  ++line;
	  my_putstr("\n");
	  my_put_nbr_base(line, 16);
	  my_putstr(" :\t");
	}
      else
	my_putstr(" ");
    }
  return (0);
}
