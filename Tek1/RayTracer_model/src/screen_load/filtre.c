/*
** filtre.c for  in /home/lecorr_b//projets/RT/Ray-Tracer/Rt/src/screen_load
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue Jun  4 15:35:59 2013 thomas lecorre
** Last update Sun Jun  9 22:19:30 2013 quentin cloarec
*/

#include "filtre.h"
#include "u_color.h"

void	blue(t_color *pix)
{
  (pix->rgb)[B] += 80;
}

void	green(t_color *pix)
{
  (pix->rgb)[G] += 80;
}


void	negatif(t_color *pix)
{
  (pix->rgb)[R] = 255 - (pix->rgb)[R];
  (pix->rgb)[G] = 255 - (pix->rgb)[G];
  (pix->rgb)[B] = 255 - (pix->rgb)[B];
}

void	black_white(t_color *pix)
{
  float	stock;

  stock = 0.0;
  stock += (pix->rgb)[R];
  stock += (pix->rgb)[G];
  stock += (pix->rgb)[B];
  if ((stock / 3) > 60.0)
    {
      (pix->rgb)[R] = 255;
      (pix->rgb)[G] = 255;
      (pix->rgb)[B] = 255;
    }
  else
    {
      (pix->rgb)[R] = 0;
      (pix->rgb)[G] = 0;
      (pix->rgb)[B] = 0;
    }
}

t_color		filtre(t_color pix, int f)
{
  if (f == 1)
    grey(&pix);
  if (f == 2)
    sepia(&pix);
  if (f == 3)
    negatif(&pix);
  if (f == 4)
    black_white(&pix);
  if (f == 5)
    red(&pix);
  if (f == 6)
    blue(&pix);
  if (f == 7)
    green(&pix);
  return (pix);
}
