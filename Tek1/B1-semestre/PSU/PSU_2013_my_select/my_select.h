/*
** my_select.h for my_select in /home/somasu_b/TEST/select
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Jan 16 10:44:20 2014 somasu_b
** Last update Sun Jan 19 21:26:18 2014 a
*/

#ifndef _MY_SELECT_H_
# define _MY_SELECT_H_

# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <ncurses/curses.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <term.h>
# include <signal.h>

# define UNDERLINE_S	us
# define UNDERLINE_E	ue
# define CURSOR_MOVE	cm
# define CURSOR_INVI	vi
# define CURSOR_VISI	ve
# define MODE_REVERS	mr
# define MODE_END	me
# define CLEAR		cl

# define ESCAPE		27
# define UP		4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define DEL		2117294875
# define BACKSPACE	127
# define SPACE		32
# define ENTER		10

typedef struct termios t_term;
typedef struct winsize t_wins;
typedef struct	s_list
{
  char		*item;
  bool		cursor;
  bool		inverse;
  struct s_list	*previous;
  struct s_list	*next;
}		t_list;

t_list	*g_list;

void	key_delete();
void	select_item();
void	my_fd_putchar(char c, int fd);
void	my_tty_str(char *str);
void	my_putstr(char *str);
void	my_signal();
char	*my_get_term(char **env);
int	init_list(int ac, char **av);
int	my_take_keys(int length);
int	my_aff(t_wins *winsize, int length);
int	my_cursor_up();
int	my_cursor_down();
int	key_validate();
int	my_clear_full_screen();
int	tputchar(int c);
int	my_strlen(char *str);
int	my_long_strlen();

#endif /* !MY_SELECT_H_ */
