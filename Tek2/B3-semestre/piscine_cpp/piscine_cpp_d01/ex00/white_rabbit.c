/*
** white_rabbit.c for white_rabbit in /home/somasu_b/rendu
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Wed Jan  7 10:17:10 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 09:59:05 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <stdio.h>

int	follow_the_white_rabbit(void)
{
  int	dice_nb;
  int	dice_sum;

  dice_sum = 0;
  dice_nb = 0;
  while (42)
    {
      dice_nb = (random() % 37) + 1;
      dice_sum = dice_sum + dice_nb;
      if ( dice_nb == 37 || dice_nb == 1)
	{
	  printf("LAPIN !!!\n");
	  return (dice_sum);
	}	
      if (dice_nb == 15 || dice_nb == 23 || dice_nb == 10)
	printf("devant\n");
      else if (dice_nb == 4 || dice_nb == 5 || dice_nb == 6 || dice_nb == 28
	       || (dice_nb >= 17 && dice_nb <= 21))
	printf("gauche\n");
      else if (dice_nb == 13 || (dice_nb >= 34 && dice_nb < 37)
	printf("droite\n");
      else if (dice_nb % 8 == 0 || dice_nb == 26)
	printf("derriere\n");
      if (dice_sum == 421 || dice_sum >= 397 || dice_nb == 37 || dice_nb == 1)
	{
	  printf("LAPIN !!!\n");
	  return (dice_sum);
	}
    }
  return (dice_sum);
}
