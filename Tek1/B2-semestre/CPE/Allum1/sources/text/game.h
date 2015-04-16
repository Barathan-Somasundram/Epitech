/*
** game.h for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Feb  3 11:45:32 2014 somasu_b
** Last update Fri Feb  7 15:52:15 2014 somasu_b
*/

#ifndef _GAME_H_
# define _GAME_H_

/*
** INCLUDES
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ncurses/curses.h>
# include <term.h>
# include "../../includes/my_colors.h"

/*
** DEFINES
*/
# define BUF_LEN	4096

# define ESCAPE		27
# define UP		4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define SELECT		32
# define ENTER		10

/*
** STRUCTURES
*/

typedef struct	termios t_term;

typedef struct	s_line
{
  char		*match;
  bool		cursor;
  bool		select;
  struct s_line	*prev;
  struct s_line	*next;
}		t_line;

typedef struct	s_alum
{
  int		size;
  bool		cursor;
  struct s_line	*line;
  struct s_alum	*prev;
  struct s_alum	*next;
}		t_alum;

typedef struct	s_menu
{
  char		*submenu;
  int		nb_alum;
  bool		mode;
  bool		cursor;
  struct s_menu	*prev;
  struct s_menu	*next;
}		t_menu;

typedef struct	s_put
{
  char		*clear;
  char		*cursor_visi;
  char		*cursor_invi;
  char		*underline_s;
  char		*underline_e;
  char		*reverse_s;
  char		*reverse_e;
}		t_put;

typedef struct	s_game
{
  t_menu	*menu;
  t_alum	*alum;
  t_term	backup;
  t_term	gameone;
}		t_game;

/*
** GLOBALS
*/

/*
** PROTOTYPES
*/

int	my_putchar(int c);

#endif /* !_GAME_H_ */
