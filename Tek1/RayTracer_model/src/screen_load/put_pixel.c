/*
** put_pixel.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:49:00 2013 vincent colliot
** Last update Sun Jun  9 05:47:04 2013 vincent colliot
** Last update Tue Jun  4 21:08:44 2013 thomas lecorre
*/

#include "filtre.h"
#include "screen.h"

static unsigned int add_color(unsigned int get, unsigned int rgb)
{
  t_color getr;
  t_color rgbr;
  t_color ret;

  if (!get)
    return (rgb);
  getr.i = get;
  rgbr.i = rgb;
  (ret.rgb)[R] = (getr.rgb)[R] / 2.0 + (rgbr.rgb)[R] / 2.0;
  (ret.rgb)[B] = (getr.rgb)[B] / 2.0 + (rgbr.rgb)[B] / 2.0;
  (ret.rgb)[G] = (getr.rgb)[G] / 2.0 + (rgbr.rgb)[G] / 2.0;
  return (ret.i);
}

static inline void            save(t_image *screen, int x, int y, unsigned int rgb)
{
  size_t           pos;

  pos = (x) * (screen->bpp / 8) + (y) * screen->size_line;
  rgb = add_color(*(unsigned int*)(screen->stack
				   + pos * sizeof(unsigned char)), rgb);
  *(unsigned int*)(screen->stack + pos * sizeof(unsigned char)) = rgb;
}

/*
 * ¤¤¤¤
 *pour l'aliasing penser a faire une boucle de remplissage...
 * ¤¤¤¤
*/

void            pix_it(t_screen *screen, t_2d pix, t_color color, int f)
{
  color = filtre(color, f);
  save(screen->screensave, (int)pix.x, (int)pix.y,
       mlx_get_color_value(screen->mlx_ptr, color.i));
}

static t_color	get_save(t_image *screen, int x, int y)
{
  t_color	color;
  size_t	pos;

  pos = (x) * (screen->bpp / 8) + (y) * screen->size_line;
  color.i =
    *(unsigned int*)(screen->stack + pos * sizeof(unsigned char));
  return (color);
}

t_color		get_pix(t_screen *screen, t_2i pix, t_color *color)
{
  t_color	get;

  get = get_save(screen->screensave, pix.x, pix.y);
  if (color)
    *color = get;
  return (get);
}
