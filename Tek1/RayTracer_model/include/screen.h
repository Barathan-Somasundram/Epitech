/*
** screen.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:13:19 2013 vincent colliot
** Last update Sun Jun  9 05:45:52 2013 vincent colliot
*/

#ifndef SCREEN_H_
# define SCREEN_H_

# include <mlx.h>
# include <stdlib.h>
# include "u_color.h"
# include "dim.h"

/*____________ SCREEN ____________*/
typedef struct          s_screen
{
  int           x;
  int           y;
  void          *mlx_ptr;
  void          *win_ptr;
  void          *screensave;
}                       t_screen;


/*_____________ IMAGE _____________*/
typedef struct          s_image
{
  int           height;
  int           width;
  int           size_line;
  int           bpp;
  int           big_E;
  void          *img_ptr;
  t_screen      *window;
  char          *stack;
}                       t_image;

	/* init */
void	screen_it(t_screen *, char *, int, int);
void    img_init(t_image*, t_screen*);
	/* put a pixel */
void    pix_it(t_screen *, t_2d, t_color, int);
	/* ray-tracing calc */
# include "ray-tracing.h"

	/*screen define*/
# define SCREEN_SIZE_X 1920
# define SCREEN_SIZE_Y 1080

# define IMG_PUT(mlx,win,img,x,y) mlx_put_image_to_window(mlx,win,img,x,y)

#endif
