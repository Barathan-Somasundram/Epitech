/*
** print_player.c for  in /home/somasu_b/rendu/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar  8 16:58:56 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 16:58:57 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include "lemipc.h"

void		putpixel(SDL_Surface *screen, int x, int y, Uint32 pixel)
{
  int		pix;
  Uint8		*p;

  pix = screen->format->BytesPerPixel;
  p = (Uint8*)screen->pixels + y * screen->pitch + x * pix;
  *(Uint32 *)p = pixel;
}

int		print_line_hor(SDL_Surface *screen, int y)
{
  int		tmp;

  tmp = 50;
  while (tmp < WINY - 50)
    putpixel(screen, tmp++, y, SDL_MapRGB(screen->format, 255, 255, 255));
  return (1);
}

int		print_line_vert(SDL_Surface *screen, int x)
{
  int		tmp;

  tmp = 50;
  while (tmp < WINX - 50)
    putpixel(screen, x, tmp++, SDL_MapRGB(screen->format, 255, 255, 255));
  return (1);
}

int		print_player(SDL_Surface *screen, int pos, int id,  Uint32 tab[9])
{
  SDL_Rect rect;

  rect.x = POSX(pos) * ((WINX - 100) / MAPX) + 51;
  rect.y = POSY(pos) * ((WINY - 100) / MAPY) + 51;
  rect.w = (WINX - 100) / MAPX - 2;
  rect.h = (WINY - 100) / MAPY - 2;
  if (id != '.' && id > '0')
    {
      if (id == '1' || id == '2')
	SDL_FillRect(screen, &rect, tab[(id - '0') - 1]);
    }
  else
    	SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 0, 0, 0));
  return (1);
}

