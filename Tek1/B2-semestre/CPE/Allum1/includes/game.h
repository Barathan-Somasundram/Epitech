/*
** game.h for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Feb  3 11:45:32 2014 somasu_b
** Last update Sun Feb 16 21:41:19 2014 somasu_b
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
# include "my_colors.h"

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

/*
** PROTOTYPES
*/

int	my_putchar(int c);
void	my_putstr(char *str);
int	my_clear_full_screen(void);
char	*my_get_term(char **env);
int	my_strncmp(char *s1, char *s2, int n);
int	select_out(t_alum **alum);
int	move_up(t_alum **alum);
int	move_down(t_alum **alum);
int	move_left(t_alum **alum);
int	move_right(t_alum **alum);
int	select_it(t_alum **alum);
int	valide_it(t_alum **alum);
int	ia(t_alum **alum);
int	player(t_alum **alum, int line);
int	init_alum(t_alum **alum, int line);
int	init_term(t_term *backup, t_term *gameone, char **env);
void	guide(void);
void	my_show(t_alum **alum, int line);
int	strlen_alum(t_alum **alum);
int	int_tab(int len, t_alum **alum, int **sizes);
int	my_xor(int len, int *sizes);

#endif /* !_GAME_H_ */
