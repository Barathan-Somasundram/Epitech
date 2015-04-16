/*
** init_move_ant.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sun May  4 20:03:05 2014 potier_g
** Last update Sun May  4 20:27:08 2014 potier_g
*/

#include <stdlib.h>
#include "struct.h"

int	init_move_ant(t_move *move, t_param *param, t_coor *end)
{
  if ((move->pos_act.x = init_posx(move->nbr_ant, *move, param, 1)) == NULL)
    return (-1);
  if ((move->pos_act.y = init_posy(move->nbr_ant, *move, param, 1)) == NULL)
    return (-1);
  if ((end->x = init_posx(move->nbr_ant, *move, param, -1)) == NULL)
    return (-1);
  if ((end->y = init_posy(move->nbr_ant, *move, param, -1)) == NULL)
    return (-1);
  if ((move->vect.x
       = calc_vect(move->pos_act, *end, move->nbr_ant, 1)) == NULL)
    return (-1);
  if ((move->vect.y
       = calc_vect(move->pos_act, *end, move->nbr_ant, -1)) == NULL)
    return (-1);
  return (0);
}
