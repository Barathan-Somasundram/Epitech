/*
** filtre2.c for filtre2.c in /home/cloare_q//Ray-Tracer/Rt/src/screen_load
** 
** Made by quentin cloarec
** Login   <cloare_q@epitech.net>
** 
** Started on  Sun Jun  9 22:15:17 2013 quentin cloarec
** Last update Sun Jun  9 22:18:53 2013 quentin cloarec
*/

#include "u_color.h"
#include "filtre.h"

void    grey(t_color *pix)
{
  float stock;

  stock = 0.0;
  stock += (pix->rgb)[R];
  stock += (pix->rgb)[G];
  stock += (pix->rgb)[B];
  (pix->rgb)[R] = stock / 3;
  (pix->rgb)[G] = stock / 3;
  (pix->rgb)[B] = stock / 3;
}

void    sepia(t_color *pix)
{
  (pix->rgb)[R] += 80;
  (pix->rgb)[G] += 80;
}

void    red(t_color *pix)
{
  (pix->rgb)[R] += 80;
}
