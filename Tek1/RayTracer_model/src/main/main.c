/*
** main.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:29:41 2013 vincent colliot
** Last update Sun Jun  9 22:41:44 2013 quentin cloarec
*/

#include <pthread.h>
#include <X11/X.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <strings.h>
#include <mlx.h>
#include "display.h"
#include "token.h"
#include "screen.h"
#include "lerror.h"
#include "select.h"

int		nfn(t_screen *screen)
{
  IMG_PUT(screen->mlx_ptr, screen->win_ptr,
	  ((t_image*)(screen->screensave))->img_ptr, 0, 0);
  return (0);
}

void		mlx_hook_init(t_screen *screen, CLASS_DISPLAY *d,
			      t_select *select)
{
  bzero(select, sizeof(*select));
  select->d = d;
  select->screen = screen;
  mlx_do_key_autorepeatoff(screen->mlx_ptr);
  mlx_expose_hook(screen->win_ptr, nfn, screen);
  mlx_mouse_hook(screen->win_ptr, get, select);
  mlx_hook(screen->win_ptr, KeyPress, KeyPressMask, &keypress, select);
  mlx_key_hook(screen->win_ptr, keyrelease, select);
  mlx_loop_hook(screen->mlx_ptr, &__stay_alert, select);
}

void	*loop_call(void *screen)
{
  mlx_loop(((t_screen*)screen)->mlx_ptr);
  return (NULL);
}

static void	ini_loop(t_screen *screen, CLASS_DISPLAY *d, t_select *select)
{
  pthread_t     thread;

  mlx_hook_init(screen, d, select);
  select->fixed = TRUE;
  select->type = VSELECT;
  pthread_create(&thread, NULL, loop_call, screen);
  pthread_join(thread, NULL);
  mlx_do_key_autorepeaton(screen->mlx_ptr);
  select->exit = TRUE;
  mlx_flush_event(screen->mlx_ptr);
}

int	main(int ac, char **av)
{
  t_select	select;
  t_screen	screen;
  CLASS_DISPLAY	d;

  if ((screen.mlx_ptr = mlx_init()) == NULL)
    lerror(USAGE);
  xml_scan(&d, ac, av);
  if (!d.eye)
    lerror(USAGE);
  screen_it(&screen, "-----> Raytracer <-----",
            SCREEN_SIZE_X, SCREEN_SIZE_Y);
  img_init(screen.screensave, &screen);
  srandom(time(0) * getpid());
  preload_img(&screen, &d);
  IMG_PUT(screen.mlx_ptr, screen.win_ptr,
	  ((t_image*)(screen.screensave))->img_ptr, 0, 0);
  ini_loop(&screen, &d, &select);
  return (0);
}
