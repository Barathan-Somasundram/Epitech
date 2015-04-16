/*
** screen.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:15:45 2013 vincent colliot
** Last update Mon Jun  3 00:06:04 2013 vincent colliot
*/

#include <mlx.h>
#include <stdlib.h>
#include "screen.h"

void screen_it(t_screen *screen, char *title, int x, int y)
{
  t_image *screensaver;

  screen->x = x;
  screen->y = y;
  screen->win_ptr = mlx_new_window(screen->mlx_ptr, screen->x, screen->y, title);
  screensaver = malloc(sizeof(*screensaver));
  screensaver->height = y;
  screensaver->width = x;
  screen->screensave = screensaver;
}
