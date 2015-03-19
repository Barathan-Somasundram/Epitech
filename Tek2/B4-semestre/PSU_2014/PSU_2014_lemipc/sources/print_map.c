/*
** print_map.c for  in /home/somasu_b/rendu/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar  8 16:59:00 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 16:59:01 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include "lemipc.h"

SDL_Surface	*init_screen()
{
  SDL_Surface *screen;

  if ( SDL_Init(SDL_INIT_VIDEO) == -1 )
    {
      printf("Can't init SDL:  %s\n", SDL_GetError());
      return (NULL);
    }
  screen = SDL_SetVideoMode(WINX, WINY, 16, SDL_HWSURFACE);
  if (!screen)
    {
      printf("Can't set video mode: %s\n", SDL_GetError( ) );
      return (NULL);
    }
  return (screen);
}

void		init_color(SDL_Surface *screen, Uint32 tab_color[9])
{
  tab_color[0] = SDL_MapRGB(screen->format, 255, 0, 0);
  tab_color[1] = SDL_MapRGB(screen->format, 0, 255, 0);
  tab_color[2] = SDL_MapRGB(screen->format, 0, 0, 255);
  tab_color[3] = SDL_MapRGB(screen->format, 255, 255, 0);
  tab_color[4] = SDL_MapRGB(screen->format, 255, 0, 255);
  tab_color[5] = SDL_MapRGB(screen->format, 0, 255, 255);
  tab_color[6] = SDL_MapRGB(screen->format, 254, 220, 0);
  tab_color[7] = SDL_MapRGB(screen->format, 124, 0, 255);
  tab_color[8] = SDL_MapRGB(screen->format, 255, 124, 0);
}

void		*print_map(void *param)
{
  SDL_Surface	*screen;
  int		i;
  Uint32	tab_color[9];

  if ((screen = (SDL_Surface *)param) == NULL)
    return (NULL);
  init_color(screen, tab_color);
  while (42)
    {
      i = 0;
      while (i <= MAPY)
	print_line_hor(screen, i++ * ((WINY - 100) / MAPY) + 50);
      i = 0;
      while (i <= MAPX)
	print_line_vert(screen, i++ * ((WINX - 100) / MAPX) + 50);
      i = -1;
      while (++i < MAPX * MAPY)
	print_player(screen, i, g_map[i], tab_color);
      SDL_Flip(screen);
    }
  return (param);
}
