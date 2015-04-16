/*
** mysh.h for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 14:52:52 2014 somasu_b
** Last update Sun Mar  9 21:43:37 2014 somasu_b
*/

#ifndef _MYSH_H_
# define _MYSH_H_

# include "my_colors.h"
# include "built_in.h"

# define BUF_LEN	4096

typedef struct	s_list
{
  char		*var;
  struct s_list	*next;
}		t_list;

typedef struct	s_term
{
  int		counter;
  t_list	*my_env;
}		t_term;

t_term	g_mysh;

void	my_putnbr(int nb);
void	my_prompt(void);
void	my_signal(void);
int	minishell(void);
int	my_put_in_list(t_list **env, char *vars);
char	**my_get_path(void);
char	*cmd_full_path(char **cmd);
int	my_exec_cmd(char **cmd, int mod);
int	my_env_tab(char ***env);
char	*my_get_env(char *elem);
char	*cmd_full_path(char **cmd);
char	*my_get_hostname(void);
char	*my_get_name(void);
char	*my_get_pwd(void);

#endif /* !MYSH_H_ */
