/*
** sh.h for 42sh in /home/somasu_b/Music/PSU_2013_42sh/PSU_2013_42sh
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Jun  1 17:12:46 2014 somasu_b
** Last update Sun Jun  1 22:28:38 2014 a
*/

#ifndef SH_H_
# define SH_H_

# include "my_colors.h"
# include "termios.h"

/*
** utility
*/
# define BUF_LEN	4096
# define PATH_LENGTH	1024

/*
** Keycodes from termcaps
*/
# define UP		4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define DEL		2117294875
# define BK_SPACE	127
# define ESCAPE		27
# define CTRL_A		1
# define CTRL_B		2
# define CTRL_D		4
# define CTRL_K		11
# define CTRL_U		21
# define CTRL_W		23
# define CLEAR		12
# define BEGIN		4738843
# define END		4607771
# define TAB		'\t'

/*
** command seperator
*/
# define REDIR_RIGHT1	">"
# define REDIR_RIGHT2	">>"
# define REDIR_LEFT1	"<"
# define REDIR_LEFT2	"<<"
# define PIPE		"|"
# define AND		"&&"
# define OR		"||"
# define SEP		";"
# define BG		"&"

# define TYPE_RIGHT1	1
# define TYPE_RIGHT2	2
# define TYPE_LEFT1	3
# define TYPE_LEFT2	4
# define TYPE_PIPE	5
# define TYPE_AND	6
# define TYPE_OR	7
# define TYPE_SEP	8
# define TYPE_BG	9

# define TYPE_CMD	10
# define TYPE_ARG	11

/*
** typedef and structures
** for parsing
*/
typedef struct	s_cmd	t_cmd;

typedef struct	s_line
{
  int		pos;
  int		len;
  char		*cmd;
}		t_line;

typedef struct	s_type
{
  char		*sep;
  int		type;
}		t_type;

typedef struct	s_tok
{
  char		*cmd;
  int		type;
  struct s_tok	*prev;
  struct s_tok	*next;
}		t_tok;

typedef struct	s_tree
{
  int		type;
  t_cmd		*cmd;
}		t_tree;

struct		s_cmd
{
  t_tok		*token;
  t_tree	*tree;
  t_cmd		*prev;
  t_cmd		*next;
};

/*
** typedef and structures
** for exec and stock
*/
typedef struct	s_42	t_42;

typedef struct	s_in
{
  char		*command;
  int		(*fct)(t_42*, t_tok*);
}		t_built;

typedef struct	termios	t_term;

typedef struct	s_env
{
  char		*var;
  char		*contents;
  struct s_env	*prev;
  struct s_env	*next;
}		t_env;

typedef struct	s_vars
{
  char		*var;
  char		*contents;
  struct s_vars	*prev;
  struct s_vars	*next;
}		t_vars;

typedef struct	s_hist
{
  char		*command;
  int		position;
  int		number;
  struct s_hist	*prev;
  struct s_hist	*next;
}		t_hist;

typedef struct	s_alia
{
  char		*var;
  char		*contents;
  struct s_alia	*prev;
  struct s_alia	*next;
}		t_alias;

struct	s_42
{
  int		is_term;
  t_term	backup;
  t_term	sh_term;

  char		*clrscreen;
  char		*rvmod;
  char		*disabl;
  char		*clrline;
  char		*save;
  char		*restore;
  char		*alocrs;
  char		*stlcrs;
  int		fd_tty;

  int		fds[2];
  int		end_pipe;

  t_env		*env;
  t_vars	*vars;
  t_hist	*history;
  t_alias	*alias;

  unsigned int	counter;
  int		exit;
  int		quit;
};

typedef struct	s_keys
{
  int		keycode;
  int		(*fct)(t_42 *, t_line *, int);
}		t_keys;

int		sh_init(char**, t_42*);
int		sh_env(char**, t_42*);
int		sh_prompt(t_42*);

char		*get_next_line(const int);
char		*epur_command(char*);
char		*my_get_cmd(t_42*);
void		my_aff_stringcursor(t_42 *, t_line *);
int		tputswrite(const int);
char		*gnl_termcaps(t_42 *);

int		gere_backspace(t_42 *, t_line *, int);
int		gere_del(t_42 *, t_line *, int);
int		gere_clear(t_42 *, t_line *, int);
int		gere_history(t_42 *, t_line *, int);
int		gere_killword(t_42 *, t_line *, int);
int		gere_movecursor(t_42 *, t_line *, int);
int		gere_cleanaftercursor(t_42 *, t_line *, int);
int		gere_clearline(t_42 *, t_line *, int);

char		*alias_in(char *, t_alias*);
int		command_center(t_42*, char*);
t_tok		*cmd_to_list(char*);
int		lexer(t_tok*);
int		parse_token(t_tree**, t_tok*, int);
int		init_tree(t_tree**, int);
int		add_elem(t_tree**, t_tok*);
int		epur_token(t_cmd*, t_tok*, int);
int		epur_tree(t_tree*);
t_tree		*parser(t_tok*);
void		free_tree(t_tree*);
void		free_token(t_tok*);

char		*my_getpwd(void);
char		*my_getvar(t_42*, char*);
int		change_env(t_42*, char*, char*);

int		my_history(t_42*, t_tok*);
int		sh_alias(t_42*, t_tok*);
int		sh_unalias(t_42*, t_tok*);
int		my_env(t_42*, t_tok*);
int		sh_setenv(t_42*, t_tok*);
int		sh_unsetenv(t_42*, t_tok*);
int		sh_echo(t_42*, t_tok*);
int		my_getnbr(char*);
int		sh_exit(t_42*, t_tok*);
int		sh_cd(t_42*, t_tok*);
int		sh_set_vars(t_42*, t_tok*);
int		sh_unset_vars(t_42*, t_tok*);

int		background(t_42*, t_tok*);
int		cmd_execution(t_42*, t_tok*);
int		sh_pipe(t_tree*, t_cmd*, t_42*);
int		and_or_pipe(t_42*, t_tree*, t_cmd*);
int		sh_left2(t_42*, char*);
int		redirection(t_42*, t_tok*);
char		*sh_search_path(t_42*, char*);
int		execve_main(t_tok*, t_42*);
int		main_execution(t_42*, t_tree*);
char		**my_str_to_wordtab(char*, char);
char		**env_to_tab(t_env*);
char		**tok_to_tab(t_tok*);

#endif	/* !SH_H_ */
