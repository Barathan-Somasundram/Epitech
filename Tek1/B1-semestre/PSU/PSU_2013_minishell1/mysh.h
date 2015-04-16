/*
** mysh.h for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 24 20:37:30 2013 a
** Last update Mon Jan  6 19:23:41 2014 a
*/

#ifndef MYSH_H_
# define MYSH_H_

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "my_lib/includes/my_lib.h"

# define BUF_LEN 4096

char	**my_str_to_wordtab(char *str, char s);
char	**my_strcpy_env(char **new_env, char **env, int size);
void	garbage(char **command, char **path, char *buffer);
void	free_env(char **env);
int	my_built_ins(char **command, char ***env, char **path, char *buffer);
int	read_cmd(char **command, char **path, char ***env);
int	minishell1(char **env);
int	my_strncmp(char *s1, char *s2, int n);
int	my_cd(char **command, char **env);
int	my_env(char **env);
int	my_exit(char **command, char **env, char **path, char *buffer);
int	my_setenv(char **command, char ***env_sys);
int	my_unsetenv(char **command, char ***env_sys);
int	execute_cmd(char **command, char **env, char **env_path);
int	path_pos(char **env);
void	my_signal(void);
int	my_home(char **env);
int	my_oldpwd(char **env);

#endif /* !MYSH_H_ */
